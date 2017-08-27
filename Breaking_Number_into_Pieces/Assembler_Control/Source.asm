.386
public _Amount_of_Numbers
public _Sort_n_Amount_of_Num
.model flat
.data
ten dword 10
N dword 0
temp dword 0
.code
_Amount_of_Numbers proc
push ebp
mov ebp,esp
mov eax,[ebp+8]
mov esi,0
_start_:
inc esi
cdq
idiv ten
cmp eax,0
jne _start_
mov eax,esi
pop ebp
ret
_Amount_of_Numbers endp
_Sort_n_Amount_of_Num proc
push ebp
mov ebp,esp
mov ebx,[ebp+8]
mov eax,[ebp+12]
mov esi,-1
_lets_start:
inc esi
cdq
idiv ten
mov [ebx][esi*4],edx
cmp eax,0
je _finita_
jmp _lets_start
_finita_:
inc esi
mov N,esi
mov esi,0
mov edi,-1
_first:
inc esi
cmp esi,N
je _la_finale
_second:
mov edi,esi
inc edi
_continue:
dec edi
cmp edi,0
je _first
mov edx,[ebx][edi*4]
mov ecx,edi
dec ecx
cmp [ebx][ecx*4],edx
jng _continue
mov temp,edx
mov edx,[ebx][ecx*4]
mov [ebx][edi*4],edx
mov edx,temp
mov [ebx][ecx*4],edx
jmp _continue
_la_finale:
mov esi,N
dec esi
mov ecx,esi
inc ecx
_finally_do_this:
mov ecx,esi
inc ecx
cmp esi,-1
je _grand_finale
mov edx,[ebx][esi*4]
mov [ebx][ecx*4],edx
dec esi
jmp _finally_do_this
_grand_finale:
mov esi,0
mov eax,N
mov [ebx][esi*4],eax
mov eax,ebx
pop ebp
ret
_Sort_n_Amount_of_Num endp
end