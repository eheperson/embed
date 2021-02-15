#include"ADUC841.H"
;
;----------------------------------------------
;	Interrupts does not used in that code
;	Check adc2-2.asm
;	Same Project with Timer0 interrup
;----------------------------------------------
;
;	Read the value with ADC at each 10ms
;	Store readed values at R4 and R5

	org 0000h
		sjmp start

		
start:
	
	mov ADCCON1, #08Ch; 10001100, Internal Reference, Clk=32 (suggsted settings)
	mov ADCCON2, #01h;  00000001, To select channel
	
read:
	setb SCONV  ; read 1 bit from ADC unit
	
x:
	jnb ADCI, x  ;wait until ADC lap complaite
	clr ADCI
	mov R4, ADCDATAH
	mov R5, ADCDATAL
	
	anl 04h, #0Fh ; adress of R4 is 04h
	mov A, #01h   ; load 1 for 10ms delay
	
	acall delay
	
	sjmp read

delay:
	mov R5, A
delay2:
	mov R7, #90h
delay1:
	mov R6, #0FFh
	
	djnz R6, $
	
	djnz R7 dly1
	
	djnz R5, dly2
	
	ret

	sjmp start
end