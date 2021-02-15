#include"ADUC841.H"

	org 0000h
		sjmp start
		
start:
	
	clr C
	
	mov 00h, #12h
	mov A, #23h
	add A, 00h ; A <- A + 00h
	
	anl PSW, #11100111b
	
	mov R0, #02h
	mov 02h, #12h
	mov A, #23h
	add A, @R0 ; A <- A + @R0
	
	clr C
	mov 78h, #34h  ;XL
	mov 79h, #12h  ;XH
	mov 7Ah, #0EFh ;YL
	mov 7Bh, #12h  ;YH
	
	mov A, 78H ; A= XL
	add A, 7Ah ; A <- XL + YL
	mov 78h, A ; SL = A
	
	mov A,  79h ; A = XH
	addc A,  7Bh; A <- A + YH + C
	mov 79h, A  ; SH = A
	
end