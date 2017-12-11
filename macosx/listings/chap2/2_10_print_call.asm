; listing 2-10. print_call.asm
; =============================
section .data

newline_char:   db  10
codes:          db  '0123456789abcdef'

section .text
global start

; print_newline - prints new line character (10) to stdout
print_newline:
    mov rax, 0x2000004          ; write syscall number
    mov rdi, 1                  ; stdout file discriptor
    mov rsi, newline_char       ; address of new line character
    mov rdx, 1                  ; 1 byte
    syscall
    ret

; print_hex - outputs data to stdout in hexadecimal format
; rdi - Argument #1, the input data
print_hex:
    mov rax, rdi
    mov rdi, 1                  ; stdout file descriptor
    ;mov rdx, 1                 ; WARNING: on Mac OS X we must explicitly
                                ; set rdx every time we make write syscall!
    mov rcx, 64                 ; right shift by 60, 56, 52, ...,4
.iterate:
    push rax
    
    ; next 4 consecutive bits in rax
    sub rcx, 4
    sar rax, cl
    and rax, 0xf

    ; how to represent this 4 bits using hexadecimal code?
    mov rsi, codes              ; WARNING: lea rsi, [codes + rax]
    add rsi, rax                ; will not compile!

    mov rax, 0x2000004          ; write syscall number
    mov rdx, 1                  ; write 1 byte

    push rcx
    syscall
    pop rcx
    pop rax

    test rcx, rcx
    jnz .iterate
    ret

start:
    mov rdi, 0x1122334455667788
    call print_hex
    call print_newline
    
    ; exit
    mov rax, 0x2000001
    xor rdi, rdi
    syscall


