;---General Informations---
;
;	Commnds  :  acall(absolute call, 2byte),  lcall(long acll, 3 byte), ret
;	Registers :  SP(stack pointer, 07h),  PC(pointer counter, 0000h)
;
;	Pointer Counter  :
;	Stack Pointer    :

;---Calling Subroutine--
;
;	PC   <-  PC + 2  //2 for acall, 3 for lcall
;	SP   <-  SP + 1
;	@SP  <-  PCL     //PCL = PC 0:7
;	SP   <-  SP + 1
;	@SP  <-  PCH	// PCH = PC 15:8
;
;---Returning From Subroutine---
;
;	PCH  <-  @SP
;	SP   <-  SP - 1
;	PCL  <-  SP
;	SP   <-  SP - 1
;
;
;!!!!!!!  Don't carry any operation inside subroutine
;!!!!!!!  SP default adress : 07h
;!!!!!!!  Bank1 default adress  : 07h
;!!!!!!!  Or we can change default adress of SP -  not suggsted!
;
;---Push and Pop---
;
;	-Push and pop are shortcut methods
;
;	push  <source>
;	push : SP   <-  SP + 1
;		   @SP  <-  <source>
;
;	pop  <target>
;	pop : <target>  <-  SP + 1
;		  SP        <-  SP + 1
;
#include"ADUC841.H"

	org	0000h
		sjmp start
start:


;--- Push Pop example 1 ----      ;more push pop example belove

pushPopExp:

	nop
	nop
	push P0  ;SP++ and P0=@SP
	push P1  ;SP++ and P1=@SP
	push P2  ;SP++ and P2=@SP
	push P3  ;SP++ and P3=@SP
	pop 03h  ;03h = @SP  and SP--
	pop 02h  ;02h = @SP  and SP--
	pop 01h  ;01h = @SP  and SP--
	pop 00h  ;00h = @SP  and SP--
	nop
	nop
	nop
	sjmp pushPopExp:
	
	
;--- Subroutine example 1 ---

example1:

	mov A, #00d
	inc A
	acall blinker
	inc A
	acall blinker
	inc A
	sjmp example1
	
blinker:   ;Blinker subroutine
	setb P0.1
	nop
	clr P0.1
	nop
	setb P0.1
	nop
	clr P0.1
	nop
	ret
	
;--- Subroutine example 2 ---

example2:

	mov A, #01h
	acall ledBlink
	mov A, #04h
	acall, ledBlink
	mov A, #0FFh
	acall ledBlink
	sjmp example2
	
ledBlink:  ;ledBlink Subroutine
	mov P0, A
	ret
	

;--- Subroutine example 3 ---

example3:

	nop
	nop
	mov A, #01h
	acall blinkerAnother
	mov A, #04h
	acall blinkerAnother
	mov A, #0FFh
	acall blinkerAnother
	sjmp example3
	
blinkerAnother:
	nop
	nop
	mov P0, A
	acall multiplier
	nop
	nop
	ret

multiplier:
	nop
	mov B, #02h
	mul AB
	mov P1, A
	ret

;--- Subroutine example 3 ---

example4:

	nop
	nop
	acall ramClean
	nop
	mov A, #01h
	acall blinker2
	mov A, #04h
	acall blinker2
	mov A, #0FFh
	acall blinker2
	
	sjmp example4
	
blinker2:
	nop
	mov P0, A
	acall ramClean
	ret

ramClean:
	mov R0, #7Fh
	mov A, #00h
	loop:
		mov @R0, A
		djnz R0, loop
		
;--- Push Pop example 2 ----     

pushPop2:
	nop
	nop
	push P0   ; SP++ and P0 = @SP
	push P1   ; SP++ and P1 = @SP
	acall blinkerLast
	pop 03h	  ;  03h = @SP  and SP--
	pop 02h	  ;  02h = @SP  and SP--
	pop 01h	  ;  01h = @SP  and SP--
	pop 00h	  ;  00h = @SP  and SP--
	sjmp pushPop2
	
blinkerLast:
	nop
	nop
	mov P1, #0FFh
	push P2  ;SP++ and P2 = @SP
	push P3  ;SP++ and P3 = @SP
	;may be some error here !!!!
	ret
		
	ljmp start
end