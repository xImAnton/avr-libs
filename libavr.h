#include <avr/io.h>
#include <util/delay.h>

#define OUTPUT 0x1
#define INPUT 0x0
#define LOW 0x0
#define HIGH 0x1
#define delay _delay_ms

void setPinMode(volatile uint8_t *port, uint8_t pin, uint8_t mode) {
    if (mode) {
        *port |= (1 << pin);
    } else {
        *port &= ~(1 << pin);
    }
}

void setPin(volatile uint8_t *port, uint8_t pin, uint8_t signal) {
    if (signal) {
        *port |= (1 << pin);
    } else {
        *port &= ~(1 << pin);
    }
}
