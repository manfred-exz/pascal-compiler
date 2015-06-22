.386p
.model flat,stdcall
option casemap:none
include pasLib.inc
includelib pasLib.lib
.code
program:
jmp test_1
scope2_scope1:
push ebp
mov ebp, esp
sub esp, 4
mov eax, 567
push eax
pop eax
push ebp
mov [ebp -4], eax
pop ebp
mov eax, 678
push eax
pop eax
push ebp
mov ebp, dword ptr [ebp]
mov [ebp -8], eax
pop ebp
mov eax, 789
push eax
pop eax
push ebp
mov ebp, dword ptr [ebp]
mov ebp, dword ptr [ebp]
mov [ebp -8], eax
pop ebp
push ebp
mov eax, dword ptr [ebp -4]
pop ebp
push eax
call writelnInt
add esp, 4
push ebp
mov ebp, dword ptr [ebp]
mov eax, dword ptr [ebp -8]
pop ebp
push eax
call writelnInt
add esp, 4
push ebp
mov ebp, dword ptr [ebp]
mov ebp, dword ptr [ebp]
mov eax, dword ptr [ebp -8]
pop ebp
push eax
call writelnInt
add esp, 4
mov eax, dword ptr [ebp -4]
add esp, 4
pop ebp
ret
scope1:
push ebp
mov ebp, esp
sub esp, 8
mov eax, 345
push eax
pop eax
push ebp
mov [ebp -4], eax
pop ebp
mov eax, 456
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
call scope2_scope1
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
mov eax, dword ptr [ebp -8]
add esp, 8
pop ebp
ret
test_1:
push ebp
mov ebp, esp
sub esp, 8
mov eax, 123
push eax
pop eax
push ebp
mov [ebp -4], eax
pop ebp
mov eax, 234
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
call scope1
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
