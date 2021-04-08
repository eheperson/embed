#ifndef _UARTDRIVER_H_
#define _UARTDRIVER_H_
/*Procedure:
1. Enable the USART by writing the UE bit in USART_CR1 register to 1.
2. Program the M bit in USART_CR1 to define the word length.
3. Program the number of stop bits in USART_CR2.
4. Select DMA enable (DMAT) in USART_CR3 if Multi buffer Communication is to take
place. Configure the DMA register as explained in multibuffer communication.
5. Select the desired baud rate using the USART_BRR register.
6. Set the TE bit in USART_CR1 to send an idle frame as first transmission.
7. Write the data to send in the USART_DR register (this clears the TXE bit). Repeat this
for each data to be transmitted in case of single buffer.
8. After writing the last data into the USART_DR register, wait until TC=1. This indicates
that the transmission of the last frame is complete. This is required for instance when
the USART is disabled or enters the Halt mode to avoid corrupting the last
transmission.*/

#include "memoryMap.h"
#include "stm32f4xx.h" 

/************************************** UART simplex Tx - Begin ****************************************/
void uartInitTx(void){
	
	//Enable clock to GPIOA
	*reinterpret_cast<volatile std::uint32_t*>(ahb1Enr) |= (1U<<0);
 	//mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::ahb1Enr,(1U<<0)>::reg_or();
	
	//Enable clock to UART2
	*reinterpret_cast<volatile std::uint32_t*>(ahb1Enr) |= (1U<<17);
 	//mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::apb1enr,(1U<<17)>::reg_or();
	
	
  //Configure PA2 as UART2 TX
	*reinterpret_cast<volatile std::uint32_t*>(gpioaModer) |= (0U<<4);
	*reinterpret_cast<volatile std::uint32_t*>(gpioaModer) |= (1U<<5);

	
  //Set ALT type  to UART2
	*reinterpret_cast<volatile std::uint32_t*>(gpioaAfrl) |= (0x0700);

	
	//Confidure USART2 baudrate 9600  @ 16MHz
	*reinterpret_cast<volatile std::uint32_t*>(usart2Brr) = 0x0683;
 
	//Enable Tx,8-bit
	*reinterpret_cast<volatile std::uint32_t*>(usart2Cr1) = 0x008;
  
	
  //1 stop bit
	*reinterpret_cast<volatile std::uint32_t*>(usart2Cr2) = 0x000;
	 
	 
  //No flow control
	*reinterpret_cast<volatile std::uint32_t*>(usart2Cr3) = 0x000;
	
	
  //Enable UART*/
	*reinterpret_cast<volatile std::uint32_t*>(usart2Cr1) |= (0x2000);
	 
}

void uartWriteTx(int ch){
 
	std::uint32_t _ch =  ch & 0xFF;
	
	/*Wait until TX buffer is empty*/
	while(!(*reinterpret_cast<std::uint32_t*>(usart2Sr) & 0x0080)){};
		*reinterpret_cast<volatile std::uint32_t*>(usart2Dr) = static_cast<std::uint32_t>(_ch);
}

/************************************** UART simplex Tx - End ****************************************/
/**/
/**/
/**/
/************************************** UART simplex Rx - Begin ****************************************/
void uartInitRx(void){
	

}
/************************************** UART simplex Rx - End ****************************************/
/**/
/**/
/**/
/************************************** UART duplex Rx-Tx - Begin **************************************/
void uartInitRTx(void){
	
	/*Enable clock to GPIOA*/
	*reinterpret_cast<volatile std::uint32_t*>(ahb1Enr) |= (1U<<1);
	
	 /*Enable clock to UART2*/
	*reinterpret_cast<volatile std::uint32_t*>(ahb1Enr) |= (0X20000);
	
  /*Configure PA2,PA3 as  ALT pin UART2 TX,RX*/
	*reinterpret_cast<volatile std::uint32_t*>(gpioaModer) |= (0U<<6);
	*reinterpret_cast<volatile std::uint32_t*>(gpioaModer) |= (1U<<7);
	
	*reinterpret_cast<volatile std::uint32_t*>(gpioaModer) |= (0U<<4);
	*reinterpret_cast<volatile std::uint32_t*>(gpioaModer) |= (1U<<5);

  /*Set ALT type  to UART2 for PA3 and PA2*/  
	*reinterpret_cast<volatile std::uint32_t*>(gpioaAfrl) |= (0x7700);
	
	/*Confidure USART2 baudrate 9600  @ 16MHz*/
	*reinterpret_cast<volatile std::uint32_t*>(usart2Brr) = 0x0683;
 
	/*Enable Rx,8-bit*/
	*reinterpret_cast<volatile std::uint32_t*>(usart2Cr1) = 0x00C;
	
  /*1 stop bit*/
	*reinterpret_cast<volatile std::uint32_t*>(usart2Cr2) = 0x000;
  
	/*No flow control*/
	*reinterpret_cast<volatile std::uint32_t*>(usart2Cr3) = 0x00;

	/*Enable UART*/
	*reinterpret_cast<volatile std::uint32_t*>(usart2Cr1) |= (0x2000); 
}

char uartReadRTx(void){
	
	char ch;

	
	/*wait until char arrives*/
	while(!(usart2Sr) & 0x0020) {}   //0010 0000  
	
	ch = *reinterpret_cast<volatile std::uint32_t*>(usart2Dr); 
  
	return ch;
}


void uartWriteRTx(int ch){
 
	std::uint32_t _ch =  ch & 0xFF;
	
	/*Wait until TX buffer is empty*/
	while(!(*reinterpret_cast<std::uint32_t*>(usart2Sr) & 0x0080)){}
		*reinterpret_cast<volatile std::uint32_t*>(usart2Dr) =static_cast<std::uint32_t>(_ch);
		
}

/************************************** UART duplex Rx-Tx - End **************************************/










#endif


