#include <libavr.h>
#include <libshift.h>
#include "led_matrix.h"

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
    .shift2 = &s2
};

ledm_t matrix2 = {
    .shift1 = &s3,
    .shift2 = &s4
};

ledm_t* matrices[] = {&matrix2, &matrix1};

ledm_letter_t ximantonde[] = {LEDM_X, LEDM_I, LEDM_M, LEDM_A, LEDM_N, LEDM_T, LEDM_O, LEDM_N, LEDM_DOT, LEDM_D, LEDM_E, LEDM_SPACE};

int main(void) {
    sr_setup(&s1);
    sr_clear(&s1);
    sr_setup(&s2);
    sr_clear(&s2);
    sr_setup(&s3);
    sr_clear(&s3);
    sr_setup(&s4);
    sr_clear(&s4);

    while (1) {
        ledm_show_word_rotating(matrices, sizeof(matrices) / sizeof(ledm_t*), ledm_word(ximantonde), 250, LEDM_LEFT, 1);
    }

    return 0;
}
