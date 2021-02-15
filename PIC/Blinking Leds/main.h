#include <16F877A.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES XT
#FUSES NOPROTECT
#FUSES NOPUT
#FUSES NOWRT
#FUSES NOCPD
#FUSES NODEBUG

#use delay(crystal=4000000)

#use fast_io(b)

