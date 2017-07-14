extern _GLOBAL_OFFSET_TABLE_
global _start

extern sofun 

section .text
_start:
call sofun wrt ..plt

; `exit` system call
mov rdi, 0
mov rax, 60
syscall
