0000000000400546 <no_stack_frame>:
400546:	55                   	push   rbp
400547:	48 89 e5             	mov    rbp,rsp
40054a:	48 83 ec 70          	sub    rsp,0x70
40054e:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
400555:	00 00 
400557:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
40055b:	31 c0                	xor    eax,eax
40055d:	b8 00 00 00 00       	mov    eax,0x0
400562:	48 8b 55 f8          	mov    rdx,QWORD PTR [rbp-0x8]
400576:	c9                   	leave  
400577:	c3                   	ret    
