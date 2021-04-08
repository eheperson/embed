#include "timerDriver.h"




 
/**************************************** SysTick Based Timer Functions - Begin ****************************************/

void  systickOne(void){
	//sysclock @  16mHz
	*reinterpret_cast<volatile std::uint32_t*>(systickRvr) = static_cast<std::uint32_t>(16000000-1);

	*reinterpret_cast<volatile std::uint32_t*>(systickCvr) = static_cast<std::uint32_t>(0);

  *reinterpret_cast<volatile std::uint32_t*>(systickCsr) = static_cast<std::uint32_t>(5);//enabl systick, use system clock, no interrupt
 

}

void  systicDot5sec(void){
	*reinterpret_cast<volatile std::uint32_t*>(systickRvr) = static_cast<std::uint32_t>(8000000-1);

	*reinterpret_cast<volatile std::uint32_t*>(systickCvr) = static_cast<std::uint32_t>(0);

  *reinterpret_cast<volatile std::uint32_t*>(systickCsr) = static_cast<std::uint32_t>(5);//enabl systick, use system clock, no interrupt
 

}

 int countFlag(void){

	return *reinterpret_cast<volatile std::uint32_t*>(systickCsr) & 0x10000;
	 /*  Ekample use of systic count flag 
		systicFlag = getCountFlag();
			
		if(systicFlag)	{
			printf(" ehe ! \r\n");
			ledToggle();
			
		}*/
}
 




void systickMsDelay(std::uint32_t delay){

	*reinterpret_cast<volatile std::uint32_t*>(systickRvr) = static_cast<std::uint32_t>(16000-1);

	*reinterpret_cast<volatile std::uint32_t*>(systickCvr) = static_cast<std::uint32_t>(0);

  *reinterpret_cast<volatile std::uint32_t*>(systickCsr) = static_cast<std::uint32_t>(5);  //enabl systick, use system clock, no interrupt

	
	for(int i=0;i<delay;i++){
		
	 /*Wit until count flag is set*/
		 while(!(*reinterpret_cast<volatile std::uint32_t*>(systickCsr) & 0x10000)){}
	}
	
	 /*stop timer by writing 0 to control and status reg*/

	 *reinterpret_cast<volatile std::uint32_t*>(systickCsr) = static_cast<std::uint32_t>(0);

}
/**************************************** SysTick Based Timer Functions - End ****************************************/
/**/
/**/
/**/
/**************************************** Timer2 Based Timer Functions - Begin ****************************************/

void tim2OneHz(void){

   //Enable clock to TIM2
	*reinterpret_cast<volatile std::uint32_t*>(apb1Enr) |= static_cast<std::uint32_t>(1U<<0);
	
	/*16 000 000 /1600 = 10000*/
	 *reinterpret_cast<volatile std::uint32_t*>(tim2PSC) =static_cast<std::uint32_t>(1600-1);
	
  /*10000/10000 =1*/
	*reinterpret_cast<volatile std::uint32_t*>(tim2ARR) =static_cast<std::uint32_t>(10000-1);

	
  //Clear timer counter 
	*reinterpret_cast<volatile std::uint32_t*>(tim2CNT) =static_cast<std::uint32_t>(0);
	
	//Enable Timer
	*reinterpret_cast<volatile std::uint32_t*>(tim2CR1) =static_cast<std::uint32_t>(1U<<0);



}

void tim2Timeout(void){
 
	
	 //Wait until UIF is set
	while(!(*reinterpret_cast<volatile std::uint32_t*>(tim2SR) & 0x1)){}
	 //Claer UIF
	*reinterpret_cast<volatile std::uint32_t*>(tim2SR) &= static_cast<std::uint32_t>(~1);

}
/**************************************** Timer2 Based Timer Functions - End ****************************************/
/**/
/**/
/**/
/**************************************** Timer3 Based Timer Functions - Begin ****************************************/

void tim3OneHz(void){

   //Enable clock to TIM3
	*reinterpret_cast<volatile std::uint32_t*>(apb1Enr) |= static_cast<std::uint32_t>(1U<<1);
	
	/*16 000 000 /1600 = 10000*/
	 *reinterpret_cast<volatile std::uint32_t*>(tim3PSC) =static_cast<std::uint32_t>(1600-1);
	
  /*10000/10000 =1*/
	*reinterpret_cast<volatile std::uint32_t*>(tim3ARR) =static_cast<std::uint32_t>(10000-1);

	
  //Clear timer counter 
	*reinterpret_cast<volatile std::uint32_t*>(tim3CNT) =static_cast<std::uint32_t>(0);
	
	//Enable Timer
	*reinterpret_cast<volatile std::uint32_t*>(tim3CR1) =static_cast<std::uint32_t>(1U<<0);



}

void tim3Timeout(void){
 
	
	 //Wait until UIF is set
	while(!(*reinterpret_cast<volatile std::uint32_t*>(tim3SR) & 0x1)){}
	 //Claer UIF
	*reinterpret_cast<volatile std::uint32_t*>(tim3SR) &= static_cast<std::uint32_t>(~1);

}
/**************************************** Timer3 Based Timer Functions - End ****************************************/
/**/
/**/
/**/
/**************************************** Timer4 Based Timer Functions - Begin ****************************************/

void tim4OneHz(void){

   //Enable clock to TIM3
	*reinterpret_cast<volatile std::uint32_t*>(apb1Enr) |= static_cast<std::uint32_t>(1U<<2);
	
	/*16 000 000 /1600 = 10000*/
	 *reinterpret_cast<volatile std::uint32_t*>(tim4PSC) =static_cast<std::uint32_t>(1600-1);
	
  /*10000/10000 =1*/
	*reinterpret_cast<volatile std::uint32_t*>(tim4ARR) =static_cast<std::uint32_t>(10000-1);

	
  //Clear timer counter 
	*reinterpret_cast<volatile std::uint32_t*>(tim4CNT) =static_cast<std::uint32_t>(0);
	
	//Enable Timer
	*reinterpret_cast<volatile std::uint32_t*>(tim4CR1) =static_cast<std::uint32_t>(1U<<0);



}

void tim4Timeout(void){
 
	
	 //Wait until UIF is set
	while(!(*reinterpret_cast<volatile std::uint32_t*>(tim4SR) & 0x1)){}
	 //Claer UIF
	*reinterpret_cast<volatile std::uint32_t*>(tim4SR) &= static_cast<std::uint32_t>(~1);

}
/**************************************** Timer4 Based Timer Functions - End ****************************************/
/**/
/**/
/**/
/**************************************** Timer4 Based Timer Functions - Begin ****************************************/

void tim5OneHz(void){

   //Enable clock to TIM3
	*reinterpret_cast<volatile std::uint32_t*>(apb1Enr) |= static_cast<std::uint32_t>(1U<<3);
	
	/*16 000 000 /1600 = 10000*/
	 *reinterpret_cast<volatile std::uint32_t*>(tim5PSC) =static_cast<std::uint32_t>(1600-1);
	
  /*10000/10000 =1*/
	*reinterpret_cast<volatile std::uint32_t*>(tim5ARR) =static_cast<std::uint32_t>(10000-1);

	
  //Clear timer counter 
	*reinterpret_cast<volatile std::uint32_t*>(tim5CNT) =static_cast<std::uint32_t>(0);
	
	//Enable Timer
	*reinterpret_cast<volatile std::uint32_t*>(tim5CR1) =static_cast<std::uint32_t>(1U<<0);



}

void tim5Timeout(void){
 
	
	 //Wait until UIF is set
	while(!(*reinterpret_cast<volatile std::uint32_t*>(tim5SR) & 0x1)){}
	 //Claer UIF
	*reinterpret_cast<volatile std::uint32_t*>(tim5SR) &= static_cast<std::uint32_t>(~1);

}
/**************************************** Timer4 Based Timer Functions - End ****************************************/






