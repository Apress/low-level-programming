main:
push   rbp
mov    rbp,rsp
sub    rsp,0x20

; `argc` and `argv` are saved in stack to make `rdi` and `rsi` available
mov    DWORD PTR [rbp-0x14],edi
mov    QWORD PTR [rbp-0x20],rsi

; var = 0
mov    DWORD PTR [rbp-0x4],0x0

; b = 0
mov    DWORD PTR [rbp-0x8],0x0

; 0x600a40 is the address of `buf` (a global variable of type `jmp_buf`)
mov    edi,0x600a40
call   400470 <_setjmp@plt>

; if (b < 3), the good branch is executed
; This is encoded by skipping several instructions to the `.endlabel` if b > 2
mov    eax,DWORD PTR [rbp-0x8]
cmp    eax,0x2
jg     .endlabel 

; A fair increment
; b++
mov    eax,DWORD PTR [rbp-0x8]
add    eax,0x1
mov    DWORD PTR [rbp-0x8],eax

; var++
add    DWORD PTR [rbp-0x4],0x1

; `printf` call
mov    eax,DWORD PTR [rbp-0x4]
mov    esi,eax
mov    edi,0x400684
; There are no floating point arguments, thus rax = 0
mov    eax,0x0
call   400450 <printf@plt>

; calling `longjmp`
mov    esi,0x1
mov    edi,0x600a40
call   400490 <longjmp@plt>

.endlabel:
mov    eax,0x0
leave  
ret    
