#include "uartDriver.h"
/**/
/**/
/************************************** UART simplex Tx - Begin ****************************************/
void uartInitTx(void){
	//Enable clock to GPIOA
	*reinterpret_cast<volatile std::uint32_t*>(ahb1Enr) |= static_cast<std::uint32_t>(1U<<0);
	 //Enable clock to UART2
	*reinterpret_cast<volatile std::uint32_t*>(apb1Enr) |= static_cast<std::uint32_t>(1U<<17);
	
  //Configure PA2 as UART2 TX
	*reinterpret_cast<volatile std::uint32_t*>(gpioaModer) |= static_cast<std::uint32_t>(0U<<4);
	*reinterpret_cast<volatile std::uint32_t*>(gpioaModer) |= static_cast<std::uint32_t>(1U<<5);
	
  //Set ALT type  to UART2
	*reinterpret_cast<volatile std::uint32_t*>(gpioaAfrl) |= static_cast<std::uint32_t>(0x7000);
	
	//Confidure USART2 baudrate 9600  @ 16MHz
	*reinterpret_cast<volatile std::uint32_t*>(usart2Brr) =static_cast<std::uint32_t>(0x0683);
 
	//Enable Tx,8-bit
	*reinterpret_cast<volatile std::uint32_t*>(usart2Cr1) =static_cast<std::uint32_t>(0x00C);
  
  //1 stop bit//
	*reinterpret_cast<volatile std::uint32_t*>(usart2Cr2) =static_cast<std::uint32_t>(0x000);
  
	//No flow control
	*reinterpret_cast<volatile std::uint32_t*>(usart2Cr3) =static_cast<std::uint32_t>(0x00);

	//Enable UART
	*reinterpret_cast<volatile std::uint32_t*>(usart2Cr1) |= static_cast<std::uint32_t>(0x2000);
}
/**/
int uartWriteTx(int ch){
 
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

	//Enable clock to GPIOA
	*reinterpret_cast<volatile std::uint32_t*>(ahb1Enr) |= static_cast<std::uint32_t>(1U<<0);
	
	//Enable clock to UART2
	*reinterpret_cast<volatile std::uint32_t*>(ahb1Enr) |= static_cast<std::uint32_t>(1U<<17);
	
	
  /*Configure PA3 as  ALT pin UART2 RX*/
	*reinterpret_cast<volatile std::uint32_t*>(gpioaModer) |= static_cast<std::uint32_t>(0U<<6);
	*reinterpret_cast<volatile std::uint32_t*>(gpioaModer) |= static_cast<std::uint32_t>(1U<<7);
	
  /*Set ALT type  to UART2*/  
	*reinterpret_cast<volatile std::uint32_t*>(gpioaAfrl) |= static_cast<std::uint32_t>(0x7000);
	
	/*Confidure USART2 baudrate 9600  @ 16MHz*/
	*reinterpret_cast<volatile std::uint32_t*>(usart2Brr) =static_cast<std::uint32_t>(0x0683);
 
	/*Enable Rx,8-bit*/
  *reinterpret_cast<volatile std::uint32_t*>(usart2Cr1) =static_cast<std::uint32_t>(0x004);
  /*1 stop bit*/
	*reinterpret_cast<volatile std::uint32_t*>(usart2Cr2) =static_cast<std::uint32_t>(0x000);
  /*No flow control*/
	*reinterpret_cast<volatile std::uint32_t*>(usart2Cr3) =static_cast<std::uint32_t>(0x00);
   /*Enable UART*/
	*reinterpret_cast<volatile std::uint32_t*>(usart2Cr1) |= static_cast<std::uint32_t>(0x2000);
};
/**/
char uartReadRx(void){
	
	char ch;

	
	/*wait until char arrives*/
	while(!(*reinterpret_cast<std::uint32_t*>(usart2Sr) & 0x0020)){}   //0010 0000  
	
	ch = *reinterpret_cast<volatile std::uint32_t*>(usart2Dr); 
  
	return ch;
};
/************************************** UART simplex Rx - End ****************************************/
/**/
/**/
/**/
/************************************** UART duplex Rx-Tx - Begin **************************************/
void uartInitRTx(void){
	/*Enable clock to GPIOA*/
	*reinterpret_cast<volatile std::uint32_t*>(ahb1Enr) |= static_cast<std::uint32_t>(1U<<0);
	 /*Enable clock to UART2*/
	*reinterpret_cast<volatile std::uint32_t*>(apb1Enr) |= static_cast<std::uint32_t>(1U<<17);

	
  /*Configure PA2,PA3 as  ALT pin UART2 TX,RX*/
	*reinterpret_cast<volatile std::uint32_t*>(gpioaModer) |= static_cast<std::uint32_t>(0U<<6);
	*reinterpret_cast<volatile std::uint32_t*>(gpioaModer) |= static_cast<std::uint32_t>(1U<<7);
	
	*reinterpret_cast<volatile std::uint32_t*>(gpioaModer) |= static_cast<std::uint32_t>(0U<<4);
	*reinterpret_cast<volatile std::uint32_t*>(gpioaModer) |= static_cast<std::uint32_t>(1U<<5);
	

  /*Set ALT type  to UART2 for PA3 and PA2*/  
	*reinterpret_cast<volatile std::uint32_t*>(gpioaAfrl) |= static_cast<std::uint32_t>(0x7700);
	
	/*Confidure USART2 baudrate 9600  @ 16MHz*/
	*reinterpret_cast<volatile std::uint32_t*>(usart2Brr) =static_cast<std::uint32_t>(0x0683);
 
	/*Enable Rx,8-bit*/
	*reinterpret_cast<volatile std::uint32_t*>(usart2Cr1) =static_cast<std::uint32_t>(0x00C);
	
  /*1 stop bit*/
	*reinterpret_cast<volatile std::uint32_t*>(usart2Cr2) =static_cast<std::uint32_t>(0x000);
  
	/*No flow control*/
	*reinterpret_cast<volatile std::uint32_t*>(usart2Cr3) =static_cast<std::uint32_t>(0x00);

	/*Enable UART*/
	*reinterpret_cast<volatile std::uint32_t*>(usart2Cr1) |= static_cast<std::uint32_t>(0x2000);
}
/**/
/**/
char uartReadRTx(void){
	
	char ch;

	
	/*wait until char arrives*/
	while(!(*reinterpret_cast<std::uint32_t*>(usart2Sr) & 0x0020)){}   //0010 0000  
	
	ch = *reinterpret_cast<volatile std::uint32_t*>(usart2Dr); 
  
	return ch;
}
/**/
/**/
int uartWriteRTx(int ch){
 
	std::uint32_t _ch =  ch & 0xFF;
	
	/*Wait until TX buffer is empty*/
	while(!(*reinterpret_cast<std::uint32_t*>(usart2Sr) & 0x0080)){}
		*reinterpret_cast<volatile std::uint32_t*>(usart2Dr) =static_cast<std::uint32_t>(_ch);
	return 1;
}
/************************************** UART duplex Rx-Tx - End **************************************/
/**/
/**/
/**/
/************************************** UART Driver Console Binding - Begin **************************/
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
		c = uartReadRTx();
		
		if(c=='\r'){
			uartWriteRTx(c);
			c = '\n';
		}
		uartWriteRTx(c);
		return c;
	}
 ///the function definitions below will not be used
 ///but we have to redefine all functions
	int fputc(int c, FILE* stream){
		return uartWriteRTx(c);
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
/************************************** UART Driver Console Binding - End **************************/
