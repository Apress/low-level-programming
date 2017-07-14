0000000000400596 <llist_at>:
400596:       48 89 f8                mov    rax,rdi
400599:       48 85 f6                test   rsi,rsi
40059c:       74 0d                   je     4005ab <llist_at+0x15>
40059e:       48 85 c0                test   rax,rax
4005a1:       74 08                   je     4005ab <llist_at+0x15>
4005a3:       48 ff ce                dec    rsi
4005a6:       48 8b 00                mov    rax,QWORD PTR [rax]
4005a9:       eb ee                   jmp    400599 <llist_at+0x3>
4005ab:       c3                      ret
