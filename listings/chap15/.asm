global _start

extern sofun 

section .text
_start:
call sofun 

; `exit` systel call
mov rdi, 0
mov rax, 60
syscall
