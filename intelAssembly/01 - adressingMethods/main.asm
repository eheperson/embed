#include "ADUC841.H"

;*******************************************
;  This Scripts Includes Adressing Trials
;  General Adressing Structure : mov <target>, <source>
;*******************************************

	org 0000h
	sjmp start
	
start:
;----------------------------------------------------
	;Immediate(ivedi) adressing examples
	;	mov <target>, #source
	
	mov	A, #02h
	mov 20h, #20h
	mov R0, #0AAh
	mov DPTR, #1FE7Eh
	mov P0, #0FFh
	mov A, #0F1h
	mov 00h, #0AAh
	mov 01h, #00001111b
	mov A, #101d

;----------------------------------------------------
	;direct(dogrudan) adressing
	;	mov <target>, <source>
	
	mov A,	20h
	mov	10h, A
	mov 00h, 01h
	mov P0, 00h
	mov 00h, P0

;----------------------------------------------------
	;register direct adressing
	;	mov rn, <source>
	;	mov <target>, rn
	;  n is {0,1,2,3,4,5,6,7}
	mov A, R0
	mov R0, A
	mov R0, 01h
	mov 00h, R1
	; mov R1, R2 -- that code is not acceptable
	
;----------------------------------------------------
	;register indirect adressing
	;	mov <target>, @ri
	;	mov @ri, <source>
	; i is {0,1}
	; mean of the @ri:
	; 	first look inside ri
	;	than go to that adress inside ri
	;	manipulate data inside that adress
	; @ri is like a pointer i C/C++

	mov A, @r0
	mov @r0, A
	mov 21h, @r0
	mov 05h, @r1
	
;----------------------------------------------------
	;register indexed adressing
	;	movc A, @A+DPTR   -> @(A+DPTR)
	;	movc A, @A+PC  	  -> @(A+PC)
	; movc : Brings data from program memory not from ram
	;!!!!!! that adressing method is usefull with lookup tables
	; Look-Up tables stores at Program memory
	;
	; Check the Sevent Segment Display Eample Code
	
	mov A, #40h
	mov DPTR, #1000h
	movc A, @A+DPTR
	movc P0, A
	
	;-------------------------------------------------
	;	org 1000h
	;sayi: db 0,1,2,3,4
	;-------------------------------------------------
	ljmp start
	
	end
	
	