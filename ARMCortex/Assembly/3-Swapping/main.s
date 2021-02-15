		AREA	SwapREgistersContent, CODE, READONLY
		ENTRY
		EXPORT	__main
			
__main
		LDR		R0, =0xBABEFACE
		LDR		R1, =0xDEADBEEF
		
		EOR		R0, R1, R0 ; R1:XOR:R0 and store in R0
		EOR		R1, R0, R1
		EOR		R0, R1, R0
		
Stop	B		Stop
		ALIGN
		END