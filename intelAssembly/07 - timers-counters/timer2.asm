#include"ADUC841.H"
;
;----------------------------------------------
;	Interrupts does not used in that code
;	Check timer2-2.asm
;	Same Project with Timer2 interrup
;----------------------------------------------
;
;	Timer 2 example
;	complement P0.1 each 10ms, without interrupt
;	16 bit autoreload mode used here
;	for 10ms :
;		10000000/50000 = 200d
;		200 corresponds to 10ms delay

	org 0000h
		sjmp start
		
start:
	
	mov T2CON, #00000000b; Timer mode, CNT2=0
	mov TL2, #0ACh
	mov TH2, #3Ch
	
	mov RCAP2L, #0AFh
	mov RCAP2H, #3Ch
	mov R0, #200d
	
	setb TR2 ;Start timer to count
	
x:
	jnb TF2, $
	clr TF2	;autoreload after overflow
	djnz R0, k
	mov R0, #200d
	cpl P1.0
	
k:
	sjmp x
	
	sjmp start
end