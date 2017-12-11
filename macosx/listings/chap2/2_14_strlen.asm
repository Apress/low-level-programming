; listing 2-14. strlen.asm
; make 2_14_strlen & ./2_14_strlen & echo $?
; ========================
section .data

test_string:    db  "abcdef", 0

section .text
global start

; strlen - takes a pointer to a null-terminated string and returns its length
; rdi - Argument #1, the pointer to a null-terminated string
; @returns the length of the input string
; ===========================================================================
strlen:
    xor rax, rax            ; When this function returns, rax will store
                            ; the length of the input string.
.loop:
    cmp byte [rdi + rax], 0 ; Is the next character a null character, i.e '\0'
    je .end                 ; If it is null, go to .end
    inc rax                 ; Otherwise, increment rax by 1
    jmp .loop               ; and move on to the next iteration
.end:
    ret

; main
; ====
start:
    mov rdi, test_string
    call strlen
    mov rdi, rax
    mov rax, 0x2000001
    syscall
    
