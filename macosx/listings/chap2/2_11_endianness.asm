; listing 2-11. endianness.asm
; =============================
section .data

newline_char:   db  10
codes:          db  '0123456789abcdef'
demo1:          dq  0x1122334455667788
demo2:          db 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88

section .text
global start

; print_newline - prints new line character (10) to stdout
; ========================================================
print_newline:
    mov rax, 0x2000004          ; write syscall number
    mov rdi, 1                  ; stdout file discriptor
    mov rsi, newline_char       ; address of new line character
    mov rdx, 1                  ; 1 byte
    syscall
    ret

; print_hex - outputs data to stdout in hexadecimal format
; rdi - Argument #1, the input data
; ========================================================
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
    ;mov rdi, [demo1]           ; Sadly this didn't work on Mac OSX
    mov rax, demo1              ; workaround
    mov rdi, [rax]   
    call print_hex
    call print_newline

    ;mov rdi, [demo2]           ; Sadly this didn't work on Mac OS X
    mov rax, demo2              ; workaround
    mov rdi, [rax]
    call print_hex
    call print_newline

    ; exit
    mov rax, 0x2000001
    xor rdi, rdi
    syscall


