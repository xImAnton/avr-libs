#include "libavr.h"

#define BPS 2 

const uint32_t blinkInterval = 1000 / 5;

int main(void) {
    setPinMode(&DDRB, PB0, OUTPUT);
	setPinMode(&DDRC, PC5, OUTPUT);

    while (1) {
        setPin(&PORTB, PB0, HIGH);
		setPin(&PORTC, PC5, LOW);
        delay(blinkInterval);

        setPin(&PORTB, PB0, LOW);
		setPin(&PORTC, PC5, HIGH);
        delay(blinkInterval);
    }
    return 0;
}

