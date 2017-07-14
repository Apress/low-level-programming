00000000004004b6 <f>:
4004b6:	48 89 f8             	mov    rax,rdi
4004b9:	48 c7 07 01 00 00 00 	mov    QWORD PTR [rdi],0x1
4004c0:	48 c7 47 08 02 00 00 	mov    QWORD PTR [rdi+0x8],0x2
4004c7:	00 
4004c8:	48 c7 47 10 03 00 00 	mov    QWORD PTR [rdi+0x10],0x3
4004cf:	00 
4004d0:	c3                   	ret    

00000000004004d1 <main>:
4004d1:	48 83 ec 20          	sub    rsp,0x20
4004d5:	48 89 e7             	mov    rdi,rsp
4004d8:	e8 d9 ff ff ff       	call   4004b6 <f>
4004dd:	b8 00 00 00 00       	mov    eax,0x0
4004e2:	48 83 c4 20          	add    rsp,0x20
4004e6:	c3                   	ret    
4004e7:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
4004ee:	00 00 
