; hello_world.asm
; ===============

global start                ; IMPORTANCE: don't underscore start (i.e _start)
                            ; otherwise the linker will complain!
section .data
hello_string:   db  "Hello, world!", 10, 0

section .text

; main program
; ============
; We're about to make a syscall write(rdi, rsi, rdx)
; where:
; rdi - the file descriptor, in this case 1 (stdout)
; rsi - the buffer's address, i.e where is the data to be written out?
;       in our case, it is hello_string.
; rdx - the number of bytes to be written
start:
    ; write(rdi, rsi, rdx)
    mov rax, 0x2000004      ; write syscall number.
                            ; The actual syscall number for write is 4
                            ; but in order to make it work under Mac OS X
                            ; we have to add 0x2000000 to it before copying
                            ; into rax.

    mov rdi, 1              ; stdout
    mov rsi, hello_string   
    mov rdx, 14
    syscall

    ; exit
    mov rax, 0x2000001      ; exit syscall number
    xor rdi, rdi            ; exit status
    syscall

    
    
