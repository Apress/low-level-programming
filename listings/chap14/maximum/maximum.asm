00000000004004b6 <maximum>:
4004b6:       55                      push   rbp
4004b7:       48 89 e5                mov    rbp,rsp
4004ba:       48 81 ec 90 0f 00 00    sub    rsp,0xf90
4004c1:       89 bd fc ef ff ff       mov    DWORD PTR [rbp-0x1004],edi
4004c7:       89 b5 f8 ef ff ff       mov    DWORD PTR [rbp-0x1008],esi
4004cd:       8b 85 fc ef ff ff       mov    eax,DWORD PTR [rbp-0x1004]
4004d3:       3b 85 f8 ef ff ff       cmp    eax,DWORD PTR [rbp-0x1008]
4004d9:       7d 08                   jge    4004e3 <maximum+0x2d>
4004db:       8b 85 f8 ef ff ff       mov    eax,DWORD PTR [rbp-0x1008]
4004e1:       eb 06                   jmp    4004e9 <maximum+0x33>
4004e3:       8b 85 fc ef ff ff       mov    eax,DWORD PTR [rbp-0x1004]
4004e9:       c9                      leave
4004ea:       c3                      ret

00000000004004eb <main>:
4004eb:       55                      push   rbp
4004ec:       48 89 e5                mov    rbp,rsp
4004ef:       48 83 ec 10             sub    rsp,0x10
4004f3:       be e7 03 00 00          mov    esi,0x3e7
4004f8:       bf 2a 00 00 00          mov    edi,0x2a
4004fd:       e8 b4 ff ff ff          call   4004b6 <maximum>
400502:       89 45 fc                mov    DWORD PTR [rbp-0x4],eax
