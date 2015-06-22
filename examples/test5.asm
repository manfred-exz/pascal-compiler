.386p
.model flat,stdcall
option casemap:none
include pasLib.inc
includelib pasLib.lib
.code
program:
jmp test_1
test_multi:
push ebp
mov ebp, esp
sub esp, 0
push ebp
mov eax, dword ptr [ebp +20]
pop ebp
push eax
call writelnInt
add esp, 4
push ebp
mov eax, dword ptr [ebp +16]
pop ebp
push eax
call writelnInt
add esp, 4
push ebp
mov eax, dword ptr [ebp +12]
mov eax, dword ptr [eax]
pop ebp
push eax
call writelnInt
add esp, 4
push ebp
mov eax, dword ptr [ebp +8]
mov eax, dword ptr [eax]
pop ebp
push eax
call writelnInt
add esp, 4
mov eax, 5
push eax
pop eax
push ebp
mov [ebp +20], eax
pop ebp
mov eax, 6
push eax
pop eax
push ebp
mov [ebp +16], eax
pop ebp
mov eax, 3
push eax
pop eax
push ebp
mov ebp, dword ptr [ebp +12]
mov [ebp], eax
pop ebp
mov eax, 4
push eax
pop eax
push ebp
mov ebp, dword ptr [ebp +8]
mov [ebp], eax
pop ebp
push ebp
mov eax, dword ptr [ebp +20]
pop ebp
push eax
call writelnInt
add esp, 4
push ebp
mov eax, dword ptr [ebp +16]
pop ebp
push eax
call writelnInt
add esp, 4
push ebp
mov eax, dword ptr [ebp +12]
mov eax, dword ptr [eax]
pop ebp
push eax
call writelnInt
add esp, 4
push ebp
mov eax, dword ptr [ebp +8]
mov eax, dword ptr [eax]
pop ebp
push eax
call writelnInt
add esp, 4
add esp, 0
pop ebp
ret
test_1:
push ebp
mov ebp, esp
sub esp, 8
mov eax, 1
push eax
pop eax
push ebp
mov [ebp -4], eax
pop ebp
mov eax, 2
push eax
pop eax
push ebp
mov [ebp -8], eax
pop ebp
push ebp
mov eax, dword ptr [ebp -4]
pop ebp
push eax
call writelnInt
add esp, 4
push ebp
mov eax, dword ptr [ebp -8]
pop ebp
push eax
call writelnInt
add esp, 4
push ebp
mov eax, dword ptr [ebp -4]
pop ebp
push eax
push ebp
mov eax, dword ptr [ebp -8]
pop ebp
push eax
push ebp
lea eax, dword ptr [ebp -4]
pop ebp
push eax
push ebp
lea eax, dword ptr [ebp -8]
pop ebp
push eax
call test_multi
add esp, 16
push ebp
mov eax, dword ptr [ebp -4]
pop ebp
push eax
call writelnInt
add esp, 4
push ebp
mov eax, dword ptr [ebp -8]
pop ebp
push eax
call writelnInt
add esp, 4
add esp, 8
pop ebp
ret
end program
