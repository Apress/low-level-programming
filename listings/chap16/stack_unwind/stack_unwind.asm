extern printf
extern fptr ; pointer to local variable of main
global unwind

section .rodata
format : db "%x ", 10, 0

section .code
unwind:
    push rbx

; while (rbx > fptr) { 
    ;     print rbx; rbx = [rbx];
    ; }
    mov rbx, rbp 
    .loop:
    cmp rbx,fptr ; check if pointing fptr or lower
    jc .end
    mov rdi, format
    mov rsi, rbx
    call printf
    mov rbx, [rbx]
    jmp .loop 

    .end:
    pop rbx
    ret
