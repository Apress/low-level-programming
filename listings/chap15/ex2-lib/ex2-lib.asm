extern _GLOBAL_OFFSET_TABLE_
global sofun:func

extern msg

section .text
sofun:
mov rax, 1
mov rdi, 1
mov rsi, [rel msg wrt ..got]
mov rdx,  50
syscall
ret

