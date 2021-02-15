;-----------------------------------------------------------------------
;Solving a simple equation method 4 - Compact Code
;-----------------------------------------------------------------------
; P = Q + R + S
; let Q=2, R=4, S=5
;-----------------------------------------------------------------------


		AREA	SimpEqu3Code,	CODE,	READONLY
		ENTRY
		EXPORT	__main
			
__main	
		ADRL	R0,	P		;
		LDR		R1, [R0, #4]
		LDR		R2, [R0, #8]
		
		ADD		R2, R1, R2
		LDR		R1, [R0, #12]
		ADD		R2, R2,	R1
		
Stop	
		B		Stop
	
	
		AREA	SimpEqu3Data,	DATA,	READONLY
			
P		SPACE	4
Q		DCD		2
R		DCD		4
S		DCD		5
			
		ALIGN
			

		END
		
		