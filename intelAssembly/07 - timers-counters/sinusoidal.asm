#include "ADUC841.H"
;
;
;
;	There is asinusoidal source with 20ms period
;	Requesting to trigger the tristor at each 18 degree (after 0 degree)
;	18 degree = 1ms supposed
;	Requesting detect every zero degree in sine wave, then report to mcu
;	T0 will be used for 18 degree detection
;	P3.2 will be used for zero degree detection
;	Mode 1 will be used
;	1ms = 1000000ns
; 	1000000/90.04 = 11062 cycle
;	T0 : 65536 - 11062 = 54473
;	54473d = d4c9h


	org 0000h
		sjmp start 

start:
	mov TMOD, #00001001b ; T0, Mode 1, start with pulse from P2.3
	mov T0L, #0c9h
	mov TOH, #0d4h
	setb TR0	;At this time, T0 cannot start counting

wait:
	jnb TF0, wait  	; counting will start if there is a signal from P3.2
					; When TF0 setting, 1ms will be passed
	clr TF0			; To wait another pulse from P3.2 , we must clear TF0
	clr TR0			; Stop Timer0
					;if 0 degree detected again, timer will start counting again
	setb p1.5		; tristor set
	
	nop
	nop
	clr P1.5
	
x1:
	jnb P2.3, x1
	setb TR0
	sjmp wait 
	
	
	sjmp start
end