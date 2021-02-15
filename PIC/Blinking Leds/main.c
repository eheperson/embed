#include <main.h>

void main()
{

   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED, 0, 1);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_ccp1(CCP_OFF);
   setup_ccp2(CCP_OFF);
   
   
   set_tris_b(0x00);
   output_b(0x00);
   delay_ms(1000);
   output_b(0xFF);
   delay_ms(1000);
   output_b(0x00);
   delay_ms(1000);
   
   
   while(TRUE)
   {
      output_b(0b000000001);
      delay_ms(1000);
      output_b(0b00000010);
      delay_ms(1000);
   }

}
