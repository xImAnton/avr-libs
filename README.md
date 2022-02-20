# avr-libs
My libraries for easier AVR development

## include/libavr.h
Small lib for abstraction of port and pin byte operations.

## include/libshift.h
Library for dealing with shift registers.

## include/event.h
Event buffer pushing and polling abstractions.

## include/notes.h
ICR values for AVR micro controllers to play sound using PWM

## include/random.h
PRNG that can be seeded using noise from an ADC port.

## include/led_matrix.h
Abstractions for controlling single 4x4 LED matrices that are connected
to the AVR-Chip via shift registers.

## include/led_screen.h
Abstractions for using a grid of LED matrices as a screen with individually
addressable pixels.

## examples
Small examples that are not worth a new repository.

## Resources
[Fuse Bit Calculator](http://eleccelerator.com/fusecalc/fusecalc.php)
