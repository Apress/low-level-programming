; ------------------------------------------------
; Forthress, a Forth dialect 
;
; This file is storing the predefined words
; Check README.md in the root directory for
; word semantics
;
; Author: igorjirkov@gmail.com
; Date  : 15-10-2016
;
; ------------------------------------------------

; ( a -- )
native "drop", drop
    add rsp, 8
    jmp next

; ( a b -- b a )
native "swap", swap
    pop rax
    pop rdx
    push rax
    push rdx
    jmp next

; ( a -- a a )
native "dup", dup
    push qword [rsp]
    jmp next

; ( a b c -- b c a )
native "rot", rot
    pop rcx
    pop rdx
    pop rax
    push rdx
    push rcx
    push rax
    jmp next

; ( y x -- [ x + y ] )
native "+", plus
    pop rax
    add [rsp], rax
    jmp next

; ( y x -- [ x * y ] )
native "*", mul
    pop rax
    pop rdx
    imul rdx
    push rax 
    jmp next

; ( y x -- [ x / y ] )
native "/", div
    pop rcx
    pop rax
    cqo
    idiv rcx
    push rax 
    jmp next

; ( y x -- [ x mod y ] )
native "%", mod 
    pop rcx
    pop rax
    cqo
    idiv rcx
    push rdx 
    jmp next
; ( y x -- [x - y] )
native "-", minus
    pop rax
    sub [rsp], rax
    jmp next

; ( a -- a' )
; a' = 0 if a != 0
; a' = 1 if a == 0
native "not", not
    pop rax
    test rax, rax
    setz al
    movzx rax, al
    push rax
    jmp next

; ( a b -- c )
; c = 1 if a == b
; c = 0 if a != b
native "=", equals
    pop rax
    pop rdx
    cmp rax, rdx
    sete al
    movzx rax, al
    push rax
    jmp next

; ( str -- len )
native "count", count
    pop rdi
    call string_length
    push rax
    jmp next

; Drops element from stack and sends it to stdout
native ".", dot
    pop rdi
    call print_int
    call print_newline
    jmp next

; Shows stack contents. Does not pop elements
native ".S", show_stack
    mov rcx, rsp
    .loop:
        cmp rcx, [stack_base]
        jae next
        mov rdi, [rcx]
        push rcx
        call print_int
        call print_newline
        pop rcx
        add rcx, 8 
        jmp .loop
    
section .rodata
    interpreter_stub: dq xt_interpreter

; Stores the data stack base. It is useful for .S
section .data
    stack_base: dq 0
native "init", init
    mov qword [state], 0
    mov rstack, rstack_start
    mov pc, interpreter_stub
    cmp qword [stack_base], 0
    je  .first
    mov rsp, [stack_base]
    jmp next
    .first:
    mov [stack_base], rsp
    jmp next    

; This is the implementation of any colon-word.
; The XT itself is not used, but the implementation (i_docol) is.

native "docol", docol
    rpush pc
    add w, 8
    mov pc, w
    jmp next

; Exit from colon word
native "exit", exit
    rpop pc
    jmp next

; Pop from data stack into return stack
native ">r", to_r
    pop rax
    rpush rax
    jmp next

; Push from return stack into data stack
native "r>", from_r
    rpop rax
    push rax
    jmp next

; Non-destructive copy from the top of return stack 
; to the top of data stack
native "r@", r_fetch
    push qword [rstack]
    jmp next
 
colon "constant", constant
    
; ( str -- header_addr )
native "find", find
    mov rsi, [last_word]
.loop:
    mov rdi, [rsp] 
    push rsi
    add rsi, 9
    call string_equals
    pop rsi 
    test rax, rax
    jnz .found

    mov rsi, [rsi]
    test rsi, rsi
    jnz .loop
.not_found:
    mov qword [rsp], 0
    push 0
    jmp next
.found:
    mov [rsp], rsi
    jmp next 

; ( word_addr -- xt )
; Converts word header start address to the 
; execution token
native "cfa", cfa
    pop rsi
    add rsi, 9
    .loop:
    mov al, [rsi]
    test al, al
    jz .end
    inc rsi
    jmp .loop

    .end:
    add rsi, 2
    push rsi
    jmp next

; ( c -- )
; Outputs a single character to stdout
native "emit", emit
    pop rdi
    call print_char
    jmp next
  

; ( addr -- len ) 
; Reads word from stdin and stores it starting at address  
; Word length is pushed into stack
native "word", word
    pop rdi
    call read_word
    push rdx
    jmp next

; ( str -- len num ) 
; Parses an integer from string
native "number", number 
    pop rdi
    call parse_int
    push rax
    push rdx
    jmp next   

; ( addr -- ) 
; Prints a null-terminated string
native "prints", prints 
    pop rdi
    call print_string
    jmp next

; Exits Forthress
native "bye", bye
    mov rax, 60
    xor rdi, rdi
    syscall

; ( call_num a1 a2 a3 a4 a5 a6 -- new_rax )
; Executes syscall
; The following registers store arguments (according to ABI) 
; rdi , rsi , rdx , r10 , r8 and r9 
native "syscall", syscall
    pop r9
    pop r8
    pop r10
    pop rdx
    pop rsi
    pop rdi 
    pop rax
    syscall
    push rax
    jmp next

; Jump to a location. Location is an offset relative to the argument end
; F.e.: |xt_branch|   24 | <next command> 
;                         ^ branch adds 24 to this address and stores it in PC
; Branch is a compile-only word. 
native "branch", branch
    add pc, [pc]
    add pc, 8
    jmp next

; Jump to a location if TOS = 0. Location is calculated in a similar way
; F.e.: |xt_branch|   24 | <next command> 
;                         ^ branch adds 24 to this address and stores it in PC
; Branch0 is a compile-only word. 
native "0branch", branch0
    pop rax
    test rax, rax
    jnz .skip
    add pc, [pc]
    .skip:
    add pc, 8
    jmp next

; Pushes a value immediately following this XT
native "lit", lit
    push qword [pc]
    add pc, 8
    jmp next

; Address of the input buffer (is used by interpreter/compiler)
const inbuf, input_buf

; Address of user memory.  
const mem, user_mem 

; Last word address
const last_word, last_word 

; State cell address.
; The state cell stores either 1 (compilation mode) or 0 (interpretation mode)
const state, state

const here, [here]

; ( xt -- )
; Execute word with this execution token on TOS
native "execute", execute
    pop rax
    mov w, rax
    jmp [rax]


; ( addr -- value )
; Fetch value from memory
native "@", fetch
    pop rax
    push qword[rax]
    jmp next

; ( val addr -- ) 
; Store value by address
native "!", write
    pop rax
    pop rdx
    mov [rdx], rax
    jmp next

; ( addr -- char )
; Read one byte starting at addr
native "@c", fetch_char
    pop rax
    movzx rax, byte [rax]
    push rax
    jmp next

; ( x -- ) 
; Add x to the word being defined
native ",", comma
    mov rax, [here]
    pop qword [rax]
    add qword [here], 8
    jmp next

; ( c -- )
; Add a single byte to the word being defined
native "c,", char_comma
    mov rax, [here]
    pop rdx 
    mov [rax], dl 
    add qword[here], 1
    jmp next

; ( name flags --  )
; Create an entry in the dictionary
; name is the new name 
; only immediate flag is implemented ATM 
native "create", create
    ; link
    mov rcx, [last_word]
    mov rsi, [here]
    mov [rsi], rcx
    mov [last_word], rsi
    add rsi, 8
    mov byte [rsi], 0
    inc rsi
    
    ; name
    pop rdi
    push rsi
    call string_copy 
    pop rsi
    push rsi
    mov rdi, rsi
    call string_length
    pop rsi
    add rsi, rax
    ; flags
    inc rsi
    pop rax
    mov [rsi], al
    inc rsi
     
    mov [here], rsi
    jmp next

; Read word from stdin and start defining it
colon ":", colon
    .restart:
    dq xt_inbuf, xt_word
    branch0 .restart
    dq xt_lit, 0, xt_inbuf, xt_create
    dq xt_state, xt_lit, 1, xt_write
    dq xt_lit, i_docol, xt_comma
    dq xt_exit 

; End the current word definition
colon ";", semicolon, 1
    dq xt_state, xt_lit, 0, xt_write
    dq xt_lit, xt_exit, xt_comma
    dq xt_exit
   
; Forthress interpreter 
; Check the 'branch' and 'branch0' macros in 'macro.inc'
colon "interpreter", interpreter
.start:
    dq xt_inbuf, xt_word
    branch0 .end_of_input

    dq xt_inbuf, xt_find       ; find in dict

    dq xt_dup
    branch0 .number  ; if not found, try to parse as a number
    dq xt_cfa

    ; if compile
    dq xt_state, xt_fetch
    branch0 .interpreting

    ; if is immediate:
    dq xt_dup
    dq xt_lit, 1, xt_minus, xt_fetch_char, xt_not
    branch0 .interpreting

    ; compile
    dq xt_comma
    branch .start

    .interpreting: 
    dq xt_execute    
    branch .start 

    .number:
    dq xt_drop
    dq xt_drop
    dq xt_inbuf
    dq xt_number
    branch0 .no_word
  
    dq xt_state, xt_fetch  ; if interpreting, that's it
    branch0 .start
                           ; when compiling, check if it was after a branch
    dq xt_here, xt_lit, 8, xt_minus
    dq xt_lit, xt_branch0
    dq xt_equals, xt_not
    branch0 .is_branch
   
    dq xt_here, xt_lit, 8, xt_minus
    dq xt_lit, xt_branch
    dq xt_equals, xt_not
    branch0 .is_branch

    dq xt_lit, xt_lit, xt_comma

.is_branch: 
    dq xt_comma

    branch .start

    .no_word:
    dq xt_drop, xt_inbuf, xt_prints
    dq xt_lit, msg_no_such_word, xt_prints    
    branch .start

    .end_of_input:
    dq xt_bye
    dq xt_exit

