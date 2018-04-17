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
    szEnter     db  "Please,enter the string :", 13, 10,0
    szOut       db  "Enter any key to continue...",0
    szEndl      db  " ",13,10,0
    szEnds      db  " ",0
    buf         db  100 dup(' '),0

.code

MainProc	proc
            invoke  StdOut, addr szEnter
            invoke  StdIn, addr buf, 100
            
            sub eax,2
            lea ebx,buf
            mov esi,-1
            
                _start_:
            
            inc esi
            cmp esi,eax
            je _finita_
            mov al,[ebx][esi]
            cmp al,96
            jle _start_
            cmp al,123
            jge _start_
            sub al,32
            mov [ebx][esi],al
            jmp _start_
                _finita_:
                
            invoke  StdOut, addr buf
            invoke  StdOut, addr szEndl
            invoke  StdOut, addr szOut
            invoke  StdIn, addr buf, 1
            invoke  ExitProcess, 0
MainProc    endp

end MainProc
