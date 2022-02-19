# AVR Model
MCU=atmega32
DUDE_MCU=m32

# Clock Speed
F_CPU=16000000 # 16 MHz

# output file name
TARGET=tetris

# source files to compile
SRCS=main.c

CC=avr-gcc
SIZE=avr-size
OBJCOPY=avr-objcopy
CFLAGS=-Wall -g -Os -std=c99
CFLAGS += -mmcu=$(MCU)
CFLAGS += -D F_CPU=$(F_CPU)
CFLAGS += -I ../include/

build:
	$(CC) $(CFLAGS) -o $(TARGET).bin $(SRCS)
	$(OBJCOPY) -j .text -j .data -O ihex $(TARGET).bin $(TARGET).hex
verify:
	$(SIZE) -C $(TARGET).bin
flash:
	avrdude -p $(DUDE_MCU) -c usbasp -v -P usb -U flash:w:$(TARGET).hex
all:
	$(MAKE) build
	$(MAKE) verify
	$(MAKE) flash
clean:
	rm -f *.bin *.hex
