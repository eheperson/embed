#ifndef _MEMORYMAP_H_
#define _MEMORYMAP_H_

#include <cstdint>


/****************************************** Global Base Adresses - Begin ******************************************/
		 
	const std::uint32_t periphB         =  0x40000000U; //peripheral base adress
	
/****************************************** Global Base Adresses - End ********************************************/
//
//
//
/************************************** Indivicual Unit Base Adresses - Begin *************************************/

      const std::uint32_t ahb1PeriphB     = periphB     + 0x00020000U;
      const std::uint32_t rccB            = ahb1PeriphB + 0x00003800U;
      
	const std::uint32_t ahb1Enr         =	rccB + 0x30;
	const std::uint32_t ahb2Enr         =	rccB + 0x34;
	const std::uint32_t ahb3Enr 	      =	rccB + 0x38;
			
	const std::uint32_t abp1Enr	      = rccB + 0x40;
      
	const std::uint32_t gpioaB          = ahb1PeriphB +  0x0000;
      const std::uint32_t gpiobB          = ahb1PeriphB +  0x0400;
      const std::uint32_t gpiocB          = ahb1PeriphB +  0x0800;
      const std::uint32_t gpiodB          = ahb1PeriphB +  0x0C00;
      const std::uint32_t gpioeB          = ahb1PeriphB +  0x1000;
      const std::uint32_t gpiofB          = ahb1PeriphB +  0x1400;
      const std::uint32_t gpiogB          = ahb1PeriphB +  0x1800;
			
	//const std::uint32_t usart1B         = 0x4001100U;
	const std::uint32_t usart2B         = 0x40004400;
	//const std::uint32_t usart6B         = 0x4001140U;
			
/************************************** Indivicual Unit Base Adresses - End *************************************/
//
//
//
/**************************************** Port Registers Adresses - Begin ***************************************/
			
      const std::uint32_t moderO          =  0x0000;   // Mode Register Offset
      const std::uint32_t otyperO         =  0x0004;   // Output Type Register Offset
      const std::uint32_t ospeedrO        =  0x0008;   // Output Speed Register Offset
      const std::uint32_t pupdrO          =  0x000C;   // Pull-up Pull-down Register Offset 
      const std::uint32_t idrO            =  0x0010;   // Input Data Register Offset
      const std::uint32_t odrO            =  0x0014;   // Output Data Register Offset
      const std::uint32_t bsrrO           =  0x0018;   // Bit Set Reset Register Offset
      const std::uint32_t lckrO           =  0x001C;   // Pull-up Pull-down Register Offset
      const std::uint32_t afrlO           =  0x0020;   // Pull-up Pull-down Register Offset
      const std::uint32_t afrhO           =  0x0024;   // Pull-up Pull-down Register Offset
			
	const std::uint32_t srO  	      = 0x00;  // Usart status Register Offset 
	const std::uint32_t drO	            = 0x04;  // Usart data register offset
	const std::uint32_t brrO	      = 0x08;  // Usart .... register offset
	const std::uint32_t cr1O	      = 0x0C;  // Usart .... register offset
	const std::uint32_t cr2O            = 0x010; // Usart .... register offset
	const std::uint32_t cr3O            = 0x014; // Usart .... register offset
			
/**************************************** Port Registers Adresses - End ****************************************/
//
//
//
/******************************************** Port A  Adresses - Begin *****************************************/

      const std::uint32_t gpioaModer     = gpioaB      +  moderO;  
      const std::uint32_t gpioaOtyper    = gpioaB      +  otyperO;  
      const std::uint32_t gpioaOspeedr   = gpioaB      +  ospeedrO;  
      const std::uint32_t gpioaPupdr     = gpioaB      +  pupdrO;  
      const std::uint32_t gpioaIdr       = gpioaB      +  idrO;  
      const std::uint32_t gpioaOdr       = gpioaB      +  odrO;  
      const std::uint32_t gpioaBsrr      = gpioaB      +  bsrrO;  
      const std::uint32_t gpioaLckr      = gpioaB      +  lckrO;  
      const std::uint32_t gpioaAfrl      = gpioaB      +  afrlO;  
      const std::uint32_t gpioaAfrh      = gpioaB      +  afrhO;  
			
/******************************************** Port A  Adresses - End *****************************************/
//
//
//
/******************************************** Port B  Adresses - Begin *****************************************/

      const std::uint32_t gpiobModer     = gpiobB      +  moderO;  
      const std::uint32_t gpiobOtyper    = gpiobB      +  otyperO;  
      const std::uint32_t gpiobOspeedr   = gpiobB      +  ospeedrO;  
      const std::uint32_t gpiobPupdr     = gpiobB      +  pupdrO;  
      const std::uint32_t gpiobIdr       = gpiobB      +  idrO;  
      const std::uint32_t gpiobOdr       = gpiobB      +  odrO;  
      const std::uint32_t gpiobBsrr      = gpiobB      +  bsrrO;  
      const std::uint32_t gpiobLckr      = gpiobB      +  lckrO;  
      const std::uint32_t gpiobAfrl      = gpiobB      +  afrlO;  
      const std::uint32_t gpiobAfrh      = gpiobB      +  afrhO;  
			
/******************************************** Port B  Adresses - End *****************************************/
//
//
//
/******************************************** Port C  Adresses - Begin *****************************************/

      const std::uint32_t gpiocModer     = gpiocB      +  moderO;  
      const std::uint32_t gpiocOtyper    = gpiocB      +  otyperO;  
      const std::uint32_t gpiocOspeedr   = gpiocB      +  ospeedrO;  
      const std::uint32_t gpiocPupdr     = gpiocB      +  pupdrO;  
      const std::uint32_t gpiocIdr       = gpiocB      +  idrO;  
      const std::uint32_t gpiocOdr       = gpiocB      +  odrO;  
      const std::uint32_t gpiocBsrr      = gpiocB      +  bsrrO;  
      const std::uint32_t gpiocLckr      = gpiocB      +  lckrO;  
      const std::uint32_t gpiocAfrl      = gpiocB      +  afrlO;  
      const std::uint32_t gpiocAfrh      = gpiocB      +  afrhO;  
			
/******************************************** Port C  Adresses - End *****************************************/
//
//
//
/******************************************** Port D  Adresses - Begin *****************************************/

      const std::uint32_t gpiodModer     = gpiodB      +  moderO;  
      const std::uint32_t gpiodOtyper    = gpiodB      +  otyperO;  
      const std::uint32_t gpiodOspeedr   = gpiodB      +  ospeedrO;  
      const std::uint32_t gpiodPupdr     = gpiodB      +  pupdrO;  
      const std::uint32_t gpiodIdr       = gpiodB      +  idrO;  
      const std::uint32_t gpiodOdr       = gpiodB      +  odrO;  
      const std::uint32_t gpiodBsrr      = gpiodB      +  bsrrO;  
      const std::uint32_t gpiodLckr      = gpiodB      +  lckrO;  
      const std::uint32_t gpiodAfrl      = gpiodB      +  afrlO;  
      const std::uint32_t gpiodAfrh      = gpiodB      +  afrhO;  
			
/******************************************** Port D  Adresses - End *****************************************/
//
//
//
/******************************************** Port E  Adresses - Begin *****************************************/

      const std::uint32_t gpioeModer     = gpioeB      +  moderO;  
      const std::uint32_t gpioeOtyper    = gpioeB      +  otyperO;  
      const std::uint32_t gpioeOspeedr   = gpioeB      +  ospeedrO;  
      const std::uint32_t gpioePupdr     = gpioeB      +  pupdrO;  
      const std::uint32_t gpioeIdr       = gpioeB      +  idrO;  
      const std::uint32_t gpioeOdr       = gpioeB      +  odrO;  
      const std::uint32_t gpioeBsrr      = gpioeB      +  bsrrO;  
      const std::uint32_t gpioeLckr      = gpioeB      +  lckrO;  
      const std::uint32_t gpioeAfrl      = gpioeB      +  afrlO;  
      const std::uint32_t gpioeAfrh      = gpioeB      +  afrhO;  
			
/******************************************** Port E  Adresses - End *****************************************/
//
//
//
/******************************************** Port F  Adresses - Begin *****************************************/

      const std::uint32_t gpiofModer     = gpiofB      +  moderO;  
      const std::uint32_t gpiofOtyper    = gpiofB      +  otyperO;  
      const std::uint32_t gpiofOspeedr   = gpiofB      +  ospeedrO;  
      const std::uint32_t gpiofPupdr     = gpiofB      +  pupdrO;  
      const std::uint32_t gpiofIdr       = gpiofB      +  idrO;  
      const std::uint32_t gpiofOdr       = gpiofB      +  odrO;  
      const std::uint32_t gpiofBsrr      = gpiofB      +  bsrrO;  
      const std::uint32_t gpiofLckr      = gpiofB      +  lckrO;  
      const std::uint32_t gpiofAfrl      = gpiofB      +  afrlO;  
      const std::uint32_t gpiofAfrh      = gpiofB      +  afrhO; 
			
/******************************************** Port F  Adresses - End *****************************************/
//
//
//
/******************************************** Port G  Adresses - Begin *****************************************/

      const std::uint32_t gpiogModer     = gpiogB      +  moderO;  
      const std::uint32_t gpiogOtyper    = gpiogB      +  otyperO;  
      const std::uint32_t gpiogOspeedr   = gpiogB      +  ospeedrO;  
      const std::uint32_t gpiogPupdr     = gpiogB      +  pupdrO;  
      const std::uint32_t gpiogIdr       = gpiogB      +  idrO;  
      const std::uint32_t gpiogOdr       = gpiogB      +  odrO;  
      const std::uint32_t gpiogBsrr      = gpiogB      +  bsrrO;  
      const std::uint32_t gpiogLckr      = gpiogB      +  lckrO;  
      const std::uint32_t gpiogAfrl      = gpiogB      +  afrlO;  
      const std::uint32_t gpiogAfrh      = gpiogB      +  afrhO;  
			
/******************************************** Port G  Adresses - End *****************************************/
//
//
//
/******************************************** Usart2 Register - Begin *****************************************/

	const std::uint32_t usart2Sr       = usart2B + srO;
	const std::uint32_t usart2Dr       = usart2B + drO;
	const std::uint32_t usart2Brr      = usart2B + brrO;
	const std::uint32_t usart2Cr1      = usart2B + cr1O;
	const std::uint32_t usart2Cr2      = usart2B + cr2O;
	const std::uint32_t usart2Cr3      = usart2B + cr3O;
			
/******************************************** Usart Register - End ******************************************/

/*

typedef struct{
	volatile std::uint32_t sr;          USART Status register,                   Address offset: 0x00
	volatile std::uint32_t dr;          USART Data register,                     Address offset: 0x04
	volatile std::uint32_t brr;         USART Baud rate register,                Address offset: 0x08
	volatile std::uint32_t cr1;         USART Control register 1,                Address offset: 0x0C
	volatile std::uint32_t cr2;         USART Control register 2,                Address offset: 0x10
	volatile std::uint32_t cr3;         USART Control register 3,                Address offset: 0x14
} UART;

UART* UART2 = (UART *)usart2B;
*/

#endif
