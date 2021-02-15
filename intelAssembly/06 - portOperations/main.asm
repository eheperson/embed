#include"ADUC841.H"
;
;for AduC841, Port1 onlc coild used as input
;
; Reading Pin:
;	mov A, Px
;	jnb Px.y, <label>
;	jb Px.y, <label>
;	mov C, Px.y
;
;Read/Write/Modify
;	anl Px, A
;	orl Px, A
;	xrl Px, 
;	jbc Px.x ,<label>
;	
;	cpl Px.x
;	inc Px
;	dec Px
;	djnz Px, <label>
;	mov Px.y, C
;	clr Px.y
;	setb Px.y
;


	org 0000h
		
start:
	
	;Button Test
	; initial Value of Ports 1
	; P2.0 is button (Pull-down)
	
	clr P2.3
	nop
	mov A, #00Eh
	mov 00h, #01h
	add A, 00h
	
	
	
	mov P0, #00Fh
	anl P0, A
	nop
	nop
	anl A, P0
	nop 
	nop
	
buttonCheck1: 

	jb P2.0 ,buttonCheck1  ; Wait until button be pressed
	
buttonCheck2:
	
	mov P1, #00d  ; if button is pressed move forward
	
k:
	jb P2.0, buttonCheck2  ;same example with jb
	mov P1, #255d
	sjmp k
	

buttonCheck3:
	; Normally, at other examples there was no clicking
	;that example includes clicking
	
	jb P2.0,y ; if button is clecked move forward, otherwise branch to y

t:	
	jnb P2.0, k ; Wait untill release button
	
	nop
	nop
	mov P1, #0FFh

y:	
	nop
	sjmp buttonCheck3
	

buttonCheck4:
	
	jnb P2.0, u
	
	nop
	nop
	sjmp buttonCheck4
	
u:
	jnb P2.1, m
	mov P1, #00h
	sjmp buttonCheck4

m:	
	mov P1, #0FFh
	sjmp buttonCheck4
	
	
pinRead:
	
	mov A, P1
	
	jb P2.0, $
	jnb P2.0, $
	mov C, P2.1

	anl P1, A
	orl P1, A
	xrl P1, A
	
x1:
	jbc P2.0, y1
	nop
	nop
	sjm x1
	
y1:	
	nop
	nop
	cpl P2.3
	inc P2
	dec P2
	
	mov P2, #02h

x2:
	djnz P2, x2
	nop
	nop
	mov P2.3, C
	clr P2.4
	setb P2.5
	
	
	sjmp start
end