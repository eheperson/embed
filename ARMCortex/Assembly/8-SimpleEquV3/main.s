;-----------------------------------------------------------------------
;Solving a simple equation method 3 - Using Register Relative Adressing
;-----------------------------------------------------------------------
; P = Q + R + S
; let Q=2, R=4, S=5
;-----------------------------------------------------------------------


		ALIGN

		AREA	SimpEqu3Code,	CODE,	READONLY
		ENTRY
		EXPORT	__main
			
__main	
		ADRL	R4, Vals		;R4 POINTS TO Vals AREA
		LDR		R1, [R4, #Q]	;LOAD Q=2 INTO R1
		LDR		R2, [R4, #R]	;LOAD R=4 INTO R2
		LDR		R3, [R4, #S]	;LOAD S=5 INTO R3
		
		ADD		R0, R1, R2
		ADD		R0, R0, R3
		
		STR		R0, [R4, #P]
		
Stop	
		B		Stop
		
P		EQU		0
Q		EQU		4
R		EQU		8
S		EQU		12
	
		AREA	SimpEqu3Data,	DATA,	READONLY
			
Vals	SPACE	4
		DCD		2
		DCD		4
		DCD		5
			

		END
		
		