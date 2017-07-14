section .text
global string_length
global print_char
global print_newline
global print_string
global print_error
global print_uint
global print_int
global string_equals
global parse_uint
global parse_int
global read_word
global string_copy
global exit


string_length:
    xor rax, rax
.loop:
    cmp byte [rdi+rax], 0
    je .end 
    inc rax
    jmp .loop 
.end:
    ret

print_char:
    push rdi
    mov rdi, rsp
    call print_string 
    pop rdi
    ret

print_newline:
    mov rdi, 10
    jmp print_char

print_error:
    push rdi
    call string_length
    pop rsi
    mov rdx, rax 
    mov rax, 1
    mov rdi, 2 
    syscall
    ret

print_string:
    push rdi
    call string_length
    pop rsi
    mov rdx, rax 
    mov rax, 1
    mov rdi, 1 
    syscall
    ret

print_uint:
    mov rax, rdi
    mov rdi, rsp
    push 0
    sub rsp, 16
    
    dec rdi
    mov r8, 10

.loop:
    xor rdx, rdx
    div r8
    or  dl, 0x30
    dec rdi 
    mov [rdi], dl
    test rax, rax
    jnz .loop 
   
    call print_string
    
    add rsp, 24
    ret

print_int:
    test rdi, rdi
    jns print_uint
    push rdi
    mov rdi, '-'
    call print_char
    pop rdi
    neg rdi
    jmp print_uint

; returns rax: number, rdx : length
parse_int:
    mov al, byte [rdi]
    cmp al, '-'
    je .signed
    jmp parse_uint
.signed:
    inc rdi
    call parse_uint
    neg rax
    test rdx, rdx
    jz .error

    inc rdx
    ret

    .error:
    xor rax, rax
    ret 

; returns rax: number, rdx : length
parse_uint:
    mov r8, 10
    xor rax, rax
    xor rcx, rcx
.loop:
    movzx r9, byte [rdi + rcx] 
    cmp r9b, '0'
    jb .end
    cmp r9b, '9'
    ja .end
    xor rdx, rdx 
    mul r8
    and r9b, 0x0f
    add rax, r9
    inc rcx 
    jmp .loop 
    .end:
    mov rdx, rcx
    ret

string_equals:
    mov al, byte [rdi]
    cmp al, byte [rsi]
    jne .no
    inc rdi
    inc rsi
    test al, al
    jnz string_equals
    mov rax, 1
    ret
    .no:
    xor rax, rax
    ret 


read_char:
    push 0
    xor rax, rax
    xor rdi, rdi
    mov rsi, rsp 
    mov rdx, 1
    syscall
    pop rax
    ret 

read_word:
    push r14
    xor r14, r14 

    .A:
    push rdi
    call read_char
    pop rdi

    cmp al, ' '
    je .A
    cmp al, 10
    je .A
    cmp al, 13
    je .A 
    cmp al, 9 
    je .A

    .B:
    mov byte [rdi + r14], al
    inc r14

    push rdi
    call read_char
    pop rdi
    cmp al, ' '
    je .C
    cmp al, 10
    je .C
    cmp al, 13
    je .C 
    cmp al, 9
    je .C
    test al, al
    jz .C
    cmp r14, 254
    je .C 

    jmp .B

    .C:
    mov byte [rdi + r14], 0
    mov rax, rdi 
    
    pop r14
    ret
   
string_copy:
    mov dl, byte[rdi]
    mov byte[rsi], dl
    inc rdi
    inc rsi
    test dl, dl
    jnz string_copy
    ret


exit:
    mov rax, 60
    syscall
