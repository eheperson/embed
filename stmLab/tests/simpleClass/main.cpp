#include"mcalReg.h"


//
// create a register in c language version : add to base adress of GPIOx
//#define RCC_AHB1ENR 0x4002 0000 + 3800 + 30
#define RCC_AHB1ENR (*((volatile unsigned int *) 0x40023830))
//#define GPIOA_MODER : same as the base adress of gpioa
#define GPIOA_MODER (*((volatile unsigned int *) 0x40020000))
//#define	GPIOA_ODR 0x4002 0000 + 0014
#define GPIOA_ODR (*((volatile unsigned int *)0x40020014))
//
//
//create a register in c++ language version
// use reinterpret_cast
//
//
class Led{
	public:
		typedef std::uint32_t port_type; //00000000 00000000 00000000 00000000 : port_type
		typedef std::uint32_t bval_type; //00000000 00000000 00000000 00000000 : bval_type
	
		Led(const port_type p, bval_type b):port(p), bval(b){
			
			// *((volatile uint32_t*)GPIOB) = (uint32_t)bval; //that is for c language
			
			/* Disable Pin 
			
			   port_initial						   = 1111010
			   (1U << 1)   				 		   = 0000010 
			   ~(1U << 1)   						 = 1111101 
			   port_initial & ~(1U << 1) = 1111000			
			*/
			//
			//
			*reinterpret_cast<volatile uint32_t *> (port) &= ~(1U << bval);  //for c++ language
			/*
				Converts between types by reinterpreting the underlying bit pattern.
				Syntax : reinterpret_cast < new_type > ( expression )
			*/
			////////////////////////////////////////////////////////////////////////////////////
			/* Set Pin Mode to Output*/
			const port_type gpio_mode_reg = port - 0x14;
			*reinterpret_cast<volatile port_type *>(gpio_mode_reg) |= (1U<<(bval*2));
		}
		
		void toggle()const{
			//access the register and toggle it
			*reinterpret_cast<volatile port_type *>(port) ^= (1U << bval);
		}

		void pseude_delayMs(int n){
			int i;
			for(;n>0;n++){
				for(i=0;i<3200;i++){}
			}
		}
/*
		void pseude_delayMs(){
			for(int i = 0; i<190000;i++){}
		}
*/		
		
	private:
		const port_type port;
		const bval_type bval;
};	


int main(){
	RCC_AHB1ENR |= (1U<<0); /* Enable Clock  to GPIOA*/
	Led led5(mcal::reg::gpioa, mcal::reg::gpioa_pin5);
	Led led6(mcal::reg::gpioa, mcal::reg::gpioa_pin6);
	
	while(1){
		led5.toggle();
		led6.toggle();
		led5.pseude_delayMs(500);
	}
	
	return 0;
}
