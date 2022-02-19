#include "led_matrix.h"

#define TET_I 0
#define TET_J 1
#define TET_L 2
#define TET_O 3
#define TET_S 4
#define TET_T 5
#define TET_Z 6

typedef uint8_t tetromino_t;

typedef struct {
    uint8_t x;
    uint8_t y;
} position_t;

tetromino_t tet_random() {
    return 0;
}

typedef struct {
    ledm_t* matrices;
    uint8_t width;
    uint8_t height;
    
    tetromino_t next;
    position_t* next_position;
} tetris_t;

void tet_init(tetris_t* t) {
    t->next = tet_random();

    position_t next_pos = {
        .x = 0,
        .y = 0
    };

    t->next_position = &next_pos;
}
