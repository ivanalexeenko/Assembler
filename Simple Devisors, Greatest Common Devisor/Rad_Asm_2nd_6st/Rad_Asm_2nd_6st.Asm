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
    szHelloWorld        db  "Press ENTER to continue...", 13, 10, 0
    _endl_              db  " ",13,10,0
    _ends_              db  " ",0
    buf                 db  300 dup(' '),0
    _log_2_x_           db  "log2(x):",0
    separate            db  "                ",0
    another_separate    db  "                    ",0
    _x_                 db  "x:",0
    _ln_x_              db  "ln(x):",0
    _pow_e_x_           db  "e^(x):",0
    _pow_a_x_           db  "^(x):",0
    
    a                   dq  3.0000000
    step                dq  0.50000000
    left_range          dq  1.00000000
    right_range         dq  10.0000000
    ln_e                dq  1.00000000
    n                   dq  25.0000000
    result              dq  0.00000000
    buffer              dq  1.00000000
    k                   dq  0.00000000
    one                 dq  1.00000000
    null_               dq  0.00000000
.data?
        x               dq ?
        y               dq ?
        ln_a            dq ?
  
.code

MainProc	proc

           fld left_range
		   fsub step
		   fstp x
		   
		   
		   invoke StdOut,addr _x_
            
           invoke StdOut,addr separate
		   invoke StdOut,addr _log_2_x_
		  
		   
		   invoke StdOut,addr separate
		   invoke StdOut,addr _ln_x_
		   
		   
		   invoke StdOut,addr separate
		   invoke StdOut,addr _pow_e_x_     
		   
		   invoke StdOut,addr separate
		   invoke FloatToStr,a,addr buf
		   invoke StdOut,addr buf
		   invoke StdOut,addr _pow_a_x_     
		   invoke StdOut,addr _endl_



		                _start_log_2 :

		   fld x
		   fadd step
		   fst y
		   fstp x
		  
		   invoke  FloatToStr,x,addr buf
		   invoke StdOut,addr buf 
           invoke StdOut,addr another_separate  
           
           

			            _log_2_x :

		    finit
			fldln2
			fld y
			fyl2x
			fstp y
			fld y
			fldln2
			fdiv
			fstp y
			
			 invoke  FloatToStr,y,addr buf
             invoke  StdOut, addr buf
             
                         ln_x:
                         
            fld x
            fstp y
            fldln2
			fld y
			fyl2x
			fstp y
            
            invoke StdOut,addr another_separate
            invoke  FloatToStr,y,addr buf
            invoke  StdOut, addr buf
                fld one
                fstp buffer  
                fld null_
                fst k
				fstp result    
               
                          pow__e__x:
                          
				fld result
				fadd one
				fstp result
				_starter_:
				fld k
				fadd one
				fstp k

				fld buffer
				fmul ln_e
				fmul x
				fdiv k
				fstp buffer
				fld result
				fadd buffer
				fstp result

				fld n
				fld k

				fcompp
				fstsw ax
				sahf
				jne _starter_
			
            
	        invoke StdOut,addr another_separate
            invoke  FloatToStr,result,addr buf
            invoke  StdOut, addr buf
            
            fld null_
            fst result
            fstp k
            fld one
            fstp buffer
            
            
            fldln2
            fld a
			fyl2x
			fstp ln_a
			
                        pow__a__x:
            

			
				
				fld result
				fadd one
				fstp result
				_starting_:
				fld k
				fadd one
				fstp k

				fld buffer
				fmul ln_a
				fmul x
				fdiv k
				fstp buffer
				fld result
				fadd buffer
				fstp result

				fld n
				fld k

				fcompp
				fstsw ax
				sahf
				jne _starting_
			
            invoke StdOut,addr another_separate
            invoke  FloatToStr,result,addr buf
            invoke  StdOut, addr buf  
            invoke  StdOut, addr _endl_
            
            fld x
			fld right_range
			fcompp
			fstsw ax
			sahf
			        je _finita_
			  
            
            
            
            
            
            jmp _start_log_2
                
            
                
                
                        _finita_:
                        
            invoke  StdOut, addr _endl_
            invoke  StdOut, addr szHelloWorld
            invoke  StdIn, addr buf, 300
            invoke  ExitProcess, 0
MainProc    endp

end MainProc
