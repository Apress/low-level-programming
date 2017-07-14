extern _GLOBAL_OFFSET_TABLE_
global sofun:function

section .rodata
msg: db "SO function called", 10  
.end:

section .text
sofun:
mov rax, 1
mov rdi, 1
lea rsi, [rel msg]
mov rdx, msg.end - msg
syscall
ret

