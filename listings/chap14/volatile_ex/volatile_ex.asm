; these are two arguments for `printf`
mov    esi,0x1
mov    edi,0x4005d4

; vol = 4
mov    DWORD PTR [rsp+0xc],0x4

; vol ++
mov    eax,DWORD PTR [rsp+0xc]
add    eax,0x1
mov    DWORD PTR [rsp+0xc],eax

xor    eax,eax

; printf( "%d\n", ordinary )
; the `ordinary` is not even created in stack frame
; its final precomputed value 1 was placed in `rsi` in the first line!
call   4003e0 <printf@plt>

; the second argument is taken from memory, it is volatile!
mov    esi,DWORD PTR [rsp+0xc]

; First argument is the address of "%d\n"
mov    edi,0x4005d4
xor    eax,eax

; printf( "%d\n", vol )
call   4003e0 <printf@plt>
xor    eax,eax
