#include <../include/libavr.h>
#include <../include/libshift.h>

shift_register_t shift = { 
    .ddr = &DDRC,
    .port = &PORTC,
    .use_strobe = 0,
    .clock = PC0,
    .data = PC1,
    .size = 8
};

volatile int8_t speed = 0;

ISR(INT0_vect) {
    if (speed == 127) {
        pin_set(&PORTB, PB0, PIN_LOW);
    }
    speed -= 1;
}

ISR(INT1_vect) {
    if (speed == 127) {
        pin_set(&PORTB, PB0, PIN_HIGH);
        return;
    }
    speed += 1;
    pin_set(&PORTB, PB0, PIN_LOW);
}    

int main(void) {
    pin_set_mode(&DDRC, PC5, PIN_OUTPUT);
    pin_set_mode(&DDRB, PB0, PIN_OUTPUT);
    i_setup(INT0, I_INT0_RISING);
    i_setup(INT1, I_INT1_RISING);
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
        int16_t to_wait = speed * 10 + 500;
        if (to_wait < 1) {
            pin_set(&PORTB, PB0, PIN_HIGH);
        } else {
            delay(to_wait);
        }
    }
}
