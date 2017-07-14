section .text
global sse

; rdi = x, rsi = y
sse:
    movdqa xmm0, [rdi]
    mulps  xmm0, [rsi]
    addps  xmm0, [rsi]
    movdqa [rdi], xmm0 
    ret 
