#
#
avr-gcc -Wall -g -Os -mmcu=atmega16 -o main.bin main.c
#
#
avr-size -C main.bin
#
#
avr-objcopy -j .text -j .data -O ihex main.bin main.hex
#
#
avrdude -p atmega16 -c usbasp -U flash:w:main.hex:i -F -P usb
