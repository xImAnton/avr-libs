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

#ifdef RANDOM_USE_DEFAULT

#ifndef RANDOM_DEFAULT_ADC_CHANNEL
#define RANDOM_DEFAULT_ADC_CHANNEL 0
#endif

rand_state_t RAND_STATE = {};

#define srand_adc() rand_seed_adc(&RAND_STATE, RANDOM_DEFAULT_ADC_CHANNEL)
#define rand() rand_xorshift32(&RAND_STATE)

#endif // RANDOM_USE_DEFAULT

#endif // not __random_h_included__
