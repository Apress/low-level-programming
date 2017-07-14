section .data
correct: dq -1
section .text
global _start
_start:
jmp _start
mov rbx, correct
sub rbx, 64 * 1024
mov rbx, [rbx]

; exit
mov rax, 60
xor rdi, rdi
syscall      
