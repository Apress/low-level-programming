extern _GLOBAL_OFFSET_TABLE_

extern fun1

global commonmsg:data commonmsg.end - commonmsg
global mainfun:function 
global _start

section .rodata
commonmsg: db "fun2", 10, 0
.end:

mainfunmsg: db "mainfun", 10, 0


section .text
_start:
    call fun1 wrt ..plt
    mov rax, 60
    mov rdi, 0
    syscall

mainfun:
    mov rax, 1
    mov rdi, 1
    mov rsi, mainfunmsg
    mov rdx, 8
    syscall
    ret
