mov  rax, 0x1111222233334444         ; rax = 0x1111222233334444
mov  eax, 0x55556666                 ; !rax = 0x0000000055556666
                                     ;  why not rax = 0x1122334455556666?

mov  rax, 0x1111222233334444         ; rax = 0x1111222233334444
mov  ax, 0x7777                      ; rax = 0x1111222233337777 
                                     ; this works as expected 
mov  rax, 0x1111222233334444         ; rax = 0x1111222233334444
xor  eax, eax                        ; rax = 0x0000000000000000
                                     ; why not rax = 0x1111222200000000?
