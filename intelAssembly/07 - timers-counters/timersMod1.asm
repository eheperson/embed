#include"ADUC841.H"


;	mode 1
;	max cycle number is 65536
;	we have to clean TF0 after each timer overflow
;	check TL0 and TH) at every sjmp wait
;	each sjmp wait will take 3cycle

	org 0000h
		sjmp start
		
start:
	mov TMOD, #01h ; 0000 0001b
				   ; TH = 0  : starting only with TR0
				   ; C/T = 0 : timer mode
				   ; M1 = 0, M0 = 0  : mode1, 16bit timer
	nop
	nop
	nop
	setb TR0
	
wait:
	nop
	nop
	sjmp wait
	
	nop
	
	sjmp start
end	
