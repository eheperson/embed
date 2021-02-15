#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>//it has delay function


int main(void)
{
DDRA=0b00000001;
while(1)
       {
     PORTA=0b00000001;
     _delay_ms(1000); //so that LED would remain in ON state for 1 sec and then  turns off  for  1 sec.     
     PORTA=0b00000000;
     _delay_ms(1000);
       }
}
