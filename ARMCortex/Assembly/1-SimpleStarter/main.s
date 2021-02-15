; Without Startup File
STACK	EQU		0x00000100		;Define stack size of 256 bytes
	
	AREA	STACK, NOINT, READWRITE, ALIGN=3

StackMem	SPACE	Stack

	AREA	RESET, DATA, READONLY
	EXPORT	__Vectors

__Vectors

	DCD		StackMem +Stack
	DCD 	Reset_Handler
	AREA	SimpleProject, CODE, READONLY, ALIGN=2

	ENTRY
	EXPORT  Reset_Handler
	
Reset_Handler

	MOV		R5, #0x1234
	MOV		R3, #0x1234
	ADD		R6, R5, R3
	
Stop	B	Stop
	END
; 
;
;//////////////////////////////////////////
;//////////////////////////////////////////
; With Startup File
;	AREA SimpleProject, CODE, READONLY
;	ENTRY
;	EXPORT __main

;__main
;	MOV		R5, #0x1234
;	MOV		R3, #0x1234
;	ADD		R6, R5, R3
;	
;Stop	B	Stop
;	END
		
