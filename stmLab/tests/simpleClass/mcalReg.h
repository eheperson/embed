#include<cstdint>
/*
		 nucleobord led is connected to PA5
		 on ARM size of int is 32 bit so use uint32_t (not int)
-----------------------------------------------------------------------
		GPIOA is connected to AHB1
		to use GPIOA we have to enable AHP1
						check page 118 - RM0368 Reference manual
		
		GPIOA = AHB1
		GPIOA = 0x4002 0000
		LED = PA5
		MODE REG Offset = 0x00
		ODR Offset = 0x14
		RCC Offset = 0x30
		AHB1ENER = AHB1 + RCC + 0x30
		
		reset values 	:
			0xA800 0000 for PortA
			0x0000 0280 for PortB
			0x0000 0000 for other ports
			
			GPOx_MODER : check RM0368 
												 Reference manual
												 page 158			
-----------------------------------------------------------------------
 				|= : logical or, used to enable bit in a pin
						 0000 - initial state of GPIOA
						 0010 - bval
						 0010 - GPIOA |= bval 
			
				&= : logical and, used to disable bit in a pin
						 1111 - initial state of GPIOA
						 1101 - bval
						 1101 - GPIOA |= bval 
				<< : Logical shift
						 (1U << 8 ) - shift 1 to position 8 :  00000000 00000000 00000001 00000000
						 ~(1U<<9) - flip everything, use it to disable pin : 11111111 11111111 11111101 11111111
*/
namespace mcal{
	namespace reg{
		const uint32_t gpioa = 0x40020014;
		const std::uint32_t gpioa_pin5 = 5;
		const std::uint32_t gpioa_pin6 = 6;
	}	
}

