#include "ADUC841.H"

	org 0000h
		sjmp start
		
start:
	
	mov A, #76h
	mov 40h, #45h
	
	anl 40h, A; 40h <- 40h & A
	
	orl 40h, A; 40h <- 40h | A
	
	xrl 40h, A; 40h <- 40h ^ A
	
	mov R0, #02h
	mov 02h, #11110000b
	mov A, #11001100b
	
	anl A, @R0;
	
	orl A, @R0;
	
	xrl A, @R0;
	
	setb RS0
	setb RS1
	
	anl PSW, #11100111b
	
	orl PSW, #00011000b
	
	mov A, #0FFh
	clr A
	clr 00h
	mov 20h, #0FFh
	clr 00h
	
	; clr works in byte level only for A(accumulator)
	; clr normally bit level instruction (except A)
	clr C
	clr PWS.7
	clr R0
	clr PSW.3
	clr P0
	clr P1.2
	clr R0
	clr A.4
	
	
	;;; don't known yet, what are the functionality of that commented lines
	;mov A, #11100011b
	;cpl A
	;cpl 00h
	;cpl R0
	;cpl @Ro
end
	
	