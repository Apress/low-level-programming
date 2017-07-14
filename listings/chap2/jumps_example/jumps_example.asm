    cmp rax, 42
    jl yes
    mov rbx, 0
    jmp ex
yes:
    mov rbx, 1
ex:
