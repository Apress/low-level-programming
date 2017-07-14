looper:
mov     rax, [rsi]
mov     rdx, [rsi + 8]
xor     rax, 0x1        
xor     rdx, 0x1
add     [rdi],rax
add     [rdi+8],rdx
add     rsi, 16
add     rdi, 16
sub     rcx, 2
jnz     looper
