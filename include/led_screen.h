#include <led_matrix.h>

#ifndef __led_screen_h_included__
#define __led_screen_h_included__

#define screen_matrix_for_coords(s, x, y) (s)->matrices[((s)->width * ((y) / 4)) + ((x) / 4)]
#define screen_inner_matrix_pos(x, y) (1 << ((((y) % 4) * 4) + ((x) % 4)))

typedef struct {
    ledm_t** matrices;
    uint8_t width;
    uint8_t height;
} screen_t;

void screen_clear_all(screen_t* s) {
    for (uint8_t i = 0; i < s->width * s->height; i++) {
        ledm_clear(s->matrices[i]);
    }
}

void screen_set(screen_t* s, uint8_t x, uint8_t y) {
    ledm_t* matrix = screen_matrix_for_coords(s, x, y);
    ledm_set(matrix, matrix->current_state | screen_inner_matrix_pos(x, y));
}

void screen_clear(screen_t* s, uint8_t x, uint8_t y) {
    ledm_t* matrix = screen_matrix_for_coords(s, x, y);
    ledm_set(matrix, matrix->current_state & ~screen_inner_matrix_pos(x, y));
}

void screen_clear_row(screen_t *s, uint8_t y) {
    for (uint8_t x = 0; x < s->width; x++) {
        screen_clear(s, x, y);
    }
}

void screen_enable_dry_mode(screen_t *s) {
    for (uint8_t i = 0; i < s->width * s->height; i++) {
        ledm_enable_dry_mode(s->matrices[i]);
    }
}

void screen_disable_dry_mode(screen_t *s) {
    for (uint8_t i = 0; i < s->width * s->height; i++) {
        ledm_disable_dry_mode(s->matrices[i]);
    }
}

uint8_t screen_is_set(screen_t* s, uint8_t x, uint8_t y) {
    if (x >= (s->width * 4)) {
        return 1;
    }
    if (y >= (s->height * 4)) {
        return 1;
    }

    ledm_t* matrix = screen_matrix_for_coords(s, x, y);
    return (matrix->current_state & screen_inner_matrix_pos(x, y)) != 0;
}

void screen_init(screen_t* s) {
    for (uint8_t i = 0; i < s->width * s->height; i++) {
        sr_setup(s->matrices[i]->shift1);
        sr_setup(s->matrices[i]->shift2);
    }
    screen_clear_all(s);
}

#endif // not __led_screen_h_included__