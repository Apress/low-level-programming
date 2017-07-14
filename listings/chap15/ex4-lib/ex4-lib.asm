extern _GLOBAL_OFFSET_TABLE_

extern puts

global sostr:data (sostr.end - sostr)
global sofun:function

section .rodata
sostr: db "sostring", 10, 0
.end:

localstr: db "localstr", 10, 0

section .text
sofun:
    lea rdi, [rel localstr]    
    call puts wrt ..plt
    mov rax, 42
    ret

