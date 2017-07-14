%include "lib.inc"

global _start

%define pc r15
%define w r14
%define rstack r13

section .bss
resq 1023
rstack_start: resq 1
input_buf: resb 1024


section .text

; this one cell is the program
main_stub: dq xt_main

; The dictionary starts here
; The first word is shown in full
; Then we omit flags and links between nodes for brevity
; Each word stores an address of its assembly implementation

; Drops the topmost element from the stack
dq 0 ; There is no previous node
db "drop", 0
db 0 ; Flags = 0
xt_drop: dq i_drop
i_drop:
    add rsp, 8
    jmp next

; Initializes registers
xt_init: dq i_init
i_init:
    mov rstack, rstack_start
    mov pc, main_stub
    jmp next    

; Saves PC when the colon word starts
xt_docol: dq i_docol
i_docol:
    sub rstack, 8
    mov [rstack], pc
    add w, 8
    mov pc, w
    jmp next

; Returns from the colon word
xt_exit: dq i_exit
i_exit: 
    mov pc, [rstack]
    add rstack, 8
    jmp next

; Takes a buffer pointer from stack
; Reads a word from input and stores it
; starting in the given buffer
xt_word: dq i_word
i_word:
    pop rdi
    call read_word
    push rdx
    jmp next

; Takes a pointer to a string from the stack
; and prints it 
xt_prints: dq i_prints
i_prints:
    pop rdi
    call print_string
    jmp next

; Exits program
xt_bye: dq i_bye
i_bye: 
    mov rax, 60
    xor rdi, rdi
    syscall

; Loads the predefined buffer address
xt_inbuf: dq i_inbuf
i_inbuf:
    push qword input_buf
    jmp next

; This is a colon word, it stores 
; execution tokens. Each token
; corresponds to a Forth word to be
; executed
xt_main: dq i_docol
    dq xt_inbuf
    dq xt_word
    dq xt_drop
    dq xt_inbuf
    dq xt_prints
    dq xt_bye

; The inner interpreter. These three lines
; fetch the next instruction and start its
; execution
next: 
    mov w, [pc]
    add pc, 8
    jmp [w]

; The program starts execution from the init word
_start: jmp i_init 



