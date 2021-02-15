#include"ADUC841.h"
;
;
;------------------------------------------------------
;	That code includes interrupt
;	Check main.asm file
;	Same Project without ADC interrupt 
;------------------------------------------------------
;
;
;	ADC Example Code
;	With interrupt
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
	org 0000h
		sjmp start
		
	org 0033h  ; ADC Interrupt Vector
		sjmp adcInt
		
start:
	mov ADCCON1, #8Ch ; 10001100, Internal Reference, Clk=32, (Suggested Settings)
	mov ADCCON2, #03h ; 00000001, Channel Selecting
	
	setb EADC  ;  Activate ADC Inerrupt
	setb EA    ;  Activate Global Interrupts
	setb SCONV ;  Read 1 bit data from ADC unit, 
			   ;  ADC Reading lap will be started after that
			   
x:
;
;
;	Any Code Here
;
	sjmp x

adcInt:
	mov A, ADCDATAH
	anl A, #0Fh
	mov R4, A
	mov R5, ADCDATAL
	
	reti
	
	sjmp start
end