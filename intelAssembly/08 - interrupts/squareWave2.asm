 
 #incude"ADUC841.H"
;
;------------------------------------------------------
;	That code includes interrupt
;	Check squareWave.asm file
;	Same Project without T0 interrupt 
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

	org		000bh
		sjmp	timer0Int

start:
	mov		TMOD,#01h
	
	;mov DPTR,#54473d ; that is correct value
	mov	 DPTR,#65473d ; that value is used for simplified out
	mov		TL0, DPL
	mov		TH0, DPh
	clr		P2.0	
	setb	ET0			; activate timer0 interrupt
	setb	EA			; activate global iterrupts
	setb	TR0			; timer0 set
x:
	nop
	nop
	nop
	;
	; any code for any purpose
	; could be declared here
	; whenever Timer0 overflows, Timer0 interrupt subroutine will run
	; then return back to where he left off
	; befor returning Timer0 overflow clears auto
	;
	sjmp x
	
timer0Int: ;Timer0 interrupt subroutine	
	;at each overflow TF0 will be cleared automatically
	mov		TL0,DPL
	mov		TH0,DPH
	cpl		P2.0
	reti
	
	sjmp start
end