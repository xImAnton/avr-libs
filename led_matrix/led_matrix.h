#include <libshift.h>
#include <string.h>

#ifndef __led_matrix_h_included__
#define __led_matrix_h_included__

#define LEDM_A1 0x1
#define LEDM_A2 0x2
#define LEDM_A3 0x4
#define LEDM_A4 0x8
#define LEDM_B1 0x10
#define LEDM_B2 0x20
#define LEDM_B3 0x40
#define LEDM_B4 0x80
#define LEDM_C1 0x100
#define LEDM_C2 0x200
#define LEDM_C3 0x400
#define LEDM_C4 0x800
#define LEDM_D1 0x1000
#define LEDM_D2 0x2000
#define LEDM_D3 0x4000
#define LEDM_D4 0x8000

#define LEDM_A LEDM_A2 | LEDM_A3 | LEDM_B1 | LEDM_B4 | LEDM_C1 | LEDM_C2 | LEDM_C3 | LEDM_C4 | LEDM_D1 | LEDM_D4
#define LEDM_B LEDM_A1 | LEDM_B1 | LEDM_C1 | LEDM_D1 | LEDM_C3 | LEDM_D2 | LEDM_B2
#define LEDM_C LEDM_B1 | LEDM_C1 | LEDM_D2 | LEDM_D3 | LEDM_A2 | LEDM_A3
#define LEDM_D LEDM_A1 | LEDM_B1 | LEDM_C1 | LEDM_D1 | LEDM_D2 | LEDM_D3 | LEDM_B4 | LEDM_A2 | LEDM_A3 | LEDM_C4
#define LEDM_E LEDM_B1 | LEDM_C1 | LEDM_D2 | LEDM_D3 | LEDM_A2 | LEDM_A3 | LEDM_B3 | LEDM_B2
#define LEDM_F LEDM_B1 | LEDM_C1 | LEDM_A2 | LEDM_A3 | LEDM_D1 | LEDM_A1 | LEDM_C2
#define LEDM_G LEDM_B1 | LEDM_C1 | LEDM_A2 | LEDM_A3 | LEDM_D2 | LEDM_D3 | LEDM_D4 | LEDM_C4 | LEDM_C3
#define LEDM_H LEDM_B1 | LEDM_C1 | LEDM_D4 | LEDM_C4 | LEDM_C3 | LEDM_A4 | LEDM_B4 | LEDM_C2 | LEDM_D1 | LEDM_A1
#define LEDM_I LEDM_A1 | LEDM_B1 | LEDM_C1 | LEDM_D1
#define LEDM_J LEDM_A2 | LEDM_A3 | LEDM_A4 | LEDM_B4 | LEDM_C4 | LEDM_D3 | LEDM_C2 | LEDM_D4
#define LEDM_K LEDM_B1 | LEDM_A1 | LEDM_C1 | LEDM_D1 | LEDM_C3 | LEDM_B2 | LEDM_A3 | LEDM_D4
#define LEDM_L LEDM_B1 | LEDM_A1 | LEDM_C1 | LEDM_D1 | LEDM_D3 | LEDM_D2
#define LEDM_M LEDM_B1 | LEDM_A1 | LEDM_C1 | LEDM_D1 | LEDM_A4 | LEDM_B4 | LEDM_C4 | LEDM_D4 | LEDM_B2 | LEDM_B3
#define LEDM_N LEDM_B1 | LEDM_A1 | LEDM_C1 | LEDM_D1 | LEDM_A4 | LEDM_B4 | LEDM_C4 | LEDM_D4 | LEDM_B2 | LEDM_C3
#define LEDM_O LEDM_B1 | LEDM_A1 | LEDM_C1 | LEDM_D1 | LEDM_C3 | LEDM_D2 | LEDM_D3 | LEDM_B3 | LEDM_A3 | LEDM_A2
#define LEDM_P LEDM_B1 | LEDM_A1 | LEDM_C1 | LEDM_D1 | LEDM_B3 | LEDM_A2 | LEDM_C2
#define LEDM_Q LEDM_B1 | LEDM_A2 | LEDM_A3 | LEDM_C3 | LEDM_B3 | LEDM_C2 | LEDM_D3
#define LEDM_R LEDM_B1 | LEDM_A1 | LEDM_C1 | LEDM_D1 | LEDM_B3 | LEDM_A2 | LEDM_C2 | LEDM_D3
#define LEDM_S LEDM_B1 | LEDM_A2 | LEDM_A3 | LEDM_C2 | LEDM_C3 | LEDM_D2 | LEDM_D1
#define LEDM_T LEDM_A2 | LEDM_A3 | LEDM_C2 | LEDM_D2 | LEDM_B2 | LEDM_A1
#define LEDM_U LEDM_A3 | LEDM_D2 | LEDM_A1 | LEDM_C1 | LEDM_B1 | LEDM_C3 | LEDM_B3 | LEDM_D3 | LEDM_D1
#define LEDM_V LEDM_A3 | LEDM_D2 | LEDM_A1 | LEDM_C1 | LEDM_B1 | LEDM_C3 | LEDM_B3
#define LEDM_W LEDM_A1 | LEDM_C1 | LEDM_B1 | LEDM_C4 | LEDM_B4 | LEDM_A4 | LEDM_C3 | LEDM_C2 | LEDM_D1 | LEDM_D3
#define LEDM_X LEDM_A1 | LEDM_C2 | LEDM_D1 | LEDM_B3 | LEDM_D3 | LEDM_B1 | LEDM_A3
#define LEDM_Y LEDM_A1 | LEDM_C2 | LEDM_D1 | LEDM_B3 | LEDM_D3 | LEDM_B1 | LEDM_A3
#define LEDM_Z LEDM_A1 | LEDM_C2 | LEDM_D1 | LEDM_B3 | LEDM_D3 | LEDM_B1 | LEDM_A3

#define LEDM_SPACE 0x00
#define LEDM_PLUS LEDM_B2 | LEDM_C1 | LEDM_C2 | LEDM_C3 | LEDM_D2
#define LEDM_EQUALS LEDM_B2 | LEDM_D1 | LEDM_D3 | LEDM_D2 | LEDM_B1 | LEDM_B3
#define LEDM_MINUS LEDM_C3 | LEDM_C2 | LEDM_C1
#define LEDM_EXCLAMATION LEDM_A1 | LEDM_B1 | LEDM_D1
#define LEDM_DOT LEDM_D1
#define LEDM_COMMA LEDM_C1 | LEDM_D1
#define LEDM_UNDERSCORE LEDM_D1 | LEDM_D2 | LEDM_D3

#define LEDM_1 LEDM_B1 | LEDM_A2 | LEDM_B2 | LEDM_C2 | LEDM_D3 | LEDM_D2 | LEDM_D1
#define LEDM_2 LEDM_B1 | LEDM_A2 | LEDM_D2 | LEDM_D1 | LEDM_A3 | LEDM_C2 | LEDM_B3 | LEDM_D3
#define LEDM_3 LEDM_A1 | LEDM_A2 | LEDM_D1 | LEDM_D2 | LEDM_C2 | LEDM_C3 | LEDM_B3
#define LEDM_4 LEDM_C1 | LEDM_B1 | LEDM_C2 | LEDM_C3 | LEDM_B3 | LEDM_A3 | LEDM_D3 | LEDM_A1
#define LEDM_5 LEDM_D1 | LEDM_D2 | LEDM_D3 | LEDM_C3 | LEDM_C2 | LEDM_B1 | LEDM_A1 | LEDM_A2 | LEDM_A3
#define LEDM_6 LEDM_A3 | LEDM_A2 | LEDM_B1 | LEDM_C1 | LEDM_D1 | LEDM_D2 | LEDM_D3 | LEDM_C3 | LEDM_C2
#define LEDM_7 LEDM_A3 | LEDM_A2 | LEDM_A1 | LEDM_B3 | LEDM_C2 | LEDM_D2
#define LEDM_8 LEDM_A3 | LEDM_A2 | LEDM_A1 | LEDM_D2 | LEDM_D1 | LEDM_D3 | LEDM_C1 | LEDM_C3 | LEDM_B3 | LEDM_B1 | LEDM_C2
#define LEDM_9 LEDM_A3 | LEDM_A2 | LEDM_A1 | LEDM_D2 | LEDM_D3 | LEDM_C3 | LEDM_B3 | LEDM_B1 | LEDM_C2 | LEDM_D1
#define LEDM_0 LEDM_O

#define LEDM_DEFAULT_TIMING 500, 50
#define ledm_word(a) a, sizeof(a)
#define LEDM_LEFT 0
#define LEDM_RIGHT 1

#define ledm_letter_row_r(l, r) (l & (1 << (15 - r))) >> ((15 - r) - 3) | (l & (1 << (11 - r))) >> ((11 - r) - 2) | (l & (1 << (7 - r))) >> ((7 - r) - 1) | (l & (1 << (3 - r))) >> ((3 - r))
#define ledm_letter_row_l(l, r) (l & (1 << (12 + r))) >> ((12 + r) - 3) | (l & (1 << (8 + r))) >> ((8 + r) - 2) | (l & (1 << (4 + r))) >> ((4 + r) - 1) | (l & (1 << (r))) >> ((r))
#define ledm_insert_letter_row_r(l, r) ((((((l & 0xF000) >> 12) << 1) & 0xF) | ((r & 0b1000) >> 3)) << 12) | ((((((l & 0x0F00) >> 8) << 1) & 0xF) | ((r & 0b0100) >> 2)) << 8) | ((((((l & 0x00F0) >> 4) << 1) & 0xF) | ((r & 0b0010) >> 1)) << 4) | ((((((l & 0x000F)) << 1) & 0xF) | ((r & 0b0001))))
#define ledm_insert_letter_row_l(l, r) (((((l & 0xF000) >> 12) >> 1) | (r & 0b1000)) << 12) | (((((l & 0x0F00) >> 8) >> 1) | (r & 0b0100) << 1) << 8) | (((((l & 0x00F0) >> 4) >> 1) | (r & 0b0010) << 2) << 4) | (((((l & 0x000F)) >> 1) | (r & 0b0001) << 3))

typedef uint16_t ledm_letter_t;

typedef struct {
    shift_register_t *shift1;
    shift_register_t *shift2;
    uint8_t common_cathode;
} ledm_t;

void ledm_set(ledm_t *matrix, ledm_letter_t l) {
    if (!matrix->common_cathode) {

        l = ~l;
    }

    sr_set(matrix->shift1, l & 0xFF);
    sr_set(matrix->shift2, l >> 8);
}

void ledm_clear(ledm_t *matrix){
    ledm_set(matrix, 0);
}

static inline void ledm_time(ledm_t *matrix, uint32_t letter_delay, uint32_t empty_delay) {
    delay(letter_delay);
    if (empty_delay > 0) {
        ledm_clear(matrix);
        delay(empty_delay);
    }
}

void ledm_show_word(ledm_t *matrix, ledm_letter_t letters[], uint32_t word_size, uint32_t letter_delay, uint32_t empty_delay) {
    uint32_t letter_count = word_size / sizeof(ledm_letter_t);
    for (uint32_t i = 0; i < letter_count; i++) {
        ledm_set(matrix, letters[i]);
        ledm_time(matrix, letter_delay, empty_delay);
    }
}

uint8_t ledm_letter_width(ledm_letter_t letter) {
    if (!letter)
        return 4;
    for (int8_t i = 4; i > 0; i--) {
        if (ledm_letter_row_l(letter, i - 1)) {
            return i;
        }
    }
    return 0;
}

void ledm_show_word_rotating(ledm_t *matrix, ledm_letter_t letters[], uint32_t word_size, uint32_t letter_delay, uint8_t direction, uint8_t ignore_whitespace) {
    uint32_t letter_count = word_size / sizeof(ledm_letter_t);
    ledm_letter_t current_display = 0;

    for (uint32_t current_letter_i = 0; current_letter_i < letter_count; current_letter_i++) {
        ledm_letter_t current_letter = letters[current_letter_i];
        uint8_t letter_width = (ignore_whitespace ? ledm_letter_width(current_letter) : 4) + 1;
        for (uint8_t current_letter_row = 0; current_letter_row < letter_width; current_letter_row++) {
            ledm_letter_t row;

            if (current_letter_row < 4) {
                if (direction) {
                    row = ledm_letter_row_r(current_letter, current_letter_row);
                }
                else {
                    row = ledm_letter_row_l(current_letter, current_letter_row);
                }
            }
            else {
                row = 0;
            }

            if (direction) {
                current_display = ledm_insert_letter_row_r(current_display, row);
            }
            else {
                current_display = ledm_insert_letter_row_l(current_display, row);
            }

            ledm_set(matrix, current_display);
            delay(letter_delay);
        }
    }
}

void ledm_word_lpush(ledm_letter_t buf[], ledm_letter_t chr) {
    int8_t i = 0;

    while (buf[i]) {
        i++;
    }

    for (; i >= 0; i--) {
        buf[i + 1] = buf[i];
    }

    buf[0] = chr;
}

ledm_letter_t num_buf[32];

void ledm_show_int(ledm_t *matrix, int32_t n, uint32_t letter_delay, uint32_t empty_delay, uint8_t base) {
    // clear buffer
    memset(num_buf, 0, sizeof(num_buf));
    uint8_t negative = 0;
    uint32_t word_length = 0;

    if (n < 0) {
        n = -n;
        negative = 1;
    }

    while (n) {
        switch (n % base) {
        case 0:
            ledm_word_lpush(num_buf, LEDM_0);
            break;
        case 1:
            ledm_word_lpush(num_buf, LEDM_1);
            break;
        case 2:
            ledm_word_lpush(num_buf, LEDM_2);
            break;
        case 3:
            ledm_word_lpush(num_buf, LEDM_3);
            break;
        case 4:
            ledm_word_lpush(num_buf, LEDM_4);
            break;
        case 5:
            ledm_word_lpush(num_buf, LEDM_5);
            break;
        case 6:
            ledm_word_lpush(num_buf, LEDM_6);
            break;
        case 7:
            ledm_word_lpush(num_buf, LEDM_7);
            break;
        case 8:
            ledm_word_lpush(num_buf, LEDM_8);
            break;
        case 9:
            ledm_word_lpush(num_buf, LEDM_9);
            break;
        case 10:
            ledm_word_lpush(num_buf, LEDM_A);
            break;
        case 11:
            ledm_word_lpush(num_buf, LEDM_B);
            break;
        case 12:
            ledm_word_lpush(num_buf, LEDM_C);
            break;
        case 13:
            ledm_word_lpush(num_buf, LEDM_D);
            break;
        case 14:
            ledm_word_lpush(num_buf, LEDM_E);
            break;
        case 15:
            ledm_word_lpush(num_buf, LEDM_F);
            break;
        }

        word_length++;
        n = n / base;
    }

    if (negative) {
        ledm_word_lpush(num_buf, LEDM_MINUS);
        word_length++;
    }

    ledm_show_word(matrix, num_buf, word_length * sizeof(ledm_letter_t), letter_delay, empty_delay);
}

#endif // not __led_matrix_h_included__
