mov rsi, 999
mov rdi, 42
call maximum
...
maximum:
push rbp
mov rbp, rsp
sub rsp, 3984

mov [rbp-0x1004], edi
mov [rbp-0x1008], esi
mov eax, [rbp-0x1004]
...

leave
ret
