#define LEDM_ENABLE_NUMBER

#include <libavr.h>
#include <libshift.h>
#include <led_matrix.h>
#include <led_screen.h>
#include "tetris.h"
#include <random.h>

#define arr(s, t) s, sizeof(s) / sizeof(t)

// button event types + state flags
#define BTN_DOWN  0
#define BTN_LEFT  1
#define BTN_UP    2
#define BTN_RIGHT 3

#define TICK_SPEED 30

#include "matrix_pins.h"

ledm_t* matrices[] = {&ol, &or, &ml, &mr, &ul, &ur};

screen_t screen = {
    .matrices = matrices, 
    .height = 3,
    .width = 2,
};

// keep track of current dot position
uint8_t x_pos = 4;
uint8_t y_pos = 0;

// message shown on loose
ledm_letter_t leiderverlorenlool[] = {LEDM_L, LEDM_E, LEDM_I, LEDM_D, LEDM_E, LEDM_R, LEDM_SPACE, LEDM_V, LEDM_E, LEDM_R, LEDM_L, LEDM_O, LEDM_R, LEDM_E, LEDM_N, LEDM_COMMA, LEDM_SPACE, LEDM_L, LEDM_O, LEDM_O, LEDM_L, LEDM_SPACE}; // LEIDER VERLOREN, LOOL 

// register for pressed buttons to detect presses / releases
uint8_t button_states = 0;

// times, the timer ISR was executed
volatile uint32_t time = 0;

// buffer for button press events
volatile uint8_t evt_bfr[256] = {0};
volatile uint8_t evt_read_ptr = 0;
volatile uint8_t evt_write_ptr = 0;

// execute every 1024 clock cycles
ISR( TIMER0_OVF_vect ) {
    time++;
    uint8_t new_states = (pin_read_bit(PINB, PB0) << BTN_RIGHT) | \
                         (pin_read_bit(PINA, PA1) << BTN_UP)    | \
                         (pin_read_bit(PINB, PB2) << BTN_LEFT)  | \
                          pin_read_bit(PINB, PB1) << BTN_DOWN;

    if (new_states != button_states) {
        if ((new_states & (1 << BTN_RIGHT)) && !(button_states & (1 << BTN_RIGHT))) {
            evt_bfr[evt_write_ptr++] = BTN_RIGHT;
        }

        if (((new_states & (1 << BTN_UP)) & 1) && !(button_states & (1 << BTN_UP))) {
            evt_bfr[evt_write_ptr++] = BTN_UP;
        }

        if ((new_states & (1 << BTN_LEFT)) && !(button_states & (1 << BTN_LEFT))) {
            evt_bfr[evt_write_ptr++] = BTN_LEFT;
        }

        if ((new_states & (1 << BTN_DOWN)) && !(button_states & (1 << BTN_DOWN))) {
            evt_bfr[evt_write_ptr++] = BTN_DOWN;
        }

        button_states = new_states;
    }
}

// random generator
rand_state_t rand_state;
#define random_column() (rand_xorshift32(&rand_state) & 0b111000) >> 3 // mask by 0b111 to get numbers in range 0..7, is not very reliable

void update_screen() {
    screen_set(&screen, x_pos, y_pos);
}

/**
 * @brief Tries to move to the given position and updates the screen
 * 
 * @param x the x position to move to
 * @param y the y position to move to
 * @return whether the move was successful (1) or not successful because of 
 *         obstruction (0)
 */
uint8_t move(uint8_t x, uint8_t y) {
    if (screen_is_set(&screen, x, y)) return 0;

    screen_clear(&screen, x_pos, y_pos);
    x_pos = x;
    y_pos = y;
    update_screen();

    return 1;
}

void run_game_tick() {

    /*
      Run the tick only, if the timer was called TICK_SPEED-times.
      Otherwise return and execute events.
      Disable interrupts to prevent `time` getting changed during checking or setting
    */
    cli();
    if (time < TICK_SPEED) {
        sei();
        return;
    }
    time -= TICK_SPEED; // subtract to not skip missed ticks
    sei();

    // try to fall down, if successful, return
    if (move(x_pos, y_pos + 1)) return;

    // unsuccessful dot drop in row 1 == loss
    if (y_pos == 1) {
        screen_clear_all(&screen);
        ledm_show_word_rotating(matrices, 2, ledm_word(leiderverlorenlool), 500, LEDM_LEFT, 0);
    }

    // create new dot at the top in a random column
    x_pos = random_column();
    y_pos = 0;

    update_screen();
}

void process_events() {
    while (evt_read_ptr != evt_write_ptr) {
        switch (evt_bfr[evt_read_ptr++]) {
            case BTN_RIGHT: // move to the right
                move(x_pos + 1, y_pos);
                break;
            case BTN_LEFT: // move to the left
                move(x_pos - 1, y_pos);
                break;
            case BTN_UP:
                break;
            case BTN_DOWN: // drop as far as possible instantly
                while (move(x_pos, y_pos + 1));
                break;
            default:
                break;
        }
    }
}

int main(void) {
    // button pins
    pin_set_mode(&DDRB, PB0, PIN_INPUT); // right
    pin_set_mode(&DDRA, PA1, PIN_INPUT); // up
    pin_set_mode(&DDRB, PB2, PIN_INPUT); // left
    pin_set_mode(&DDRB, PB1, PIN_INPUT); // down

    screen_init(&screen);

    // timer F_CPU / 1024
    TCCR0 = (1 << CS02) | (1 << CS00);
    // enable timer overflow interrupt
    TIMSK |= (1 << TOIE0);
    sei();

    // setup adc for prng seed
    pin_set_mode(&DDRA, PA0, PIN_INPUT);
    adc_enable();
    adc_prescale(ADC_PRESC_128);
    rand_seed_adc(&rand_state, 0);

    // initialise and show first dot
    x_pos = random_column();
    update_screen();

    while (1) {
        run_game_tick();
        process_events();
    }

    return 0;
}
