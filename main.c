#include "libavr.h"
#include "libshift.h"

#define BPS 2 

const uint32_t blinkInterval = 1000 / 5;
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
    while (1) {
		sr_set(&shift, 0x55);
		delay(500);
		sr_shift(&shift);
		// sr_set(&shift, 0xAA);
		delay(500);
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

