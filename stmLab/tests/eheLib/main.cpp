#include "memoryMap.h"
#include "uartDriver.h"

int main(){
	
	uartInitTx();
	
	while(1){
	
		uartWriteTx('q');
		for(int i=0;i<180000;i++){}
	}
	
	return 0;
}

