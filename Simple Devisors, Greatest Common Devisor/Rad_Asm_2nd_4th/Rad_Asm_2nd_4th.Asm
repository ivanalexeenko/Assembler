.486
.model flat, stdcall                    
option casemap :none

include windows.inc     ; always first

include masm32.inc
include gdi32.inc
include user32.inc
include kernel32.inc

includelib masm32.lib
includelib gdi32.lib
includelib user32.lib
includelib kernel32.lib

.data
    szOut               db  "Press Enter to continue... ",13,10,0
    szHelloWorld        db  "Lets find the Greatest Common Divisor of two numbers:", 13, 10, 0
    szEnter_1           db  13,10,"Please,enter the First number :",13,10,0
    szEnter_2           db 13,10,"Please,enter the Second number :",13,10,0
    GCD                 db  "GCD ",0
    _endl_              db  " ",13,10,0
    _ends_              db  " ",0
    buf                 db  300 dup(' '),0
    num_1               dd 100
    num_2               dd 200
    left_brace          db "(",0
    virgule             db ",",0
    right_brace         db ")",0
    _equal_             db " = ",0
.data?
   gcd                  dd ?
.code

MainProc	proc
             invoke  StdOut, addr szHelloWorld
        
            invoke StdOut,addr szEnter_1
            call NumberInput
            mov num_1,eax
          
            invoke StdOut,addr szEnter_2
            call NumberInput
           
            mov num_2,eax
            
            

            
	
	
	
		    mov eax, num_1
		    mov ebx, num_2
		    cmp eax, ebx
		    jg _start_

		    mov ecx, eax
		    mov eax, ebx
		    mov ebx, ecx

		            _start_ :

		    cdq
			idiv ebx
			cmp edx, 0
			je _found_
			mov eax, ebx
			mov ebx,edx
			jmp _start_


			        _found_ :
		     mov gcd,ebx
             
	         invoke  StdOut,addr GCD
	         invoke  StdOut,addr left_brace
	         
	         invoke ltoa,num_1,addr buf
	         invoke StdOut,addr buf
	         
	         invoke StdOut,addr virgule
	         
	         invoke ltoa,num_2,addr buf
	         invoke StdOut,addr buf
	         
	         invoke  StdOut,addr right_brace
	         
	         invoke  StdOut,addr _equal_
	         
	         invoke ltoa,gcd,addr buf
	         invoke StdOut,addr buf
	         
	         invoke StdOut,addr _endl_
	         
	         invoke StdOut,addr szOut

             invoke StdIn, addr buf, 300


            
            invoke  ExitProcess, 0
MainProc    endp

NumberInput proc
            invoke StdIn, addr buf, 300
            invoke atol,addr buf
            ret
NumberInput endp
end MainProc


