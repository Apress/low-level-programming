extern _GLOBAL_OFFSET_TABLE_

extern commonmsg
extern mainfun 

global fun1:function

section .rodata
msg: db "fun1", 10

section .text
fun1:
    mov rax, 1
    mov rdi, 1
    lea rsi, [rel msg]
    mov rdx, 6
    syscall
    call fun2
    call mainfun wrt ..plt
    ret

fun2:
    mov rax, 1
    mov rdi, 1
    mov rsi, [rel commonmsg wrt ..got]
    mov rdx, 5
    syscall
    ret
