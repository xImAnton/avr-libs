#include <libavr.h>

#ifndef __random_h_included__
#define __random_h_included__

typedef struct {
  uint32_t a;
} rand_state_t;

void rand_seed_adc(rand_state_t* state, uint8_t channel) {
    uint32_t out = 0;

    for (uint8_t i = 0; i < 16; i++) {
        out |= ((adc_read(channel) & 0b11) << (i * 2));
    }

    state->a = out;
}

uint32_t rand_xorshift32(rand_state_t* state) {
	/* Algorithm "xor" from p. 4 of Marsaglia, "Xorshift RNGs" */
	uint32_t x = state->a;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return state->a = x;
}

long map(long x, long in_min, long in_max, long out_min, long out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

uint32_t rand_range(rand_state_t* state, uint32_t lower, uint32_t upper) {
    return map(rand_xorshift32(state), 0, 4294967295, lower, upper);
}

#endif // not __random_h_included__
