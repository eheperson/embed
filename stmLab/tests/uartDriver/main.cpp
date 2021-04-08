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






int main(){
	uartInit();
	
	while(1){
		uartWrite('Y');
		//or we can use just
		//std::cout << "Hello motherfuckers \r\n";
		//printf("enivicivokki \r\n");
		
		for(int i = 1; i<180000; i++){}
	}
	return 0;
}
