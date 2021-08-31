#include "libavr.h"
#include "libshift.h"

shift_register_t shift = { 
    .ddr = &DDRC,
    .port = &PORTC,
    .use_strobe = 0,
    .clock = PC0,
    .data = PC1,
    .size = 8
};

volatile uint8_t state = PIN_LOW;

ISR(INT0_vect) {
    state = !state;
    pin_set(&PORTC, PC5, state);
}

int main(void) {
    pin_set_mode(&DDRC, PC5, PIN_OUTPUT);
    i_setup(INT0, I_INT0_RISING);
    sei();

    sr_setup(&shift);
    sr_clear(&shift);
    uint8_t state = 0x07;
    while (1) {
        if (state == 7) {
            sr_set(&shift, 0x01);
            state = 0x00;
        } else {
            sr_shift(&shift);
            state++;
        }
        delay(300);
    }
    return 0;
}

