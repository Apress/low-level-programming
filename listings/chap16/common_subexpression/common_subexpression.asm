0000000000400516 <test>:
; rsi = x + 2
400516:       8d 77 02                lea    esi,[rdi+0x2]
400519:       31 c0                   xor    eax,eax
40051b:       0f af f7                imul   esi,edi
; rsi = x*(x+2)
40051e:       bf b4 05 40 00          mov    edi,0x4005b4
; rdx = rsi-1 = x*(x+2) - 1
400523:       8d 56 ff                lea    edx,[rsi-0x1]
; rsi = rsi + 1 = x*(x+2) - 1
400526:       ff c6                   inc    esi
400528:       e9 b3 fe ff ff          jmp    4003e0 <printf@plt>
