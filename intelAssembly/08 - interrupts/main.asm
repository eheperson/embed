#include "ADUC841.H"
;
;----------------------------------------------
;	Interrupts does not used in that code
;	Check main2.asm
;	Same Project with T0 interrup
;----------------------------------------------
;	there is a sensor at P3.4
;	each toggling from 0 to 1 (P3.4), one box passed
;	until box passed totaly, P3.4 is 1
;	at second toggling from 0 to 1 at P3.4
;	another box is passing
;	if 1000 box counted, P2.0 will set
;	because of the P3.4, we have to use Timer0
;	for 1000 box :
;		65536d - 1000d = 64536d = FC17h
; 	open Port3, set P3.4
;	detect box each toggling P3.4 from 1 to 0 (check TL0)
	org 0000h
		sjmp start
		
start:
	mov TMOD. #00000101b  ;Timer0, gate=0, c/t=1 (counter), mode1(16bit counter)
	mov TL0, #0FCh		  ; normally FCh
	mov TH0, #0FFh		  ; normally FCh, to trials 4 more, FFh
	
	clr P2.0
	setb TR0
	
x:
	jnb TF0, x  ;if P3.4 detects 1000 box, TF0 will be set
	
	clr TF0  ;clear tF0 automatically after overflow
	setb P2.0
	nop
	nop
	clr P2.0
	mov TL0, #0FCh ; normally 17h
	mov TH0, #0FFh ; normally FCh, to trial 4 more count (FFh)
	
	sjmp x
	
	; We do not need to set TR0 
	; Timer0 runs automatically already
	sjmp start
end