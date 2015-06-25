.386p
.model flat,stdcall
option casemap:none
include pasLib.inc
includelib pasLib.lib
.code
program:
jmp test_1
fib:
push ebp
mov ebp, esp
sub esp, 4
push ebp
mov eax, dword ptr [ebp +8]
pop ebp
push eax
mov eax, 0
push eax
pop ebx
pop eax
cmp eax, ebx
je label_2
push 0
jmp label_3
label_2:
push 1
label_3:
pop eax
push eax
push ebp
mov eax, dword ptr [ebp +8]
pop ebp
push eax
mov eax, 1
push eax
pop ebx
pop eax
cmp eax, ebx
je label_4
push 0
jmp label_5
label_4:
push 1
label_5:
pop eax
push eax
pop ebx
pop eax
or eax, ebx
push eax
pop eax
push eax
pop eax
test eax, eax
jz label_0
mov eax, 1
push eax
pop eax
push ebp
mov [ebp -4], eax
pop ebp
jmp label_1
label_0:
push ebp
mov eax, dword ptr [ebp +8]
pop ebp
push eax
mov eax, 2
push eax
pop ebx
pop eax
sub eax, ebx
push eax
call fib
add esp, 4
push eax
push ebp
mov eax, dword ptr [ebp +8]
pop ebp
push eax
mov eax, 1
push eax
pop ebx
pop eax
sub eax, ebx
push eax
call fib
add esp, 4
push eax
pop ebx
pop eax
add eax, ebx
push eax
pop eax
push ebp
mov [ebp -4], eax
pop ebp
label_1:
mov eax, dword ptr [ebp -4]
add esp, 4
pop ebp
ret
test_1:
push ebp
mov ebp, esp
sub esp, 412
push eax
call fib
add esp, 4
push eax
call writeInt
add esp, 4
add esp, 412
pop ebp
ret
p dd 3
q dd 4
end program
