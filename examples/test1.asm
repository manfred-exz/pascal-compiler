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
push eax
pop eax
push eax
pop eax
mov ebx, 1
cmp eax, ebx
jne label_7
lea eax, label_8
jmp label_9
label_8 db 'excellent!'
label_9:
push eax
call writelnInt
add esp, 4
jmp label_6
label_7:
cmp eax, ebx
jne label_10
lea eax, label_11
jmp label_12
label_11 db 'well done!'
label_12:
push eax
call writelnInt
add esp, 4
jmp label_6
label_10:
cmp eax, ebx
jne label_13
lea eax, label_14
jmp label_15
label_14 db 'you passed'
label_15:
push eax
call writelnInt
add esp, 4
jmp label_6
label_13:
label_6:
label_16:
push eax
mov eax, 100
push eax
pop ebx
pop eax
cmp eax, ebx
jl label_18
push 0
jmp label_19
label_18:
push 1
label_19:
pop eax
test eax, eax
jz label_17
jmp label_16
label_17:
label_20:
push eax
mov eax, 100
push eax
pop ebx
pop eax
cmp eax, ebx
je label_21
push 0
jmp label_22
label_21:
push 1
label_22:
pop eax
test eax, eax
jz label_20
jmp goto_3
push eax
mov eax, 3
push eax
pop ebx
pop eax
cmp eax, ebx
je label_25
push 0
jmp label_26
label_25:
push 1
label_26:
pop eax
push eax
pop eax
test eax, eax
jz label_23
jmp label_24
label_23:
label_24:
add esp, 412
pop ebp
ret
p dd 3
q dd 4
end program
