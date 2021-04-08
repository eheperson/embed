#ifndef _MEMORYMAP_H_
#define _MEMORYMAP_H_
/**/
#include <cstdint>
/**/
/**/
/****************************************** Global Base Adresses - Begin ******************************************/
const std::uint32_t periphB         =  0x40000000U; //peripheral base adress
/****************************************** Global Base Adresses - End ********************************************/
/**/
/**/
/**/
/************************************** Indivicual Unit Base Adresses - Begin *************************************/
const std::uint32_t ahb1PeriphB     = periphB     + 0x00020000U;
const std::uint32_t rccB            = ahb1PeriphB + 0x00003800U;
/**/
const std::uint32_t ahb1Enr         =	rccB + 0x30;
const std::uint32_t ahb2Enr         =	rccB + 0x34;
const std::uint32_t ahb3Enr 	      =	rccB + 0x38;
const std::uint32_t apb1Enr	      = rccB + 0x40;
/**/
const std::uint32_t gpioaB          = ahb1PeriphB +  0x0000;
const std::uint32_t gpiobB          = ahb1PeriphB +  0x0400;
const std::uint32_t gpiocB          = ahb1PeriphB +  0x0800;
const std::uint32_t gpiodB          = ahb1PeriphB +  0x0C00;
const std::uint32_t gpioeB          = ahb1PeriphB +  0x1000;
const std::uint32_t gpiofB          = ahb1PeriphB +  0x1400;
const std::uint32_t gpiogB          = ahb1PeriphB +  0x1800;
/**/
const std::uint32_t usart1B         = 0x4001100U;
const std::uint32_t usart2B         = 0x40004400;
const std::uint32_t usart6B         = 0x4001140U;
/**/
const std::uint32_t scbB        =  0xE000E000U;
const std::uint32_t systickB 		= scbB + 0x010U; //sysTick Base Adress
/**/
const std::uint32_t tim1B  = 0x40010000;
const std::uint32_t tim2B  = periphB;
const std::uint32_t tim3B  = 0x40000400;
const std::uint32_t tim4B  = 0x40000800;
const std::uint32_t tim5B  = 0x40000C00;
const std::uint32_t tim9B  = 0x40014000;
const std::uint32_t tim10B = 0x40014400;
const std::uint32_t tim11B = 0x40014800;
/************************************** Indivicual Unit Base Adresses - End *************************************/
/**/
/**/
/**/
/**************************************** PortX Registers Offsets - Begin ***************************************/
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
/**************************************** PortX Registers Offsets - End ****************************************/
/**/
/**/
/**/
/******************************************** PortX  Adresses - Begin *****************************************/
/************ Port A Register Map - Begin ************/
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
/************ Port A Register Map - End ************/
/**/
/************ Port B Register Map - Begin ************/
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
/************ Port B Register Map - End ************/
/**/
/************ Port C Register Map - Begin ************/
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
/************ Port C Register Map - End ************/
/**/
/************ Port D Register Map - Begin ************/
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
/************ Port D Register Map - End ************/
/**/
/************ Port E Register Map - Begin ************/
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
/************ Port E Register Map - End ************/
/**/
/************ Port F Register Map - Begin ************/
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
/************ Port F Register Map - End ************/
/**/
/************ Port G Register Map - Begin ************/
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
/************ Port G Register Map - End ************/
/******************************************** PortX  Adresses - End *****************************************/
/**/
/**/
/**/
/******************************************** Usart2 Register - Begin *****************************************/
const std::uint32_t srO  	      	= 0x00;  // Usart status Register Offset 
const std::uint32_t drO	          = 0x04;  // Usart data register offset
const std::uint32_t brrO	      	= 0x08;  // Usart .... register offset
const std::uint32_t cr1O	      	= 0x0C;  // Usart .... register offset
const std::uint32_t cr2O          = 0x010; // Usart .... register offset
const std::uint32_t cr3O          = 0x014; // Usart .... register offset
/**/
const std::uint32_t usart2Sr     	= usart2B + srO;
const std::uint32_t usart2Dr      = usart2B + drO;
const std::uint32_t usart2Brr     = usart2B + brrO;
const std::uint32_t usart2Cr1     = usart2B + cr1O;
const std::uint32_t usart2Cr2     = usart2B + cr2O;
const std::uint32_t usart2Cr3     = usart2B + cr3O;
/**/		
/*
typedef struct{
	volatile std::uint32_t sr;          USART Status register,                   Address offset: 0x00
	volatile std::uint32_t dr;          USART Data register,                     Address offset: 0x04
	volatile std::uint32_t brr;         USART Baud rate register,                Address offset: 0x08
	volatile std::uint32_t cr1;         USART Control register 1,                Address offset: 0x0C
	volatile std::uint32_t cr2;         USART Control register 2,                Address offset: 0x10
	volatile std::uint32_t cr3;         USART Control register 3,                Address offset: 0x14
} UART;
*/
/******************************************** Usart Register - End ******************************************/
/**/
/**/
/**/
/******************************************** SysTick Register - Begin *****************************************/
/**/
const std::uint32_t csrO					=  0x000;
const std::uint32_t rvrO					=  0x004; 
const std::uint32_t cvrO				  =  0x008;
const std::uint32_t calibO				=  0x00C;
/**/
const std::uint32_t systickCsr   =  systickB + csrO; //SysTick  Control and Status Register
const std::uint32_t systickRvr 	=  systickB + rvrO; //SysTick Reload Value Register
const std::uint32_t systickCvr 		=  systickB + cvrO; // SysTick Current Value Register
const std::uint32_t systickCalib 	=  systickB + calibO; //SysTick Calibration Value Register
/**/
/*
typedef struct{
	volatile std::uint32_t  CTRL;
	volatile std::uint32_t  LOAD;
	volatile std::uint32_t  VAL;
	volatile std::uint32_t  CALIB;
}SYSTICK;
*/				
/******************************************** SysTick Register - End *****************************************/
/**/
/**/
/**/
/******************************************** TimerX Registers - Begin *****************************************/
/** TIM2 to TIM5 register offsets map **/
const std::uint32_t timXcr1O 		= 0x00;		//Timerx Control Register 1 Offset
const std::uint32_t timXcr2O 		= 0x04;		//TimerX Control Register 2 Offset
const std::uint32_t timXsmcrO 	= 0x08;		//TimerX Slave Mode Control Register Offset 
const std::uint32_t timXdierO 	= 0x0C;		// TimerX DMA/Interrupt Enable Register Offset
const std::uint32_t timXsrO 		= 0x10;		//TimerX Status Register Offset
const std::uint32_t timXegrO 		= 0x14;		//TimerX Event Generation Register Offset 
const std::uint32_t timXccmr1O 	= 0x18;		//TimerX Capture/Compare Register 1 Offset
const std::uint32_t timXccmr2O 	= 0x1C;		//TimerX Capture/Compare Register 2 Offset
const std::uint32_t timXccerO 	= 0x20;		//TimerX Capture/Compare Enable Register Offset
const std::uint32_t timXcntO  	= 0x24;		//TimerX Counter Register Offset
const std::uint32_t timXpscO 		= 0x28;		//TimerX Prescaler Register Offset
const std::uint32_t timXarrO 		= 0x2C;		//TimerX Auto-Reload Register Offset
const std::uint32_t timXccr1O 	= 0x34;		//TimerX Capture/Compare Register 1 Offset
const std::uint32_t timXccr2O 	= 0x38;		//TimerX Capture/Compare Register 2 Offset
const std::uint32_t timXccr3O 	= 0x3C;		//TimerX Capture/Compare Register 3 Offset
const std::uint32_t timXccr4O 	= 0x40;		//TimerX Capture/Compare Register 4 Offset
const std::uint32_t timXdcrO 		= 0x48;		//TimerX DMA Control Register Offset
const std::uint32_t timXdmarO 	= 0x4C;		//TimerX DMA Adress Register Offset (For Full Transfer) 
const std::uint32_t timXorO 		= 0x50;		//TimerX Option Register Offset
/**/
/*************** TIM2 Register Map - Begin ***************/
const std::uint32_t tim2CR1 	= tim2B + timXcr1O;		//Timer2 Control Register 1 
const std::uint32_t tim2CR2 	= tim2B + timXcr2O;		//Timer2 Control Register 2 
const std::uint32_t tim2SMCR 	= tim2B + timXsmcrO;	//Timer2 Slave Mode Control Register 
const std::uint32_t tim2DIER 	= tim2B + timXdierO;	// Timer2 DMA/Interrupt Enable Register 
const std::uint32_t tim2SR 		= tim2B + timXsrO;		//Timer2 Status Register 
const std::uint32_t tim2EGR 	= tim2B + timXegrO;		//Timer2 Event Generation Register 
const std::uint32_t tim2CCMR1 = tim2B + timXccmr1O;	//Timer2 Capture/Compare Register 1 
const std::uint32_t tim2CCMR2 = tim2B + timXccmr2O;	//Timer2 Capture/Compare Register 2 
const std::uint32_t tim2CCER 	= tim2B + timXccerO;	//Timer2 Capture/Compare Enable Register 
const std::uint32_t tim2CNT  	= tim2B + timXcntO;		//Timer2 Counter Register 
const std::uint32_t tim2PSC 	= tim2B + timXpscO;		//Timer2 Prescaler Register 
const std::uint32_t tim2ARR 	= tim2B + timXarrO;		//Timer2 Auto-Reload Register 
const std::uint32_t tim2CCR1 	= tim2B + timXccr1O;	//Timer2 Capture/Compare Register 1 
const std::uint32_t tim2CCR2 	= tim2B + timXccr2O;	//Timer2 Capture/Compare Register 2 
const std::uint32_t tim2CCR3 	= tim2B + timXccr3O;	//Timer2 Capture/Compare Register 3 
const std::uint32_t tim2CCR4 	= tim2B + timXccr4O;	//Timer2 Capture/Compare Register 4 
const std::uint32_t tim2DCR 	= tim2B + timXdcrO;		//Timer2 DMA Control Register 
const std::uint32_t tim2DMAR 	= tim2B + timXdmarO;	//Timer2 DMA Adress Register  (For Full Transfer) 
const std::uint32_t tim2OR		= tim2B + timXorO;		//Timer2 Option Register 
/*************** TIM2 Register Map - End ***************/
/**/
/*************** TIM3 Register Map - Begin ***************/
const std::uint32_t tim3CR1 	= tim3B + timXcr1O;  	//Timer3 Control Register 1 
const std::uint32_t tim3CR2 	= tim3B + timXcr2O; 	//Timer3 Control Register 2 
const std::uint32_t tim3SMCR 	= tim3B + timXsmcrO; 	//Timer3 Slave Mode Control Register 
const std::uint32_t tim3DIER 	= tim3B + timXdierO; 	// Timer3 DMA/Interrupt Enable Register 
const std::uint32_t tim3SR 		= tim3B + timXsrO; 		//Timer3 Status Register 
const std::uint32_t tim3EGR 	= tim3B + timXegrO; 	//Timer3 Event Generation Register 
const std::uint32_t tim3CCMR1 = tim3B + timXccmr1O;	//Timer3 Capture/Compare Register 1 
const std::uint32_t tim3CCMR2 = tim3B + timXccmr2O;	//Timer3 Capture/Compare Register 2 
const std::uint32_t tim3CCER 	= tim3B + timXccerO;	//Timer3 Capture/Compare Enable Register 
const std::uint32_t tim3CNT  	= tim3B + timXcntO;		//Timer3 Counter Register 
const std::uint32_t tim3PSC 	= tim3B + timXpscO;		//Timer3 Prescaler Register 
const std::uint32_t tim3ARR 	= tim3B + timXarrO;		//Timer3 Auto-Reload Register 
const std::uint32_t tim3CCR1 	= tim3B + timXccr1O;	//Timer3 Capture/Compare Register 1 
const std::uint32_t tim3CCR2 	= tim3B + timXccr2O;	//Timer3 Capture/Compare Register 2 
const std::uint32_t tim3CCR3 	= tim3B + timXccr3O;	//Timer3 Capture/Compare Register 3 
const std::uint32_t tim3CCR4 	= tim3B + timXccr4O;	//Timer3 Capture/Compare Register 4 
const std::uint32_t tim3DCR 	= tim3B + timXdcrO;		//Timer3 DMA Control Register 
const std::uint32_t tim3DMAR 	= tim3B + timXdmarO;	//Timer3 DMA Adress Register  (For Full Transfer) 
const std::uint32_t tim3OR		= tim3B + timXorO;		//Timer3 Option Register 
/*************** TIM3 Register Map - End ***************/
/**/
/*************** TIM4 Register Map - Begin ***************/
const std::uint32_t tim4CR1 	= tim4B + timXcr1O;  	//Timer3 Control Register 1 
const std::uint32_t tim4CR2 	= tim4B + timXcr2O; 	//Timer3 Control Register 2 
const std::uint32_t tim4SMCR 	= tim4B + timXsmcrO; 	//Timer3 Slave Mode Control Register 
const std::uint32_t tim4DIER 	= tim4B + timXdierO; 	// Timer3 DMA/Interrupt Enable Register 
const std::uint32_t tim4SR 		= tim4B + timXsrO; 		//Timer3 Status Register 
const std::uint32_t tim4EGR 	= tim4B + timXegrO; 	//Timer3 Event Generation Register 
const std::uint32_t tim4CCMR1 = tim4B + timXccmr1O;	//Timer3 Capture/Compare Register 1 
const std::uint32_t tim4CCMR2 = tim4B + timXccmr2O;	//Timer3 Capture/Compare Register 2 
const std::uint32_t tim4CCER 	= tim4B + timXccerO;	//Timer3 Capture/Compare Enable Register 
const std::uint32_t tim4CNT  	= tim4B + timXcntO;		//Timer3 Counter Register 
const std::uint32_t tim4PSC 	= tim4B + timXpscO;		//Timer3 Prescaler Register 
const std::uint32_t tim4ARR 	= tim4B + timXarrO;		//Timer3 Auto-Reload Register 
const std::uint32_t tim4CCR1 	= tim4B + timXccr1O;	//Timer3 Capture/Compare Register 1 
const std::uint32_t tim4CCR2 	= tim4B + timXccr2O;	//Timer3 Capture/Compare Register 2 
const std::uint32_t tim4CCR3 	= tim4B + timXccr3O;	//Timer3 Capture/Compare Register 3 
const std::uint32_t tim4CCR4 	= tim4B + timXccr4O;	//Timer3 Capture/Compare Register 4 
const std::uint32_t tim4DCR 	= tim4B + timXdcrO;		//Timer3 DMA Control Register 
const std::uint32_t tim4DMAR 	= tim4B + timXdmarO;	//Timer3 DMA Adress Register  (For Full Transfer) 
const std::uint32_t tim4OR		= tim4B + timXorO;		//Timer3 Option Register 
/*************** TIM4 Register Map - End ***************/
/**/
/*************** TIM5 Register Map - Begin ***************/
const std::uint32_t tim5CR1 	= tim5B + timXcr1O;  	//Timer3 Control Register 1 
const std::uint32_t tim5CR2 	= tim5B + timXcr2O; 	//Timer3 Control Register 2 
const std::uint32_t tim5SMCR 	= tim5B + timXsmcrO; 	//Timer3 Slave Mode Control Register 
const std::uint32_t tim5DIER 	= tim5B + timXdierO; 	// Timer3 DMA/Interrupt Enable Register 
const std::uint32_t tim5SR 		= tim5B + timXsrO; 		//Timer3 Status Register 
const std::uint32_t tim5EGR 	= tim5B + timXegrO; 	//Timer3 Event Generation Register 
const std::uint32_t tim5CCMR1 = tim5B + timXccmr1O;	//Timer3 Capture/Compare Register 1 
const std::uint32_t tim5CCMR2 = tim5B + timXccmr2O;	//Timer3 Capture/Compare Register 2 
const std::uint32_t tim5CCER 	= tim5B + timXccerO;	//Timer3 Capture/Compare Enable Register 
const std::uint32_t tim5CNT  	= tim5B + timXcntO;		//Timer3 Counter Register 
const std::uint32_t tim5PSC 	= tim5B + timXpscO;		//Timer3 Prescaler Register 
const std::uint32_t tim5ARR 	= tim5B + timXarrO;		//Timer3 Auto-Reload Register 
const std::uint32_t tim5CCR1 	= tim5B + timXccr1O;	//Timer3 Capture/Compare Register 1 
const std::uint32_t tim5CCR2 	= tim5B + timXccr2O;	//Timer3 Capture/Compare Register 2 
const std::uint32_t tim5CCR3 	= tim5B + timXccr3O;	//Timer3 Capture/Compare Register 3 
const std::uint32_t tim5CCR4 	= tim5B + timXccr4O;	//Timer3 Capture/Compare Register 4 
const std::uint32_t tim5DCR 	= tim5B + timXdcrO;		//Timer3 DMA Control Register 
const std::uint32_t tim5DMAR 	= tim5B + timXdmarO;	//Timer3 DMA Adress Register  (For Full Transfer) 
const std::uint32_t tim5OR		= tim5B + timXorO;		//Timer3 Option Register 
/*************** TIM5 Register Map - End ***************/
/**/
typedef struct{
	volatile std::uint32_t CR1;         // TIM control register 1,              Address offset: 0x00 
	volatile std::uint32_t CR2;         // TIM control register 2,              Address offset: 0x04 
	volatile std::uint32_t SMCR;        // TIM slave mode control register,     Address offset: 0x08 
	volatile std::uint32_t DIER;        // TIM DMA/interrupt enable register,   Address offset: 0x0C 
	volatile std::uint32_t SR;          // TIM status register,                 Address offset: 0x10 
	volatile std::uint32_t EGR;         // TIM event generation register,       Address offset: 0x14 
	volatile std::uint32_t CCMR1;       // TIM capture/compare mode register 1, Address offset: 0x18 
	volatile std::uint32_t CCMR2;       // TIM capture/compare mode register 2, Address offset: 0x1C 
	volatile std::uint32_t CCER;        // TIM capture/compare enable register, Address offset: 0x20 
	volatile std::uint32_t CNT;         // TIM counter register,                Address offset: 0x24 
	volatile std::uint32_t PSC;         // TIM prescaler,                       Address offset: 0x28 
	volatile std::uint32_t ARR;         // TIM auto-reload register,            Address offset: 0x2C 
	volatile std::uint32_t RCR;         // TIM repetition counter register,     Address offset: 0x30 
	volatile std::uint32_t CCR1;        // TIM capture/compare register 1,      Address offset: 0x34 
	volatile std::uint32_t CCR2;        // TIM capture/compare register 2,      Address offset: 0x38 
	volatile std::uint32_t CCR3;        // TIM capture/compare register 3,      Address offset: 0x3C 
	volatile std::uint32_t CCR4;        // TIM capture/compare register 4,      Address offset: 0x40 
	volatile std::uint32_t BDTR;        // TIM break and dead-time register,    Address offset: 0x44 
	volatile std::uint32_t DCR;         // TIM DMA control register,            Address offset: 0x48 
	volatile std::uint32_t DMAR;        // TIM DMA address for full transfer,   Address offset: 0x4C 
	volatile std::uint32_t OR;          //TIM option register,                  Address offset: 0x50 
} TIMx;
/******************************************** Timer2 Register - End *****************************************/
#endif



