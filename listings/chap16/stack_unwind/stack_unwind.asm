extern printf
global unwind

section .rodata
format : db "%x ", 10, 0

section .code
unwind:
push rbx

; while (rbx != 0) { 
    ;     print rbx; rbx = [rbx];
    ; }
    mov rbx, rbp 
    .loop:
    test rbx, rbx
    jz .end
    mov rdi, format
    mov rsi, rbx
    call printf
    mov rbx, [rbx]
    jmp .loop 

    .end:
    pop rbx
    ret
