#include<ADUC8051.H>
	
	org 0000h
		sjmp start
		
start:
		mov A, #01h
		mov DPTR, #sevenseg
		movc A, @A+DPTR
		mov P1, A
		
		mov A, #0Fh
		mov DPTR, #sevenseg
		movc A, @A+DPTR
		mov P1, A
		
		mov A, #06h
		mov DPTR, #sevenseg
		movc A, @A+DPTR
		mov P1, A
		
		nop
		nop
		nop
		
		sjmp start
		
sevenseg :  db 3Fh, 06h, 5Bh, 4Fh, 66h, 6Dh, 7Dh, 07h, 7Fh, 6Fh, 77h, 7Ch, 39h, 5Eh, 79h, 71h
	
end