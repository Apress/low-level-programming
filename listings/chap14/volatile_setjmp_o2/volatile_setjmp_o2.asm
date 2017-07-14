main:

; allocating memory in stack 
sub    rsp,0x18

; a `setjmp` argument, the address of `buf`
mov    edi,0x600a40

; b = 0
mov    DWORD PTR [rsp+0xc],0x0
; instructions are placed in the order different
; from C statements to make better use of pipeline and other inner 
; CPU mechanisms.
call   400470 <_setjmp@plt>

; `b` is read and checked in a fair way
mov    eax,DWORD PTR [rsp+0xc]
cmp    eax,0x2
jle    .branch

; return 0 
xor    eax,eax
add    rsp,0x18
ret    

.branch:

mov    eax,DWORD PTR [rsp+0xc]

; the second argument of `printf` is var + 1
; It was not even read from memory nor allocated. 
; The computations were performed in compile time
mov    esi,0x1

; The first argument of `printf`
mov    edi,0x400674

; b = b + 1
add    eax,0x1
mov    DWORD PTR [rsp+0xc],eax

xor    eax,eax
call   400450 <printf@plt>

; longjmp( buf, 1 )
mov    esi,0x1
mov    edi,0x600a40
call   400490 <longjmp@plt>
