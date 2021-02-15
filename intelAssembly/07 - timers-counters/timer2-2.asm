 
 #incude"ADUC841.H"
;
;------------------------------------------------------
;	That code includes interrupt
;	Check timer2.asm file
;	Same Project without T2 interrupt 
;------------------------------------------------------
;
;	Timer 2 example
;	complement P0.1 each 10ms, with interrupt
;	16 bit autoreload mode used here
;	for 10ms :
;		10000000/50000 = 200d
;		200 corresponds to 10ms delay

	org 0000h
		sjmp start
	
	org 002Bh ; Timer2 interrupt vector
		sjmp t2Int
		
start:
	
	mov T2CON, #00000000b ;Timer2 used, CNT2 = 0
	mov TL2, #0AFh
	mov TH2, #3Ch
	
	mov RCAP2L, #0AFh
	mov RCAP2H, #3Ch
	
	mov R0, #200d
	
	setb ET2
	setb EA
	setb TR2
	
x:
;
;
;	Any Code
;	  For
;	Any Purpose
;
	sjmp x
	
t2Int:
	clr TF2  ;after clearing TF2, Timer2 will load automatically
	djnz R0, k
	mov R0, #200d
	cpl P1.0
	
k:
	reti
	
	sjmp start
end