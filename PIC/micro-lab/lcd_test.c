#include <lcd_test.h>


//******************* ANA PROGRAM FONKS�YONU *******************
void main ()
{ 

   setup_psp(PSP_DISABLED);        // PSP birimi devre d���
   setup_timer_1(T1_DISABLED);     // T1 zamanlay�c�s� devre d���
   setup_timer_2(T2_DISABLED,0,1); // T2 zamanlay�c�s� devre d���
   setup_CCP1(CCP_OFF);            // CCP1 birimi devre d���
   setup_CCP2(CCP_OFF);            // CCP2 birimi devre d���

   set_tris_a(0x01);  // RA0 Giri� olarak y�nlendiriliyor
   set_tris_b(0x00);
   set_tris_c(0xff);

   setup_adc(adc_clock_div_32); 
   setup_adc_ports(AN0); 

   lcd_init();   

   set_adc_channel(0);   
   delay_us(20);         

   lcd_init();  
   rtc_init();  
   rtc_set_datetime(11,12,13,4,16,38); 
   while(1){
   
         
      
      display();
      
         //check_alarm(saat, saata, dakika, dakikaa);
      if(input(menu)){        while(input(menu));
         printf(lcd_putc,"\f  Saat Ayari");
         while(1){
            if(input(menu)) {
               while(input(menu));
               break;
            }
            if(input(select)){
               while(input(menu));
               set_clock();
               break;
            }
         }
         
         delay_ms(20);
         printf(lcd_putc,"\f  Tarih Ayari");
         while(1){
            if(input(menu)){
               while(input(menu));
               break;
            }
            if(input(select)){
               while(input(select));
               set_date();
               break;
            }
         }
         while(input(menu));
         delay_ms(20);
         printf(lcd_putc,"\f  Alarm Ayari");
         while(1){
            if(input(menu)){
               while(input(menu));
               break;
            }
            if(input(select)){
               while(input(select));
               set_alarm();
               break;
            }
         
         }
      }
      
  }
}

