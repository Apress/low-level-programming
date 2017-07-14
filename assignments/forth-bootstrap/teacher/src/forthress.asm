; ------------------------------------------------
; Forthress, a Forth dialect 
;
; Author: igorjirkov@gmail.com
; Date  : 15-10-2016
;
; This is the main Forthress file which defines the entry point
; Please define words inside "words.inc"
; last_word is dependent, it should be placed after all words are defined
; ------------------------------------------------

global _start
%include "macro.inc"
%include "util.inc"

%define pc r15
%define w r14
%define rstack r13

section .text

%include "words.inc"

section .bss

resq 1023
rstack_start: resq 1

input_buf: resb 1024
user_dict:  resq 65536 
user_mem: resq 65536

section .data 
state: dq 0
last_word: dq _lw
here: dq user_dict

section .rodata
msg_no_such_word: db ": no such word", 10, 0

section .text
next: 
    mov w, pc
    add pc, 8
    mov w, [w]
    jmp [w]

_start: jmp i_init

