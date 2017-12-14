; listing 2-1 hello.asm
; ======================
global start                ; WARNING: don't make it _start

section .data
message:    db 'hello, world!', 10

section .text
start:
    mov rax, 0x2000004      ; Syscall number shound be in rax
                            ; On Mac OSX, the write syscall number is
                            ; 4 instead of 1, and don't ever forget to
                            ; add 0x2000000 to the actual syscall number before
                            ; store it in rax.
    mov rdi, 1              ; argument #1 in rdi: where to write? stdout
    mov rsi, message        ; argument #2 in rsi: where does the string start?
    mov rdx, 14             ; argument #3 in rdx: how many bytes to write?
    syscall                 ; this instruction invokes as system call

