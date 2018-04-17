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
    szEnter             db  "Please,enter an integer number:", 13, 10,0
    szOut               db  "Press ENTER to continue...", 13, 10, 0
    szEndl              db  " ",13,10,0
    szEnds              db  " ",0
    szDividers          db  "Simple dividers: ",13,10,0
    szDeg               db  "^",0
    szEq                db  " = ",0
    szMul               db  " * ",0
    two                 dd  2
    one                 db "1",0
    Error               db "This number can not be decomposed!",0
.data?
    buf                 db  300 dup(?),0
    mas                 dd  30 dup(?)
    num                 dd  ?
    deg                 dd  ?
    flag                dd  ?
    am                  dd  ?
    temp                dd  ?
.code

MainProc	proc
            invoke  StdOut, addr szEnter
            invoke  StdIn, addr buf, 300
            invoke  atol,addr buf
        mov num,eax      
		lea ebx, mas
		mov esi, -1
		mov edi, 1
		mov eax, num
		mov ecx, num
		cmp eax, 2
		jl _end_
		mov flag, 0

		_start_ :

		mov deg, 0
			mov eax, ecx
			inc edi
			mov edx, edi
			dec edx
			cmp edx, num
			je _finita_
			cmp ecx, 1
			je _finita_
			cdq
			mov ecx, eax
			idiv edi
			cmp edx, 0
			je _while_divide_
			jmp _start_

			_while_divide_ :
			inc esi
			mov[ebx][esi * 4], edi

			_while_ :

			inc deg
			
			cmp eax, 0
			je _finita_
			mov ecx, eax
			cdq
			idiv edi
			cmp edx, 0
			je _while_
			push eax
			mov eax, deg
			inc esi
			mov[ebx][esi * 4], eax
			pop eax
			jmp _start_

			_finita_ :

		inc esi
			mov am, esi
			jmp _grand_finale

			_end_ :

		mov flag, esi

			_grand_finale :

	        mov edi,flag
	        cmp edi,-1
	        je null_or_one
	          
            invoke ltoa,num,addr buf
            invoke  StdOut, addr szDividers
            invoke  StdOut, addr buf
            invoke  StdOut, addr szEq
            mov esi,-1
            lea ebx,mas
                    _cout_mas_:
                 
            inc esi
              
            cmp esi,am
            je _enough_
           
            invoke ltoa,[ebx][esi*4],addr buf
            pushad
            invoke  StdOut, addr buf
            popad 
            inc esi
           
            invoke ltoa,[ebx][esi*4],addr buf
            pushad
            invoke StdOut,addr szDeg
            invoke  StdOut, addr buf
            invoke StdOut,addr szMul
            popad 
            
            jmp _cout_mas_
                    null_or_one:
            invoke  StdOut, addr Error
            jmp _almost_
            
                    _enough_:
            invoke  StdOut, addr one
                    _almost_:
            invoke  StdOut, addr szEndl
            
            invoke  StdOut, addr szOut
            invoke  StdIn, addr buf, 300
            
                    _exit_:
          
            
            invoke  ExitProcess, 0
MainProc    endp

end MainProc