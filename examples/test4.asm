.386p
.model flat,stdcall
option casemap:none
include pasLib.inc
includelib pasLib.lib
.code
program:
jmp test_1
abcde:
push ebp
mov ebp, esp
sub esp, 4
push ebp
mov ebp, dword ptr [ebp +12]
add ebp, 0
mov eax, dword ptr [ebp]
pop ebp
push eax
call writelnInt
add esp, 4
push ebp
mov ebp, dword ptr [ebp +12]
add ebp, 4
mov eax, dword ptr [ebp]
pop ebp
push eax
call writelnInt
add esp, 4
mov eax, 3
push eax
pop eax
push ebp
mov ebp, dword ptr [ebp +12]
add ebp, 0
mov [ebp], eax
pop ebp
mov eax, 4
push eax
pop eax
push ebp
mov ebp, dword ptr [ebp +12]
add ebp, 4
mov [ebp], eax
pop ebp
mov eax, 0
push eax
pop eax
push ebp
mov [ebp -4], eax
pop ebp
push ebp
mov eax, dword ptr [ebp -4]
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
label_1:
label_4:
push ebp
mov eax, dword ptr [ebp -4]
pop ebp
push eax
mov eax, 3
push eax
pop ebx
pop eax
cmp eax, ebx
jle label_6
push 0
jmp label_7
label_6:
push 1
label_7:
pop eax
push eax
pop eax
test eax, eax
jz label_5
push ebp
mov eax, dword ptr [ebp -4]
pop ebp
push eax
pop eax
mov ebx, 1
sub eax, ebx
mov ebx, 4
imul ebx
push eax
push ebp
mov eax, dword ptr [ebp -4]
pop ebp
push eax
pop eax
pop ebx
push ebp
mov ebp, dword ptr [ebp +8]
add ebp, ebx
mov [ebp], eax
pop ebp
push ebp
mov eax, dword ptr [ebp -4]
pop ebp
push eax
pop eax
mov ebx, 1
sub eax, ebx
mov ebx, 4
imul ebx
push ebp
mov ebp, dword ptr [ebp +8]
add ebp, eax
mov eax, dword ptr [ebp]
pop ebp
push eax
call writelnInt
add esp, 4
push ebp
mov eax, dword ptr [ebp -4]
pop ebp
push eax
mov eax, 1
push eax
pop ebx
pop eax
add eax, ebx
push eax
pop eax
push ebp
mov [ebp -4], eax
pop ebp
jmp label_4
label_5:
label_8:
push ebp
mov eax, dword ptr [ebp -4]
pop ebp
push eax
mov eax, 1
push eax
pop ebx
pop eax
sub eax, ebx
push eax
pop eax
mov ebx, 1
sub eax, ebx
mov ebx, 4
imul ebx
push eax
push ebp
mov eax, dword ptr [ebp -4]
pop ebp
push eax
pop eax
pop ebx
push ebp
mov ebp, dword ptr [ebp +8]
add ebp, ebx
mov [ebp], eax
pop ebp
push ebp
mov eax, dword ptr [ebp -4]
pop ebp
push eax
mov eax, 1
push eax
pop ebx
pop eax
sub eax, ebx
push eax
pop eax
mov ebx, 1
sub eax, ebx
mov ebx, 4
imul ebx
push ebp
mov ebp, dword ptr [ebp +8]
add ebp, eax
mov eax, dword ptr [ebp]
pop ebp
push eax
call writelnInt
add esp, 4
push ebp
mov eax, dword ptr [ebp -4]
pop ebp
push eax
mov eax, 1
push eax
pop ebx
pop eax
sub eax, ebx
push eax
pop eax
push ebp
mov [ebp -4], eax
pop ebp
push ebp
mov eax, dword ptr [ebp -4]
pop ebp
push eax
mov eax, 1
push eax
pop ebx
pop eax
cmp eax, ebx
je label_9
push 0
jmp label_10
label_9:
push 1
label_10:
pop eax
push eax
pop eax
test eax, eax
jz label_8
mov eax, 1
neg eax
push eax
pop ecx
push ebp
mov [ebp -4], ecx
pop ebp
label_11:
push ecx
mov eax, 1
push eax
pop eax
pop ecx
cmp ecx, eax
jg label_12
push ebp
mov eax, dword ptr [ebp -4]
pop ebp
push eax
mov eax, 1
neg eax
push eax
pop ebx
pop eax
cmp eax, ebx
je label_15
push 0
jmp label_16
label_15:
push 1
label_16:
pop eax
push eax
pop eax
test eax, eax
jz label_13
mov eax, 1
neg eax
push eax
call writelnInt
add esp, 4
jmp label_14
label_13:
label_14:
push ebp
mov eax, dword ptr [ebp -4]
pop ebp
push eax
mov eax, 2
push eax
pop ebx
pop eax
add eax, ebx
push eax
pop eax
mov ebx, 1
sub eax, ebx
mov ebx, 4
imul ebx
push eax
push ebp
mov eax, dword ptr [ebp -4]
pop ebp
push eax
pop eax
pop ebx
push ebp
mov ebp, dword ptr [ebp +8]
add ebp, ebx
mov [ebp], eax
pop ebp
push ebp
mov eax, dword ptr [ebp -4]
pop ebp
push eax
mov eax, 2
push eax
pop ebx
pop eax
add eax, ebx
push eax
pop eax
mov ebx, 1
sub eax, ebx
mov ebx, 4
imul ebx
push ebp
mov ebp, dword ptr [ebp +8]
add ebp, eax
mov eax, dword ptr [ebp]
pop ebp
push eax
call writelnInt
add esp, 4
push ebp
mov ecx, dword ptr [ebp -4]
pop ebp
inc ecx
push ebp
mov [ebp -4], ecx
pop ebp
jmp label_11
label_12:
mov eax, 3
push eax
pop ecx
push ebp
mov [ebp -4], ecx
pop ebp
label_17:
push ecx
mov eax, 1
push eax
pop eax
pop ecx
cmp ecx, eax
jl label_18
push ebp
mov eax, dword ptr [ebp -4]
pop ebp
push eax
pop eax
mov ebx, 1
sub eax, ebx
mov ebx, 4
imul ebx
push ebp
mov ebp, dword ptr [ebp +8]
add ebp, eax
mov eax, dword ptr [ebp]
pop ebp
push eax
call writelnInt
add esp, 4
push ebp
mov ecx, dword ptr [ebp -4]
pop ebp
dec ecx
push ebp
mov [ebp -4], ecx
pop ebp
jmp label_17
label_18:
push ebp
mov eax, dword ptr [ebp -4]
pop ebp
push eax
pop eax
lea ebx, outer_const
mov ebx, dword ptr [ebx]
cmp eax, ebx
jne label_20
mov eax, 1
push eax
call writelnInt
add esp, 4
jmp label_19
label_20:
lea ebx, inner_const_abcde
mov ebx, dword ptr [ebx]
cmp eax, ebx
jne label_21
mov eax, 2
push eax
call writelnInt
add esp, 4
jmp label_19
label_21:
mov ebx, 1
cmp eax, ebx
jne label_22
mov eax, 3
push eax
call writelnInt
add esp, 4
jmp label_19
label_22:
mov ebx, 0
cmp eax, ebx
jne label_23
lea eax, inner_const_abcde
mov eax, dword ptr [eax]
push eax
call writelnInt
add esp, 4
lea eax, outer_const
mov eax, dword ptr [eax]
push eax
call writelnInt
add esp, 4
jmp label_19
label_23:
mov ebx, 2
cmp eax, ebx
jne label_24
mov eax, 4
push eax
call writelnInt
add esp, 4
jmp label_19
label_24:
label_19:
mov eax, dword ptr [ebp -4]
add esp, 4
pop ebp
ret
inner_const_abcde dd 5
test_1:
push ebp
mov ebp, esp
sub esp, 20
mov eax, 1
push eax
pop eax
push ebp
add ebp, 0
mov [ebp -8], eax
pop ebp
mov eax, 2
push eax
pop eax
push ebp
add ebp, 4
mov [ebp -8], eax
pop ebp
push ebp
lea eax, dword ptr [ebp -8]
pop ebp
push eax
push ebp
lea eax, dword ptr [ebp -20]
pop ebp
push eax
call abcde
add esp, 8
push ebp
add ebp, 0
mov eax, dword ptr [ebp -8]
pop ebp
push eax
call writelnInt
add esp, 4
push ebp
add ebp, 4
mov eax, dword ptr [ebp -8]
pop ebp
push eax
call writelnInt
add esp, 4
jmp goto_123
mov eax, 7
push eax
call writelnInt
add esp, 4
goto_123:
mov eax, 2
push eax
pop eax
mov ebx, 1
sub eax, ebx
mov ebx, 4
imul ebx
push eax
mov eax, 2
push eax
pop eax
mov ebx, 1
sub eax, ebx
mov ebx, 4
imul ebx
push ebp
add ebp, eax
mov eax, dword ptr [ebp -20]
pop ebp
push eax
mov eax, 2
push eax
pop ebx
pop eax
sub eax, ebx
push eax
call absInt
add esp, 4
push eax
pop eax
pop ebx
push ebp
add ebp, ebx
mov [ebp -20], eax
pop ebp
mov eax, 2
push eax
pop eax
mov ebx, 1
sub eax, ebx
mov ebx, 4
imul ebx
push ebp
add ebp, eax
mov eax, dword ptr [ebp -20]
pop ebp
push eax
call writelnInt
add esp, 4
add esp, 20
pop ebp
ret
outer_const dd 3
end program
