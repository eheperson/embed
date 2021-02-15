#include <16F877A.h>
#use delay(crystal=4000000)
#include<lcd.c>

//#define usb_portb_lcd TRUE

#use fast_io(b)


#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES XT
#FUSES NOPROTECT
#FUSES NOPUT
#FUSES NOWRT
#FUSES NOCPD
#FUSES NODEBUG






