#include <libavr.h>
#include <libshift.h>

shift_register_t shift = { 
    .ddr = &DDRC,
    .port = &PORTC,
    .use_strobe = 0,
    .clock = PC0,
    .data = PC1,
    .size = 8
};

volatile uint8_t toggle_state = PIN_LOW;

ISR(INT0_vect) {
    toggle_state = !toggle_state;
    pin_set(&PORTC, PC5, toggle_state);
    pin_set(&PORTB, PB0, !toggle_state);
}

int main(void) {
    pin_set_mode(&DDRC, PC5, PIN_OUTPUT);
    pin_set_mode(&DDRB, PB0, PIN_OUTPUT);
    pin_set(&PORTB, PB0, PIN_HIGH);
    i_setup(INT0, I_INT0_RISING);
    sei();

    sr_setup(&shift);
    sr_clear(&shift);
    uint8_t state = 0x07;
    while (1) {
        if (state >= 7) {
            sr_set(&shift, 0x01);
            state = 0x00;
        } else {
            sr_shift(&shift);
            state++;
        }
        if (toggle_state) {
            delay(300)
        } else {
            delay(30)
        }
    }
}

