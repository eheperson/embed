		AREA	myCode, CODE, READONLY
		ENTRY	
		EXPORT  __main
			
__main
		LDR		R0, =A ;R0 is pointing to the adress A
		MOV		R1, #5
		STR		R1, [R0] ;Store R1 to R0
		
		LDR		R0, =C
		MOV		R1, #4
		STR		R1, [R0]
		
		LDR		R0, =D
		MOV		R1, #3
		STR		R1, [R0]
	
Stop	B		Stop
	
		;AREA 	name, type, spec
		AREA	myData, DATA, READWRITE
		; Allocate Following in the SRAM
A		SPACE 	4
C		SPACE	4
D		SPACE	4
	
		END