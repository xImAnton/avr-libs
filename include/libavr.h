#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#ifndef __libavr_h_included__
#define __libavr_h_included__

#define PIN_OUTPUT 0x01
#define PIN_INPUT 0x00
#define PIN_LOW 0x00
#define PIN_HIGH 0x01

#define I_INT0_RISING ((1 << ISC01) | (1 << ISC00))
#define I_INT0_FALLING (1 << ISC01)
#define I_INT0_CHANGE (1 << ISC00)
#define I_INT0_LOW 0x00

#define I_INT1_RISING ((1 << ISC11) | (1 << ISC01))
#define I_INT1_FALLING (1 << ISC11)
#define I_INT1_CHANGE (1 << ISC01)
#define I_INT1_LOW 0x00

#define delay(ms) uint32_t _t = ms; while (_t--) _delay_ms(1)

#define adc_enable() ADCSRA |= 1 << ADEN
#define adc_disable() ADCSRA &= ~(1 << ADEN)
#define adc_prescale(x) ADCSRA &= 0xF8 | ((x) & 7)

#define ADC_PRESC_2   1
#define ADC_PRESC_4   2
#define ADC_PRESC_8   3
#define ADC_PRESC_16  4
#define ADC_PRESC_32  5
#define ADC_PRESC_64  6
#define ADC_PRESC_128 7

void pin_set_mode(volatile uint8_t *ddr, uint8_t pin, uint8_t mode) {
    if (mode) {
        *ddr |= (1 << pin);
    } else {
        *ddr &= ~(1 << pin);
    }
}

void pin_set(volatile uint8_t *port, uint8_t pin, uint8_t signal) {
    if (signal) {
        *port |= (1 << pin);
    } else {
        *port &= ~(1 << pin);
    }
}

#define pin_read(pin_register, pin) (pin_register & (1 << pin))
#define pin_read_bit(pin_register, pin) ((pin_register & (1 << pin)) >> pin)

inline void i_setup(uint8_t interrupt, uint8_t mode) {
    GICR |= ( 1 << interrupt );
    MCUCR |= mode;
}

uint16_t adc_read(uint8_t channel) {
    ADMUX |= channel & 0x0f;
    ADCSRA |= (1 << ADSC);

    while((ADCSRA&(1<<ADIF))==0);

    _delay_us(10);
    return ADCL | (ADCH << 8);
}

#endif // not __libavr_h_included__
