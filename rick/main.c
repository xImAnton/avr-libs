#include <avr/io.h>
#include <util/delay.h>
#include "notes.h"

#define DEFAULT_VOLUME 100

void init() {
	// Configure OC1B pin as output

    DDRB |= _BV(PB2);
	// DDRD |= _BV(DDD4); //OC1B as output

	// timer1 configuration (for PWM)
    TCCR1A |= _BV(COM1B1);  // Clear OC1A/OC1B on compare match

	TCCR1B |= _BV(WGM13) 	//mode 8, PWM, Phase and Frequency Correct (TOP value is ICR1)
		   |_BV(CS11); 		//prescaler(8)
}

void play_track(const int* pMusicNotes, uint8_t tempo) {
	int duration;
	int note;
	int i;
	uint16_t delay = tempo * 10000;

	while (*pMusicNotes) {
		note = *pMusicNotes;
		pMusicNotes++;

		duration = *pMusicNotes;
		pMusicNotes++;

		if (p == note) {
			// pause, do not generate any sound
			OCR1B = 0;
		} else {
			// not a pause, generate tone
			OCR1B = DEFAULT_VOLUME;

			// set frequency
			ICR1H = (note >> 8);
			ICR1L = note;
		}

		for (i = 0; i < 32 / duration; i++) {
			_delay_loop_2(delay);
			_delay_loop_2(delay);
			_delay_loop_2(delay);
			_delay_loop_2(delay);
			_delay_loop_2(delay);
		}

	}

	//turn off any sound
	OCR1B = 0;
}

#define P8 p,8
#define P16 p,16
#define P32 p,32


const int rick[] = {
    A3,16,  B3,16, D4,16,  B3,16, P32, // never gonna
    Fis4,8, P32,   Fis4,8, P32,   E4,4, P8, // give you up
    A3,16,  B3,16, D4,16,  B3,16, P32, // never gonna
    E4,8,   P32,   E4,8,   P32,   D4,16, Cis4,16, B3,4, P8, // let you down
    A3,16,  B3,16, D4,16,  B3,16, P32, // never gonna
    D4,8,   P32, E4,8, P32, Cis4,16, B3,16, A3,4, P16, A3,8, E4,4, D4,4, P8, // run around and desert you
	A3,16,  B3,16, D4,16,  B3,16, P32, // never gonna
    Fis4,8, P32,   Fis4,8, P32,   E4,4, P8,
    A3,16,  B3,16, D4,16,  B3,16, P32,
    E4,8,   P32,   E4,8,   P32,   D4,16, Cis4,16, B3,4, P8,
    A3,16,  B3,16, D4,16,  B3,16, P32,
    D4,8,   P32, E4,8, P32, Cis4,16, B3,16, A3,4, P16, A3,8, E4,4, D4,4, P8,
    MUSIC_END
};


int main() {
	PORTB = 0x00; 
	init();

	while (1) {
		play_track(rick, 10);
		_delay_ms(1000);
	}
}
