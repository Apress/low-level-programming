global _start

section .data

test_string: db "abcdef", 0

section .text

strlen:                   ; by our convention, first and the only argument
                          ; is taken from rdi
    xor rax, rax          ; rax will hold string length. If it is not 
                          ; zeroed first, its value will be totally random

.loop:                    ; main loop starts here
    cmp byte [rdi+rax], 0 ; Check if the current symbol is null-terminator.
                          ; We absolutely need that 'byte' modifier since
                          ; the left and the right part of cmp should be 
                          ; of the same size. Right operand is immediate
                          ; and holds no information about its size,
                          ; hence we don't know how many bytes should be 
                          ; taken from memory and compared to zero
    je .end               ; Jump if we found null-terminator

    inc rax               ; Otherwise go to next symbol and increase 
                          ; counter
    jmp .loop

.end:
    ret                   ; When we hit 'ret', rax should hold return value

_start:

    mov rdi, test_string
    call strlen
    mov rdi, rax

    mov rax, 60
    syscall
