Disassembly of section .init:

0000000000400550 <_init>:
sub    rsp,0x8
mov    rax,QWORD PTR [rip+0x200a9d]        # 600ff8 <_DYNAMIC+0x1e0>
test   rax,rax
je     400565 <_init+0x15>
call   4005a0 <__libc_start_main@plt+0x10>
add    rsp,0x8
ret    
Disassembly of section .plt:

0000000000400570 <libfun@plt-0x10>:
push   QWORD PTR [rip+0x200a92]        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
jmp    QWORD PTR [rip+0x200a94]        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
nop    DWORD PTR [rax+0x0]

0000000000400580 <libfun@plt>:
jmp    QWORD PTR [rip+0x200a92]        # 601018 <_GLOBAL_OFFSET_TABLE_+0x18>
push   0x0
jmp    400570 <_init+0x20>

0000000000400590 <__libc_start_main@plt>:
jmp    QWORD PTR [rip+0x200a8a]        # 601020 <_GLOBAL_OFFSET_TABLE_+0x20>
push   0x1
jmp    400570 <_init+0x20>


Disassembly of section .got:
0000000000600ff8 <.got>:
...
Disassembly of section .got.plt:

0000000000601000 <_GLOBAL_OFFSET_TABLE_>:
...
