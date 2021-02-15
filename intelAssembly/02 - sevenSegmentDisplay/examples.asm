#include"ADUC841.H"

	org 0000h
		sjmp start
		
start:

	mov A, #20h
	mov 20h, #20h
	mov R0, #0AAh
	mov DPTR, #1FE7h
	mov P0, #0CCh
	
	mov A, #0A2h
	mov 20h, #0A0h
	mov DPTR, #2FE9h
	mov R0, #0FAh
	mov P0, #0FFh
	
	mov 00h, #00001100b
	mov 01h, #54d
	mov 02h, #98h
	mov 03h, #0ABh
	mov 03h, #0Ch
	
	mov R0, #54h
	mov R1, #10100011b
	mov 20h, #23d
	
	setb PSW.3
	clr PSW.3
	
	setb RS0
	
	mov R0, #23h
	
	mov 12h, #66h
	mov R5, #34h
	
	mov P0, #0F0h
	
	mov DPTR, #01FEh
	
	mov 02h, A
	mov A, 01h
	mov A, #01h
	mov 30h, 01h
	mov R5, 01h
	mov P1, A
	mov P0, 01h
	
	mov C, A.6
	mov C, P0.1
	mov P0.2, C
	;mov P0.1, PSW.7  ---- that command is not acceptable
	
	movc 01h, C
	
	setb 06h
	mov C, 07h
	mov P0.1, C
	
	mov A, R5
	
	setb RS0
	
	mov R0, A
	
end
	