#include "libavr.h"

#ifndef __libshift_h_included__
#define __libshift_h_included__

typedef struct {
    volatile uint8_t *portConfig;
    volatile uint8_t *port;
    uint8_t strobe;
    uint8_t use_strobe;
    uint8_t clock;
    uint8_t data;
    uint8_t size;
} shift_register_t;

void sr_setup(shift_register_t *shift) {
    if (shift->use_strobe) {
        setPinMode(shift->portConfig, shift->strobe, OUTPUT);
    }
    setPinMode(shift->portConfig, shift->clock, OUTPUT);
    setPinMode(shift->portConfig, shift->data, OUTPUT);
}

inline static void sr_shift(shift_register_t *shift) {
    setPin(shift->port, shift->clock, HIGH);
    // delay(1);
    setPin(shift->port, shift->clock, LOW);
}

inline void sr_disable_strobe(shift_register_t *shift) {
    if (shift->use_strobe) {
        setPin(shift->port, shift->strobe, LOW);
    }
}

inline void sr_enable_strobe(shift_register_t *shift) {
    if (shift->use_strobe) {
        setPin(shift->port, shift->strobe, HIGH);
    }
}

void sr_set(shift_register_t *shift, uint8_t value) {
    sr_disable_strobe(shift);
    for (int16_t i = shift->size - 1; i >= 0; --i) {
        setPin(shift->port, shift->data, value & (1 << i));
        sr_shift(shift);
        setPin(shift->port, shift->data, LOW);
    }
    sr_enable_strobe(shift);
}

inline void sr_clear(shift_register_t *shift) {
    sr_set(shift, 0x00);
}

#endif
