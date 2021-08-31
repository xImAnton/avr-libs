#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#ifndef __libavr_h_included__
#define __libavr_h_included__

#define PIN_OUTPUT 0x1
#define PIN_INPUT 0x0
#define PIN_LOW 0x0
#define PIN_HIGH 0x1

#define I_INT0_RISING (1<<ISC01)|(1<<ISC00)
#define I_INT0_FALLING (1<<ISC01)
#define I_INT0_CHANGE (1<<ISC00)
#define I_INT0_LOW 0

#define I_INT1_RISING (1<<ISC11)|(1<<ISC01)
#define I_INT1_FALLING (1<<ISC11)
#define I_INT1_CHANGE (1<<ISC01)
#define I_INT1_LOW 0

#define delay _delay_ms

void pin_set_mode(volatile uint8_t *port, uint8_t pin, uint8_t mode) {
    if (mode) {
        *port |= (1 << pin);
    } else {
        *port &= ~(1 << pin);
    }
}

void pin_set(volatile uint8_t *port, uint8_t pin, uint8_t signal) {
    if (signal) {
        *port |= (1 << pin);
    } else {
        *port &= ~(1 << pin);
    }
}

uint8_t pin_read(volatile uint8_t *portIn, uint8_t port) {
    return *portIn & (1 << port);
}

inline void i_setup(uint8_t interrupt, uint8_t mode) {
    GICR |= ( 1 << interrupt );
    MCUCR |= mode;
}

#endif
