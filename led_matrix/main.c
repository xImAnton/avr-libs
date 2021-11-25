#include <libavr.h>
#include <libshift.h>
#include "led_matrix.h"

#define arr(s, t) s, sizeof(s) / sizeof(t)

shift_register_t s1 = {
    .ddr = &DDRC,
    .port = &PORTC,
    .use_strobe = 0,
    .clock = PC4,
    .data = PC5,
    .size = 8
};

shift_register_t s2 = {
    .ddr = &DDRC,
    .port = &PORTC,
    .use_strobe = 0,
    .clock = PC2,
    .data = PC3,
    .size = 8
};

shift_register_t s3 = {
    .ddr = &DDRD,
    .port = &PORTD,
    .use_strobe = 0,
    .clock = PD6,
    .data = PD7,
    .size = 8
};

shift_register_t s4 = {
    .ddr = &DDRD,
    .port = &PORTD,
    .use_strobe = 0,
    .clock = PD5,
    .data = PD0,
    .size = 8
};

ledm_t matrix1 = {
    .shift1 = &s1,
    .shift2 = &s2,
    .common_cathode = 0
};

ledm_t matrix2 = {
    .shift1 = &s3,
    .shift2 = &s4,
    .common_cathode = 0
};

void init_matrices(ledm_t* matrices[], uint8_t matrix_count) {
    for (uint8_t i = 0; i < matrix_count; i++) {
        sr_setup(matrices[i]->shift1);
        sr_setup(matrices[i]->shift2);
        sr_clear(matrices[i]->shift1);
        sr_clear(matrices[i]->shift2);
    }
}

ledm_t* matrices[] = {&matrix2, &matrix1};
ledm_letter_t ximantonde[] = {LEDM_X, LEDM_I, LEDM_M, LEDM_A, LEDM_N, LEDM_T, LEDM_O, LEDM_N, LEDM_DOT, LEDM_D, LEDM_E, LEDM_SPACE};

int main(void) {
    init_matrices(arr(matrices, ledm_t*));

    while (1) {
        ledm_show_word_rotating(arr(matrices, ledm_t*), ledm_word(ximantonde), 250, LEDM_LEFT, 1);
    }

    return 0;
}
