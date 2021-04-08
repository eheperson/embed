#include "uart.h"
//#include<iostream> 
/*
	iostream library is perfect for our computer but
	it is so huge for embedded devices
	rather than use iostream we can simply use printf
	printf("Hello motherfuckers \r\n");

*/

/* increase heap
HEAP SIZE IS CHANGED 
	FROM :
		Heap_Size       EQU     0x00000200
	TO:
		Heap_Size       EQU     0x00002000

	in 'startup_stm32f401xw.s(Startup)' file
*/



typedef std::uint32_t  reg;
typedef std::uint16_t  value;

//---------------------------------------------------------------------------------
// Global base addresses.
const reg periphB       =  0x40000000U;

// Individual unit base addresses.
const reg ahb1Pbase     = periphB     + 0x00020000U;
const reg rccB          = ahb1Pbase + 0x00003800U;
      
const reg ahb1enr       =	rccB + 0x30;
const reg ahb2enr       =	rccB + 0x34;
		 
const reg apb1enr       = rccB+ 0x40;
const reg apb2enr       = rccB+ 0x44;

      
const reg gpioaB        = ahb1Pbase +  0x0000;

const reg adc1B  				= 0x40012000U;


 // Port registers.
			
const reg  moderOff     =  0x0000;  

const reg  gpioaModer   = gpioaB  +  moderOff;  



const reg  adcSqrt1off  = 0x2C;
const reg  adcSqrt2off  = 0x30;	
const reg  adcSqrt3off  = 0x34;

const reg  adc1Sqrt1 		= adcSqrt1off    + adc1B;
const reg  adc1Sqrt2 		= adcSqrt2off    + adc1B;
const reg  adc1Sqrt3 		= adcSqrt3off    + adc1B;

const reg  adcDroff     = 0x4C;	
const reg  adcCr2off    = 0x08;
const	reg  adc1Cr2 		= adcCr2off   + adc1B;
const reg  adc1Dr       = adcDroff      + adc1B;
//---------------------------------------------------------------------------------


int main(){
	uartInit();
	
	reg ADCdata;
 
	

	
	//Enable clock access to PA1
	*reinterpret_cast<volatile reg*>(ahb1enr) |= static_cast<reg>(1U<<0);
	
	//Configure PA1 as analog pin
	*reinterpret_cast<volatile reg*>(gpioaModer) |= static_cast<reg>(1U<<2);
	*reinterpret_cast<volatile reg*>(gpioaModer) |= static_cast<reg>(1U<<3);

	//Enable clock access to ADC1
	*reinterpret_cast<volatile reg*>(apb2enr) |= static_cast<reg>(1U<<8);
	
	//SW Trigger
	*reinterpret_cast<volatile reg*>(adc1Cr2) = static_cast<reg>(0x00);

  
	//Conversion sequence starts at ch1
	*reinterpret_cast<volatile reg*>(adc1Sqrt3) =static_cast<reg>(1U<<0);

	
  //Conversion seqeunce length 1
	*reinterpret_cast<volatile reg*>(adc1Sqrt1) =static_cast<reg>(0x00);
	
	//Enable ADC
	*reinterpret_cast<volatile reg*>(adc1Cr2) |=static_cast<reg>(1U<<0);
	
	

	printf("start");
	while(1){
		//uartWrite('Y');
		//or we can use just
		//std::cout << "Hello motherfuckers \r\n";
		
		//Start a conversion
		*reinterpret_cast<volatile reg*>(adc1Cr2) |=static_cast<reg>(1U<<30);
		
		//Wait for conversion completion
		while(!(ADC1->SR) & (0x02)){}
			
	  //Read	value from data register

		ADCdata = *reinterpret_cast<volatile reg*>(adc1Dr);
		printf("ADC Value : %f \r\n",((float(ADCdata) / 4096.0 )* 3.3));
		//printf("ADC Value : %d \r\n",ADCdata);
		
			
		
	}
	return 0;
	
	
}
