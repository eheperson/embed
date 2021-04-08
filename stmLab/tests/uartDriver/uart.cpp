#include "uart.h"

void uartInit(void){
	RCC->AHB1ENR |= 0x1; //enable GPIOA clock
	RCC->APB1ENR |= 0x20000; //enable USART2 clock
	
	// configure PA2, PA3 for USART2 TX, RX*/
	/*
	To get access our AFR register : GPIOA -> AFR
	GPIOA -> ARF[0] : to access GPIOA_ARFL
	GPIOA -> ARF[1] : to access GPIOA_ARFH
	
	to set alternate function for PA2 and PA3 
	we need to reach ARFL : GPIOA -> ARF[0]
	
	GPIOx_ARFL : GPIO alternate function lowregister
	AFRLy : alternate function selection for port x bit y
	GPIOA_ARFL2
	
	then.......

	*/
	GPIOA -> AFR[0] |= 0x7700; //7 = 0111  ....AF7 for usart2
	//                 0b0111 0111 0000 0000
	//                    PA3	 PA2  PA1  PA0	
	/* 	
	we have got to go to the MODER -mode register-
	and we want to set the mood as alternate function pin.
	*/
	//
	/* 
		SPECIFIC USART PARAMETERS
	*/
	GPIOA -> MODER |= 0x00A0;  //enable alternate function for PA2 and PA3
	//
	USART2 -> BRR = 0x0683; //set baudrate to 9600 baud @16MHz
	USART2 -> CR1 = 0x000C; //enable tx rx 8-bit data
	USART2 -> CR2 = 0x000; // 1 stop bit
	USART2 -> CR3 = 0x000; //no flow control
	USART2 -> CR1 |= 0x2000; //enable USART2
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/*
	to write data 
	we have to do is wait for the transmit buffer of the uart to be empty
	to do that we have to check a particular bit in the STATUS register
	
*/
int uartWrite(int ch){
	while(!(USART2->SR & 0x0080)){} // wait until  Tx empty
	USART2 -> DR = (ch & 0xFF);
	return 1;	//retrun 1 if it successed
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/*
	to read data 
	we have to check status register again
	for the character we wanna read to arrive 
  USART2 -> SR : 0x00000020 : 0b 0000 0000 0000 0000 0000 0000 0010 0000
	we need to check bit 5 of status register of usart
	if that bit is 1 
  then character has arrived
*/
int uartRead(void){
		while(!(USART2->SR & 0x020)){} //wait until arrive data to usart
		return USART2->DR;
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/* Bind our UART to the c or c++ console
*/


namespace std{
	struct __FILE{ //
		int handle; // 
	};
	
	FILE __stdout;
	FILE __stdin;
	FILE __stderr;
	
//////that section is specific to ARM architecture
////// read documentations for more info
////// different from other compilers
	int fgetc(FILE *f){
		int c;
		c = uartRead();
		
		if(c=='\r'){
			uartWrite(c);
			c = '\n';
		}
		uartWrite(c);
		return c;
	}
 ///the function definitions below will not be used
 ///but we have to redefine all functions
	int fputc(int c, FILE* stream){
		return uartWrite(c);
	}
	
	int ferror(FILE* stream){
		return 1;
	}
	
	long int ftell(FILE* stream){
		return 1;
	}
	
	int fclose(FILE* f){
		return 1;
	}
	int fseek(FILE *f, long nPos, int nMode){
		return 0;
	}
	int fflush(FILE* f){
		return 1;
	}
}
