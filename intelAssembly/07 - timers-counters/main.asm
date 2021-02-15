#include"ADUC841.H"

	org 0000h
		sjmp start
		
start:

	;--- Timer Example 1 ---
	;
	;	Toggle a led connectedto P1.0 every 1ms
	; 	any rn coul take max 255
	;	if r0=255
	;	every djnz will increase value of rn -> cycle number : 255*3*(machineCycle)
	;														   255*3*90.4
	;   we cannot catch 1ms delay in that situations
	;
	;	to obtain 1ms delay:
	;		1ms/90.4ns = 11062 
	;		r0 = 255
	;		r1 = x
	;		3*255*x will be olur machine cycle for 1ms delay
	;
	cpl P1.0
	acall delay
	nop
	sjmp start
	
delay:
	mov R1, #255d  ;r1 = k1

x1:	mov R0, #255d  ; r0 = k0
x2: djnz R0, x2
	djnz R1, X1
	
	; waiting time :
	;	djnz takes 3 cycle
	;	first djnz line : 3*k2*k1
	;	second djnz line : 3*k1
	;	total djnz  : 3*k2*k1 + 3*k2 = 3*k2(k1 + 1)
	;	k2 = 255 , supposed
	;	3*255*(k1 + 1) = 11062
	;	k1 = 15
	nop
	nop
	ret
	
	sjmp start

end