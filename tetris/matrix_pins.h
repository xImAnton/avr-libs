#define SR_A(name, d, c) shift_register_t name = { SR_SIZE_8 .ddr = &DDRA, .port = &PORTA, .clock = c, .data = d }
#define SR_B(name, d, c) shift_register_t name = { SR_SIZE_8 .ddr = &DDRB, .port = &PORTB, .clock = c, .data = d }
#define SR_C(name, d, c) shift_register_t name = { SR_SIZE_8 .ddr = &DDRC, .port = &PORTC, .clock = c, .data = d }
#define SR_D(name, d, c) shift_register_t name = { SR_SIZE_8 .ddr = &DDRD, .port = &PORTD, .clock = c, .data = d }

#define MATRIX(name) ledm_t name = { .shift1 = &(name ## o), .shift2 = &(name ## u), .common_cathode = 0 }

SR_B(olu, PB4, PB3);
SR_A(olo, PA2, PA3);
MATRIX(ol);

SR_A(oru, PA4, PA5);
SR_A(oro, PA6, PA7);
MATRIX(or);

SR_C(mru, PC7, PC6);
SR_C(mro, PC5, PC4);
MATRIX(mr);

SR_C(mlu, PC3, PC2);
SR_D(mlo, PD7, PD6);
MATRIX(ml);

SR_D(ulu, PD5, PD4);
SR_D(ulo, PD3, PD2);
MATRIX(ul);

SR_D(uru, PD1, PD0);
SR_C(uro, PC1, PC0);
MATRIX(ur);
