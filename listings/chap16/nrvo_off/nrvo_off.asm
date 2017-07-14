00000000004004b6 <f>:
; prologue 
4004b6:	55                   	push   rbp
4004b7:	48 89 e5             	mov    rbp,rsp
; A hidden argument is the address of a structure which will hold the result.
; It is saved into stack. 
4004ba:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
; Filling the fields of `copy` local variable 
4004be:	48 c7 45 e0 01 00 00 	mov    QWORD PTR [rbp-0x20],0x1
4004c5:	00 
4004c6:	48 c7 45 e8 02 00 00 	mov    QWORD PTR [rbp-0x18],0x2
4004cd:	00 
4004ce:	48 c7 45 f0 03 00 00 	mov    QWORD PTR [rbp-0x10],0x3
4004d5:	00 
; rax = address of the destination struct 
4004d6:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
; [rax]      = 1 (taken from `copy.x`)
4004da:	48 8b 55 e0          	mov    rdx,QWORD PTR [rbp-0x20]
4004de:	48 89 10             	mov    QWORD PTR [rax],rdx
; [rax + 8]  = 2 (taken from `copy.y`)
4004da:	48 8b 55 e0          	mov    rdx,QWORD PTR [rbp-0x20]
4004e1:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
4004e5:	48 89 50 08          	mov    QWORD PTR [rax+0x8],rdx
; [rax + 10] = 3  (taken from `copy.z`) 
4004e9:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
4004ed:	48 89 50 10          	mov    QWORD PTR [rax+0x10],rdx
; rax =  address where we have put the structure contents 
; (it was the hidden argument)
4004f1:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
4004f5:	5d                   	pop    rbp
4004f6:	c3                   	ret    

00000000004004f7 <main>:
4004f7:	55                   	push   rbp
4004f8:	48 89 e5             	mov    rbp,rsp
4004fb:	48 83 ec 30          	sub    rsp,0x30
4004ff:	89 7d dc             	mov    DWORD PTR [rbp-0x24],edi
400502:	48 89 75 d0          	mov    QWORD PTR [rbp-0x30],rsi
400506:	48 8d 45 e0          	lea    rax,[rbp-0x20]
40050a:	48 89 c7             	mov    rdi,rax
40050d:	e8 a4 ff ff ff       	call   4004b6 <f>
400512:	b8 00 00 00 00       	mov    eax,0x0
400517:	c9                   	leave  
400518:	c3                   	ret    
400519:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
