section .text
%include "colon.inc"

extern read_word
extern find_word
extern print_newline
extern print_string
extern print_error
extern string_length
extern exit

global _start

section .rodata
msg_noword: db "No such word",0


%include "words.inc"
    
section .text
_start:
    push rbp
    mov rbp, rsp
    sub rsp, 256
    mov rdi, rsp
    call read_word
    mov rdi, rax
    mov rsi, lw
    call find_word
    test rax, rax
    jz .bad

    add rax, 8
    push rax
    mov rax, [rsp]
    mov rdi, rax
    call string_length
    pop rdi
    add rdi, rax
    inc rdi
    call print_string
    mov rsp, rbp
    pop rbp
    mov rdi, 0
    call exit 

.bad:
    mov rdi, msg_noword
    call print_error

    mov rsp, rbp
    pop rbp
    mov rdi, 0
    call exit


