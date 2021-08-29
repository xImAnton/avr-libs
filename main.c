// #define F_CPU 16000000
#include "libavr.h"

#define BPS 10

int main(void) {
    const uint32_t blinkSpeed = 1000 / BPS;
    setPinMode(&DDRB, PB0, OUTPUT);

    while (1) {
        setPin(&PORTB, PB0, HIGH);
        delay(blinkSpeed);
        setPin(&PORTB, PB0, LOW);
        delay(blinkSpeed);
    }
    return 0;
}

