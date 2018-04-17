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
    szEnter     db  "Please,enter the string from a,b,c :", 13, 10,0
    szNew       db  "SortedString:", 13, 10,0
    szOut       db  "Enter any key to continue...",0
    szEndl      db  " ",13,10,0
    szEnds      db  " ",0
    buf         db  100 dup(' '),0

.code

MainProc	proc
            invoke  StdOut, addr szEnter
            invoke  StdIn, addr buf, 300
            sub eax,2
            lea ebx,buf
            mov esi,-1
            xor ecx,ecx ; a
            xor edx,edx ; b
            xor edi,edi ; c
            
                    _start_:
            inc esi
            cmp esi,eax
            je _finita_
            
            mov al,[ebx][esi]
            cmp al,'a'
            je _add_a
            cmp al,'b'
            je _add_b
            cmp al,'c'
            je _add_c
            jmp _start_
            
                    _add_a:
            inc ecx
            jmp _start_
                    _add_b:
            inc edx
            jmp _start_
                    _add_c:
            inc edi
            jmp _start_
                    _finita_:
            mov esi,-1
                    _write_a:
            inc esi
            cmp esi,ecx
            je _write_b
            mov al,'a'
            mov [ebx][esi],al
            jmp _write_a
                    _write_b:
            dec esi
            mov ecx,esi
            mov esi,-1
                    _continue_write_b:
            inc esi
            inc ecx
            cmp esi,edx
            je  _write_c
            mov al,'b'
            mov [ebx][ecx],al
            jmp     _continue_write_b
                    _write_c:
            dec ecx
            mov edx,ecx
            mov esi,-1
                    _continue_write_c:
            inc edx
            inc esi
            cmp esi,edi
            je _grand_finale
            mov al,'c'
            mov [ebx][edx],al
            jmp _continue_write_c
                    _grand_finale:
                    
            invoke  StdOut, addr szNew
            invoke  StdOut, addr buf
            
            invoke StdOut,addr szEndl
            
            invoke  StdOut, addr szOut
            invoke  StdIn, addr buf, 300
            invoke  ExitProcess, 0
MainProc    endp

end MainProc
