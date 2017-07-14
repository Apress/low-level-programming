extern  _GLOBAL_OFFSET_TABLE_

global func:function

section .rodata
message: db "Shared object wrote this", 10, 0

section .text
func:
    mov     rax, 1
    mov     rdi, 1
    mov     rsi, message
    mov     rdx, 14 
    syscall
ret
