#include "memoryMap.h"
#include "uartDriver.h"
#include "timerDriver.h"
#include "digital.h"

int main(){
	
	
	uartInitRTx();
	//systickOneSec();
	gpioaInitLed();
	//tim2OneHz();
	tim5OneHz();
	char ch;
	int systicFlag = 0;
while(1){
		/*
		systicFlag = getCountFlag();
			
		if(systicFlag)	{
			printf(" ehe ! \r\n");
			ledToggle();
			
		}
		*/
		printf("--- e n i v i c i v o k k i ---\r\n");
		ledToggle();
		tim5Timeout();
		/*
		systickMsDelay(100);
		printf(" ehe ! \r\n");
		ledToggle();
		*/
	}
	
	return 0;
}

