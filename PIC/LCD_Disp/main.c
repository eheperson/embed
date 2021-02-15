#include <main.h>

int x;
float y;
char z;

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
   lcd_init();
      

   while(1)
   {
      
      lcd_send_byte(0,0x0d);
      printf(lcd_putc, "enivicivokki");
      delay_ms(1000);
      lcd_gotoxy(1,2);
      
      printf(lcd_putc, "     :*      ");
      delay_ms(1000);
      lcd_gotoxy(1,1);
      

   }

}
