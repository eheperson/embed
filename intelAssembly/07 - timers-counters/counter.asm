#include "ACDUC841.H"
;
;
;	There is a sensor at P3.4 pin
;	Purpose is counting how many box passes from conveyer band with that sensor
;	Led connected to P0.1 will blink at every box detection
;
;	8bit, autoreload mode, T0 (mode 2)
;	TH0 and TL0 will be 155d (255 - 100)
;	155d = 9Bh
;	
;	detector wll count at every toggling of led from logic 1 to logic 0
;	
	org 0000h
		sjmp start
		
start:
	mov TMOD, #00000110b ; T0, Mode1, Gate=0, will start with TR0
	mov TL0, #250d
	mov TH0, #250d
	
	setb TR0
	clr P0.1
	
x:
	jnb TF0, x  ; if P3.4 detect 100 box, tF0 will be 1 
	clr TF0		; Clear TF0 after each overflow at timer0
	setb P0.1
	nop
	nop
	clr P0.1
	sjmp x
	
	sjmp start
end