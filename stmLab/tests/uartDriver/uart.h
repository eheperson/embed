/*	note before begin USART and UART are same

	UART is an peripheral,
	we have to check datasheet of mcu  >>>
	to ind out how the uart is connected to our processor
	
	!!!!!! We have to see how peripherals conncts to register !!!!!!
	
	There is a clockgate mechanism :
		clock access to different parts of microcontroller, including peripherals,
		are disabled bydefault and this helps the microcontrollers save power
		IN ORDER TO USE IT, THEREFORE WE HAVE TO ENABLE THE CLOCK ACCESS
		TO THAT PARTICULAR PERIPHERAL AND TO ENABLE THE CLOCK ACCESS 
		WE HAVE TO FIND OUT WHICH BUS
				check page 14 of datasheet (schematic)
------------------------------------------------------------------------
	USART2 module is connected to the APB1 bus
	we have to go to the APB1 bus register and find the
	register that is usefull enabling its modules
------------------------------------------------------------------------
	!!!!!!! USART is an alternate function !!!!!!!!!!!!!!!
	pins are typically coded as GPIO
	if we wish use them for other functions they become SPIO
	
	there are 2 alternate function register (maybe there are more than 2 bur I learned 2 of them)
	GPOIx_AFRL : alternate function low register, adress offset : 0x20
	ARFLy : Alternate function selection for port x bit y ( y = 0..7)
					These bits are written by software to configure alternate functions I/O
				
				AFRLy selection : 
				
				0000: AF0				1000: AF8
				0001: AF1				1001: AF9
				0010: AF2				1010: AF10
				0011: AF3				1011: AF11
				0100: AF4				1100: AF12
				0101: AF5				1101: AF13
				0110: AF6				1110: AF14
				0111: AF7				1111: AF15
				
				If we wanna configure AFRL0 for 'alternate function 0' (AF0)
				then we have to set ARFL0 to 0000
				If we wanna configure AFRL0 for 'alternate function 1' (AF1)
				then we have to set ARFL0 to 0001
				...
				...
				All of these AF0 AF1 AF2 has meaning 
				AF0 could be UART
				AF1 could be ADC
				AF2 could be PWM
				we have to find their meaning...
				
				>>>Selecting an alternate function on STM32
					page 15 0on reference manual
					the reason weareable to select different alternate function options
					is because it uses multiplexing
				
				I will found it for uart driver also :D
				then
				be ready for secret info
				0111 : AF7 is for UART
				
------------------------------------------------------------------------
	ANY GPIO PIN CAN BE CONFIGURED TO BE RECEIVER FOR THE UART OR
	A TRANSMITTER FOR THE UART
------------------------------------------------------------------------
	for USART2 tx and rx pins are connected to PA2 and PA3 respectively
	we have to configure them to use via usart 
			---need anther document : reference manual
------------------------------------------------------------------------
GPIOx_MODER register to setdirection of data for each pin
MODERy[1:0] Poert configuration pin for any port

*/
#ifndef __UART_H
#define __UART_H
#include "stm32f4xx.h"                  // Device header
#include<stdio.h>

void uartInit(void);

int uartWrite(int ch);

int uartRead(void);
#endif
