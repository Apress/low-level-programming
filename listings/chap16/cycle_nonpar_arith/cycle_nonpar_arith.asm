looper:
    mov     rax,[rsi]

    ; The next instruction depends on the previous one.
    ; It means that we can not swap them because 
    ; the program behavior will change.
    xor     rax, 0x1        

    ; One more dependency here
    add     [rdi],rax
    add     rsi,8
    add     rdi,8
    dec     rcx
    jnz     looper
