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
    szHelloWorld        db "All ASCII symbols:",13,10,0
    szEnds              db " ",0
    szEndl              db " ",13,10,0
    buf                 db  2 dup(' '),0
    ten                 dd 10

.code
MainProc	proc
            invoke  StdOut, addr szHelloWorld
            mov esi,-1
            mov buf,'0'
            dec buf
            
                _begin_:
            
            inc esi
            cmp esi,128
            je _end_
            
            cdq
            mov eax,esi
            idiv ten
            cmp edx,0
            je _endl_
            
                _continue_:
                
            inc buf
            push esi
            invoke StdOut,addr buf
            invoke StdOut,addr szEnds
            pop esi
            jmp _begin_
            
                _endl_:
                
            push esi
            invoke StdOut,addr szEndl
            pop esi
            jmp _continue_
            
                _end_:
                
            invoke  StdIn, addr buf, 300
            invoke  ExitProcess, 0
MainProc    endp

end MainProc
