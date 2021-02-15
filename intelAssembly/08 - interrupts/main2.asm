#include"ADUC841.H"

	org 0000h
		sjmp start
		
	org 000Bh
		;T0 Interrupt Vector
		sjmp sounterFcn
		
start:
	
	mov TMOD, #00000101b ; p3.4 is sensor
	
	mov DPTR, #65532d
	mov T0L, DPL
	mov T0H, DPH
	
	set ET0 ; activate T0 interrupt
	set EA  ; activate global interrupts
		
	setb tr0 ;start counting with timer0
	
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
	
counterFcn:
	; After carrying interrupt function
	; Timer1 overflow (TF0) clear automatically
	set P2.0
	nop
	nop
	clr P2.0
	mov TL0, DPL
	mov TH0, DPH
	
	reti  ; return from interrupt subroutine command
		  ; return to place at infinity loop
	
	sjmp start
end