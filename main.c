#include "libavr.h"
#include "libshift.h"

shift_register_t shift = { 
    .portConfig = &DDRD,
    .port = &PORTD,
    .use_strobe = 0,
    .clock = PD1,
    .data = PD0,
    .size = 8
};

int main(void) {
    setPinMode(&DDRC, PC5, OUTPUT);
    setPinMode(&DDRB, PB0, OUTPUT);
    setPin(&PORTC, PC5, HIGH);
    // setPin(&PORTB, PB0, HIGH);
    sr_setup(&shift);
    sr_clear(&shift);
    setPin(&PORTB, PB0, HIGH);
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
        // sr_set(&shift, 0x55);
        // delay(500);
        // sr_shift(&shift);
        // sr_set(&shift, 0xAA);
        // delay(500);
        /* setPin(&PORTB, PB0, HIGH);
        setPin(&PORTC, PC5, LOW);
        delay(blinkInterval);

        setPin(&PORTB, PB0, LOW);
        setPin(&PORTC, PC5, HIGH);
        delay(blinkInterval); */
        // setPin(&PORTC, PC5, digitalRead(&PINC, PC4));
    }
    return 0;
}

