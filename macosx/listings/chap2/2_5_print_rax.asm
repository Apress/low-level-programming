; listing 2-5 print_rax.asm
; =========================
section .data
codes:  db  '0123456789ABCDEF'

section .text
global start
start:
    mov rax, 0x1122334455667788
    mov rdi, 1                      ; stdout
    ;mov rdx, 1                     ; WARNING: on Mac OSX we must explicitly set
                                    ; rdx after syscall write otherwise, it will
                                    ; be automatically zeroed out!
    mov rcx, 64                     ; 8 bytes = 64 bits
.loop:
    push rax                        

    ; next hexadecimal digit in rax
    ; xxxxxxxxxxxxxxxx
    ;  |<-----cl----->
    sub rcx, 4                      
    sar rax, cl
    and rax, 0xf                    

    ; now the value in rax ranging from 0 - 15 (4 bits)
    ; how can we represent this value using hex digit?
    mov rsi, codes                  ; WARNING: lea rsi, [codes + rax]
    add rsi, rax                    ; will not compile!

    mov rax, 0x2000004              ; write syscall number
    mov rdx, 1                      ; # bytes to rite

    push rcx                        ; syscall leaves rcx and r11 changed!
    syscall
    pop rcx                         ; restore rcx

    pop rax                         ; restore rax

    test rcx, rcx                   ; is rcx zero?
    jnz .loop                       ; if not move on to the next iteration

    ; otherwise, exit
    mov rax, 0x2000001              ; exit syscall number
    xor rdi, rdi                    ; exit status
    syscall
