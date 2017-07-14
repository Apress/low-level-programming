; global -> rsi
787:	mov    rax,QWORD PTR [rip+0x20084a]        # 200fd8 <_DYNAMIC+0x1c8>
78e:	mov    eax,DWORD PTR [rax]
790:	mov    esi,eax

792:	lea    rdi,[rip+0x46]        # 7df <_fini+0xf>
799:	mov    eax,0x0
79e:	call   650 <printf@plt>

; global_alias -> rsi
7a3:	mov    eax,DWORD PTR [rip+0x20088f]        # 201038 <global>
7a9:	mov    esi,eax

7ab:	lea    rdi,[rip+0x2d]        # 7df <_fini+0xf>
7b2:	mov    eax,0x0
7b7:	call   650 <printf@plt>

; calling global `fun`
7bc:	call   640 <fun@plt>

; calling aliased `fun` directly
7c1:	call   770 <fun>
