;------------------------------------------------------------------
;Solving a simple equation method 2 - Storing Constants In Memory
;------------------------------------------------------------------
; P = Q + R + S
; let Q=2, R=4, S=5
;------------------------------------------------------------------

		AREA	SimpleAdd, DATA, READONLY
			
P		SPACE	4	;RESERVE 4 BYTES OF MEMORY	
Q		DCD		2	;CREATE VARIABLE Q WITH INTERNAL VALUE 2, Q=0x00000002
R		DCD		4	;CREATE VARIABLE R WITH INTERNAL VALUE 4, Q=0x00000004
S		DCD		5	;CREATE VARIABLE S WITH INTERNAL VALUE 5, Q=0x00000005
	
		AREA	SimpleAddCode,  CODE,	READONLY
		ENTRY
		EXPORT __main
	
__main
		LDR		R1, Q
		LDR		R2, R
		LDR		R3, S
		
		ADD		R0, R1, R2
		ADD		R0, R0, R3
		
Stop	B		Stop

		END

