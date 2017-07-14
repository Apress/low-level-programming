section .data
correct: dq -1
section .text
global _start
_start:
mov rax, [0x400000-1]

; exit
mov rax, 60
xor rdi, rdi
syscall      
