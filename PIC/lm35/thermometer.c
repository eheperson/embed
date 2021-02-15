/******************************************************
 PIC16F877 ile LM35 Sicaklik Sens�r� Uygulamasi
PIC PROG/DEKA : Port B jumper'i LCD konumunda olmali
*******************************************************/
#include <16f877.h> // Kullanilacak denetleyicinin baslik dosyasi tanitiliyor.
 
#device ADC=10 // 10 bitlik ADC kullanilacagi belirtiliyor.
 
// Denetleyici konfig�rasyon ayarlari
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG,NOCPD
 
#use delay (clock=4000000) // Gecikme fonksiyonu i�in kullanilacak osilat�r frekansi belirtiliyor.
 
#use fast_io(a) //Port y�nlendirme komutlari A portu i�in ge�erli
 
#define use_portb_lcd TRUE // LCD B portuna bagli
 
#include <lcd.c> // lcd.c dosyasi tanitiliyor
 
unsigned long int bilgi; // Isaretsiz 16 bitlik tam sayi tipinde degisken tanimlaniyor
float voltaj,sicaklik; // ondalikli tipte degiskenler tanitiliyor
 
//********** ANA PROGRAM FONKSIYONU*******
 
void main ( )
{
 setup_psp(PSP_DISABLED); // PSP birimi devre disi
 setup_timer_1(T1_DISABLED); // T1 zamanlayicisi devre disi
 setup_timer_2(T2_DISABLED,0,1); // T2 zamanlayicisi devre disi
 setup_CCP1(CCP_OFF); // CCP1 birimi devre disi
 setup_CCP2(CCP_OFF); // CCP2 birimi devre disi
 
 set_tris_a(0x01); // RA0 Giris olarak y�nlendiriliyor
 
 setup_adc(adc_clock_div_32); // ADC clock frekansi fosc/32
 setup_adc_ports(AN0); //RA0/AN0 girisi analog
 
 lcd_init(); // LCD hazir hale getiriliyor
 
 set_adc_channel(0); // RA0/AN0 ucundaki sinyal A/D islemine tabi tutulacak
 delay_us(20); // Kanal se�iminde sonra bu bekleme s�resi verilmelidir
 
 printf(lcd_putc,"\fSicaklik="); // LCD'ye yazi yazdiriliyor
 while(1) // sonsuz d�ng�
 {
 bilgi=read_adc(); // ADC sonucu okunuyor ve bilgi degiskenine aktariliyor
 
 voltaj=(0.0048828125*bilgi)*1000; // Dijitale �evirme islemine ugrayan sinyalin mV olarak gerilimi hesaplaniyor
 sicaklik=(voltaj/10)+2; // Her 10mV'ta 1 derece artma
 
 lcd_gotoxy(10,1); // Imle� 1. satir 10.s�tunda
 printf(lcd_putc,"%5.1f'C",sicaklik); // LCD'ye sicaklik degeri yazdiriliyor
 // G�sterilecek ondalikli degerin toplam basamak sayisi 5 olacak.
 // G�sterilecek degerin ondalikli kismi ise 1 basamak olacak. %5.1f
 // komutu ile bu islemler yaptirilmistir.
 delay_ms(100); // 100 msn gecikme
 }
}
