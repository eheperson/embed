# AVR Programming Environment Installer Script
#
apt-get update
#
# installing latest gcc complier
apt-get install gcc build-essential 
#
# gcc-avr : AVR gcc compiler
# binutils-avr : binary utilities for AVR
# avr-libc : C library for AVR micro-controllers
# gbd-avr : GNU debugger for AVR
apt-get install gcc-avr binutils-avr avr-libc gbd-avr 
#
#
# avrdude : In-system programming software. 
# AVRDUDE is an open source utility to download/upload/manipulate 
# the ROM and EEPROM contents of AVR microcontrollers 
# using the in-system programming technique (ISP)
apt-get install avrdude
#
#
# If you are using USB programmers such atmel “avrisp mk2” or “usbtiny” 
apt-get install libusb-dev
#
#
#
# echo "##########################################################################################"
# echo "##########################################################################################"
# echo " PLEASE FOLLOW THE INSTUCTIONS AFTER RUNNING THE SCRIPT "
# echo "##########################################################################################"
# echo "##########################################################################################"
# echo ""
# echo "1 - Connect AVR ISP mkII to PC. Use the following command : lsusb "
# echo ""
# echo "2 - Connect the AVR ISP mkII 6 pin programming header to Board. Figure below, shows the pin diagram for ISP connector. If your connection is right (and board is powered) you should see green LED in programmer. "
# echo " Verify reading device signature. Use following command : avrdude -c avrisp2 -p t44 "
# echo "If everything goes well, you should be able to read device signature successfully. This confirms you have work software toolchain and you can talk to your micro-controller through programmer."
# echo ""
# echo "3 - Testfile to the blinking led will automatically created : testAVR.c "
# echo "testAVR.c : Blinks LED connected to Pin PA6"
# echo ""
# echo "4 - Create make file and save it as BlinkLED.make"
# echo ""
# echo "5 -Program fuses using avrispmk2 programmer (or other programmer, see makefile) : "
# echo "'sudo make -f BlinkLED.make program-avrisp2-fuses'  or  'sudo make -f BlinkLED.make program-avrisp2'"
# echo ""
# echo ""
# echo "If everything goes well, you should see led blinking in your board. Congratulations!! you have successfully programmed your board."
#
#
#
# touch testAVR.c
#
# echo "// Blinks LED connected to Pin PA6 #include <avr/io.h> #include <util/delay.h> #define output(directions,pin) (directions |= pin) // set port direction for output #define input(directions,pin) (directions &= (~pin)) // set port direction for input #define set(port,pin) (port |= pin) // set port pin #define clear(port,pin) (port &= (~pin)) // clear port pin #define pin_test(pins,pin) (pins & pin) // test for port pin #define bit_test(byte,bit) (byte & (1 << bit)) // test for bit set #define led (1 << PA6) #define led_port PORTA #define led_direction DDRA int main(void) { while (1) { output(led_direction, led); set(led_port, led); _delay_ms(10); clear(led_port, led); _delay_ms(10); } }" > testAVR.c


