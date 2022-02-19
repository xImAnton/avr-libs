#include "libavr.h"

#ifndef __libshift_h_included__
#define __libshift_h_included__

#define SR_SIZE_8 .size = 8,

typedef struct {
    volatile uint8_t *ddr;
    volatile uint8_t *port;
    uint8_t strobe;
    uint8_t use_strobe;
    uint8_t clock;
    uint8_t data;
    uint8_t size;
} shift_register_t;

void sr_setup(shift_register_t *shift) {
    if (shift->use_strobe) {
        pin_set_mode(shift->ddr, shift->strobe, PIN_OUTPUT);
    }
    pin_set_mode(shift->ddr, shift->clock, PIN_OUTPUT);
    pin_set_mode(shift->ddr, shift->data, PIN_OUTPUT);
}

inline static void sr_shift(shift_register_t *shift) {
    pin_set(shift->port, shift->clock, PIN_HIGH);
    // delay(1);
    pin_set(shift->port, shift->clock, PIN_LOW);
}

inline void sr_disable_strobe(shift_register_t *shift) {
    if (shift->use_strobe) {
        pin_set(shift->port, shift->strobe, PIN_LOW);
    }
}

inline void sr_enable_strobe(shift_register_t *shift) {
    if (shift->use_strobe) {
        pin_set(shift->port, shift->strobe, PIN_HIGH);
    }
}

void sr_set(shift_register_t *shift, uint8_t value) {
    sr_disable_strobe(shift);
    for (int16_t i = shift->size - 1; i >= 0; --i) {
        pin_set(shift->port, shift->data, value & (1 << i));
        sr_shift(shift);
        pin_set(shift->port, shift->data, PIN_LOW);
    }
    sr_enable_strobe(shift);
}

inline void sr_clear(shift_register_t *shift) {
    sr_set(shift, 0x00);
}

#endif // not __libshift_h_included__
