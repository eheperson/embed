#include"ADUC841.H"
;
;----------------------------------------------
;	That code includes interrupt
;	Check adc2-2.asm
;	Same Project without Timer0 interrup
;----------------------------------------------
;
;	Read the value with ADC at each 10ms
;	Store readed values at R4 and R5
;
;	T0, 16bit and will count 200

	org 0000h
		sjmp start
		
	org 000Bh ;Timer0 Interrupt vector
		sjmp t0Int

		
start:
	mov ADCCON1, #8Ch ; 10001100, Internal Reference, Clk=32, (Suggested Settings)
	mov ADCCON2, #01h ; 00000001, Channel Selecting
	
	mov TMOD, #00000001b
	
	mov DPTR, #15535d ; 65525 - 50000
	
	mov TL0, DPL
	mov TH0, DPH
	
	setb ET0
	setb EA
	
	setb TR0
	
	sjmp $ ; infinite loop
		
t0Int:
	;after 200 interrupt, ADC lap will be started
	clr TF0
	mov TL0, DPL
	mov TH0, DPH
	
	dec R0
	
	cjne R0, #00h, x ;after 10ms, ADC Lap started
	setb SCONV
	jnb ADCI, $; infinite loop, wait until ADC Reading Finish
	
	clr ADCI
	mov R4, ADCDATAH
	mov R5, ADCDATAL
	
	anl 04h, #0Fh  ;04h is the adress of R4
	
	mov R0, #200d
	
x:
	reti
	
	sjmp start
end