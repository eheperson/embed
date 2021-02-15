#incude"ADUC841.H"
;
;------------------------------------------------------
;	That code does not include any interrupt
;	Check squareWave2.asm file
;	Same Project with T0 interrupt
;------------------------------------------------------
;
;	there is a square wave source with 2ms period
;	each 1 ms passed, square output will be toggled
;	
;	for 1ms :
;		1000000/90.04 = 11062 machine cycle will be neede
;		T0 : 65536d - 11062d = 54473d = D4C9h
;
	org 0000h
		sjmp start

start: 
	mov		TMOD,#01h ; tIMER0,gate=0, c/t=0, Counter mode with 16 bit (mode1)
	mov		DPTR,#54473d
	mov		DPTR,#64473d
	
	mov		TH0,DPL
	mov		TH0,DPH
	clr		P2.0
	setb	TR0
x:	jnb		TF0,x ;  after 1ms (11062 cycle) TF0 will set
	clr		TF0
	mov		TL0,DPL
	mov		TH0,DPH
	cpl		P2.0
	sjmp	x

	sjmp start
end