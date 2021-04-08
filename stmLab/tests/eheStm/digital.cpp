#include "memoryMap.h"

void gpioaInitLed(void){
	//Enable clock for GPIOA
	*reinterpret_cast<volatile std::uint32_t*>(ahb1Enr) |=static_cast<std::uint32_t>((1U<<0));
	//Set PA5 to output
	*reinterpret_cast<volatile std::uint32_t*>(gpioaModer) |=static_cast<std::uint32_t>(1U<<10);
}

void ledOn(){
	// Will be declared
}



void ledOff(){
	// Will be declared
}

void ledToggle(){

	
	// Toggle built-in led
	*reinterpret_cast<volatile std::uint32_t*>(gpioaOdr) ^= static_cast<std::uint32_t>(1U<<5);
}

