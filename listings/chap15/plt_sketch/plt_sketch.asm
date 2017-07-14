; somewhere in the program
call func@plt


; PLT 
PLT_0:           ; the common part
call resolver

...

PLT_n:     func@plt:
jmp [GOT_n]
PLT_n_first:
; here the arguments for resolver are prepared
jmp PLT_0


GOT:
...
GOT_n:
dq  PLT_n_first
