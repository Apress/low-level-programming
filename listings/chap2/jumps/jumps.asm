mov rax, -1
mov rdx, 2

cmp rax, rdx
jg location
ja location			; different logic!

cmp rax, rdx
je  location		; if rax equals rdx
jne location		; if rax is not equal to rdx