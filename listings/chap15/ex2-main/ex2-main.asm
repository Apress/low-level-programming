extern _GLOBAL_OFFSET_TABLE_
global _start

extern sofun 

global msg:data (msg.end - msg)

section .rodata
msg: db "SO function called -- message is stored in 'main'", 10  
.end:

section .text
_start:
call sofun  wrt ..plt

mov rdi, 0
mov rax, 60
syscall

