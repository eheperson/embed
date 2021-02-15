#include"ADUC841.h"
;
;----------------------------------------------
;	Interrupts does not used in that code
;	Check main2.asm
;	Same Project with ADC interrup
;----------------------------------------------
;
;	ADC Example Code
;	Without interrupt
;
;	Usage of ADC unit:
;		1 - set ADCON1 and ADCON2 to select challel, SCONV should be '0'
;		2 - set SCONV=1
;		3 - check ADCI until becomes logic 1
;			means of that,
;			if ADCI 1, then adc reading complaited
;		4 - get readed ADC data from ADCDATAH and ADCDATAL
;		5 - clear ADCI and go back to step2, to run ADC again
;
;
;
	org 0000h
		sjmp start
		
start:
	
	mov ADCCON1, #08Ch; 10001100, Internal Reference, Clk=32 (suggsted settings)
	mov ADCCON2, #01h;  00000001, To select channel
	
read:
	setb SCONV  ; read 1 bit from ADC unit
	jnb ADCI, $  ;wait until ADC lap complaite
	
	clr ADCI
	mov R4, ADCDATAH
	mov R3, ADCDATAL
	
x:
;
;
; Any Code
;
;
;
	sjmp x
	
	sjmp start
end