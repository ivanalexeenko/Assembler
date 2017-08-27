.386
.model flat
public _Sol@12
public @Remainder@8
public _DivideByTwo
public _StrIndex@12
.data
.code
_Sol@12 proc
mov eax,[esp+4]
mov ebx,[esp+8]
mov ecx,[esp+12]
imul eax,ebx
add eax,ecx
ret 12
_Sol@12 endp
@Remainder@8 proc
mov eax,ebx
mov ebx,edx
cdq
idiv ebx
mov eax,edx
ret
@Remainder@8 endp
_DivideByTwo proc
push ebp
mov ebp,esp
mov eax,[esp+8]
sar eax,1
pop ebp
ret
_DivideByTwo endp
_StrIndex@12 proc
push ebp
mov ebp,esp
mov edi,[esp+8]
mov ecx,[esp+12]
mov eax,[esp+16]
repne scasb 
jz m_found
mov eax,-1 
jmp m_end
m_found:
mov eax,[ebp+12]
sub eax,ecx 
dec eax
m_end: 
pop ebp
ret 12 
_StrIndex@12 endp
end