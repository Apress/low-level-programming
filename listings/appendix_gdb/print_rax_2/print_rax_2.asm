section .data                                                           
codes:                              
db      '0123456789ABCDEF'      

section .text                       
global _start                       
_start:                         
mov rax, 0x1122334455667788    

mov rdi, 1                  
mov rdx, 1                  
mov rcx, 64   
.loop:                            
push rax                    
sub rcx, 4   
sar rax, cl                 
and rax, 0xf                

lea rsi, [codes + rax]
mov rax, 1                  

push rcx                              
syscall                     
pop rcx                     

pop rax
test rcx, rcx
jnz .loop   

mov     rax, 60            ; invoke 'close' system call
xor     rdi, rdi
syscall
