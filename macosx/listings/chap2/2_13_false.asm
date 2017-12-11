; listing 2-13 false.asm
; ======================
global start
section .text
start:
    mov rdi, 1          ; exit status code
    mov rax, 0x2000001  ; exit syscall number
    syscall
