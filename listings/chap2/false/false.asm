global _start

section .text
_start:
    mov rdi, 1
    mov rax, 60
    syscall
