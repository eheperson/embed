$NOMOD51
	
#include"ADUC841.H"

	org 0000h
		sjmp start
		
start:

	mov A, #0FFh
	mov A, #33h
	sjmp start
end
	
	DELAY: MOV TMOD,#00000001B 
       MOV TH0,#19H
       MOV TL0,#388H 
       SETB TR0 
	   
HERE: JNB TF0,HERE 
      CLR TR0 
      CLR TF0 
      RET