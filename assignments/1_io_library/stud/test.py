#!/usr/bin/python

import os
import subprocess
import sys
import re
import sys
from subprocess import CalledProcessError, Popen, PIPE
from termcolor import colored

#-------helpers---------------

def starts_uint( s ):
    matches = re.findall('^\d+', s)
    if matches:
        return (int(matches[0]), len(matches[0]))
    else:
        return (0, 0)

def starts_int( s ):
    matches = re.findall('^-?\d+', s)
    if matches:
        return (int(matches[0]), len(matches[0]))
    else:
        return (0, 0)

def unsigned_reinterpret(x):
    if x < 0:
        return x + 2**64
    else:
        return x

def first_or_empty( s ):
    sp = s.split()
    if sp == [] : 
        return ''
    else:
        return sp[0]

#-----------------------------

def compile( fname, text ):
    f = open( fname + '.asm', 'w')
    f.write( text )
    f.close()

    if subprocess.call( ['nasm', '-f', 'elf64', fname + '.asm', '-o', fname+'.o'] ) == 0 and subprocess.call( ['ld', '-o' , fname, fname+'.o'] ) == 0:
             print ' ', fname, ': compiled'
             return True
    else: 
        print ' ', fname, ': failed to compile'
        return False


def launch( fname, seed = '' ):
    output = ''
    try:
        p = Popen(['./'+fname], shell=None, stdin=PIPE, stdout=PIPE)
        (output, err) = p.communicate(input=seed)
        return (output, p.returncode)
    except CalledProcessError as exc:
        return (exc.output, exc.returncode)
    else:
        return (output, 0)



def test_asm( text, name = 'dummy',  seed = '' ):
    if compile( name, text ):
        r = launch( name, seed )
        #os.remove( name )
        #os.remove( name + '.o' )
        #os.remove( name + '.asm' )
        return r 
    return None 

class Test:
    name = ''
    string = lambda x : x
    checker = lambda input, output, code : False

    def __init__(self, name, stringctor, checker):
        self.checker = checker
        self.string = stringctor
        self.name = name
    def perform(self, arg):
        res = test_asm( self.string(arg), self.name, arg)
        if res is None:
            return False
        (output, code) = res
        print '"', arg,'" ->',  res
        return self.checker( arg, output, code )

before_call="""
mov rdi, -1
mov rsi, -1
mov rax, -1
mov rcx, -1
mov rdx, -1
mov r8, -1
mov r9, -1
mov r10, -1
mov r11, -1
push rbx
push rbp
push r12 
push r13 
push r14 
push r15 
"""
after_call="""
cmp r15, [rsp] 
jne .convention_error
pop r15
cmp r14, [rsp] 
jne .convention_error
pop r14
cmp r13, [rsp] 
jne .convention_error
pop r13
cmp r12, [rsp] 
jne .convention_error
pop r12
cmp rbp, [rsp] 
jne .convention_error
pop rbp
cmp rbx, [rsp] 
jne .convention_error
pop rbx

jmp continue

.convention_error:
    mov rax, 1
    mov rdi, 2
    mov rsi, err_calling_convention
    mov rdx,  err_calling_convention.end - err_calling_convention
    syscall
    mov rax, 60
    mov rdi, -41
    syscall
section .data
err_calling_convention: db "You did not respect the calling convention! Check that you handled caller-saved and callee-saved registers correctly", 10
.end:
section .text
continue:
"""
tests=[ Test('string_length',
             lambda v : """section .data
        str: db '""" + v + """', 0
        section .text
        %include "lib.inc"
        global _start
        _start:
        """ + before_call + """
        mov rdi, str
        call string_length
        """ + after_call + """
        mov rdi, rax
        mov rax, 60
        syscall""",
        lambda i, o, r: r == len(i)
         ),

        Test('print_string',
             lambda v : """section .data
        str: db '""" + v + """', 0
        section .text
        %include "lib.inc"
        global _start 
        _start:
        """ + before_call + """
        mov rdi, str
        call print_string
        """ + after_call + """

        mov rax, 60
        xor rdi, rdi
        syscall""", 
        lambda i,o,r: i == o),

        Test('string_copy',
            lambda v: """
        section .data
        arg1: db '""" + v + """', 0
        arg2: times """ + str(len(v) + 1) +  """ db  66
        section .text
        %include "lib.inc"
        global _start 
        _start:
        """ + before_call + """
        mov rdi, arg1
        mov rsi, arg2
        mov rdx, """ + str(len(v) + 1) + """
        call string_copy

        """ + after_call + """
        mov rdi, arg2 
        call print_string
        mov rax, 60
        xor rdi, rdi
        syscall""", 
        lambda i,o,r: i == o),

        Test('print_char',
            lambda v:""" section .text
        %include "lib.inc"
        global _start 
        _start:
        """ + before_call + """
        mov rdi, '""" + v + """'
        call print_char
        """ + after_call + """
        mov rax, 60
        xor rdi, rdi
        syscall""", 
        lambda i,o,r: i == o),

        Test('print_uint',
            lambda v: """section .text
        %include "lib.inc"
        global _start 
        _start:
        """ + before_call + """
        mov rdi, """ + v + """
        call print_uint
        """ + after_call + """
        mov rax, 60
        xor rdi, rdi
        syscall""", 
        lambda i, o, r: o == str(unsigned_reinterpret(int(i)))),
        
        Test('print_int',
            lambda v: """section .text
        %include "lib.inc"
        global _start 
        _start:
        """ + before_call + """
        mov rdi, """ + v + """
        call print_int
        """ + after_call + """
        mov rax, 60
        xor rdi, rdi
        syscall""", 
        lambda i, o, r: o == i),

        Test('read_char',
             lambda v:"""section .text
        %include "lib.inc"
        global _start 
        _start:
        """ + before_call + """
        call read_char
        """ + after_call + """
        mov rdi, rax
        mov rax, 60
        syscall""", 
        lambda i, o, r: (i == "" and r == 0 ) or ord( i[0] ) == r ),

        Test('read_word',
             lambda v:"""
        section .data
        word_buf: times 20 db 0xca
        section .text
        %include "lib.inc"
        global _start 
        _start:
        """ + before_call + """
        mov rdi, word_buf
        mov rsi, 20 
        call read_word
        """ + after_call + """
        mov rdi, rax
        call print_string

        mov rax, 60
        xor rdi, rdi
        syscall""", 
        lambda i, o, r: first_or_empty(i) == o),

        Test('read_word_length',
             lambda v:"""
        section .data
        word_buf: times 20 db 0xca
        section .text
        %include "lib.inc"
        global _start 
        _start:
        """ + before_call + """
        mov rdi, word_buf
        mov rsi, 20 
        call read_word
        """ + after_call + """

        mov rax, 60
        mov rdi, rdx
        syscall""", 
        lambda i, o, r: len(first_or_empty(i)) == r or len(first_or_empty(i)) > 19),

        Test('read_word_too_long',
             lambda v:"""
        section .data
        word_buf: times 20 db 0xca
        section .text
        %include "lib.inc"
        global _start 
        _start:
        """ + before_call + """
        mov rdi, word_buf
        mov rsi, 20 
        call read_word
        """ + after_call + """

        mov rdi, rax
        mov rax, 60
        syscall""", 
        lambda i, o, r: ( (not len(first_or_empty(i)) > 19) and r != 0 ) or  r == 0 ),

        Test('parse_uint',
             lambda v: """section .data
        input: db '""" + v  + """', 0
        section .text
        %include "lib.inc"
        global _start 
        _start:
        """ + before_call + """
        mov rdi, input
        call parse_uint
        """ + after_call + """
        push rdx
        mov rdi, rax
        call print_uint
        mov rax, 60
        pop rdi
        syscall""", 
        lambda i,o,r:  starts_uint(i)[0] == int(o) and r == starts_uint( i )[1]),
        
        Test('parse_int',
             lambda v: """section .data
        input: db '""" + v  + """', 0
        section .text
        %include "lib.inc"
        global _start 
        _start:
        """ + before_call + """
        mov rdi, input
        call parse_int
        """ + after_call + """
        push rdx
        mov rdi, rax
        call print_int
        pop rdi
        mov rax, 60
        syscall""", 
        lambda i,o,r: (starts_int( i )[1] == 0 and int(o) == 0) or (starts_int(i)[0] == int(o) and r == starts_int( i )[1] )),

        Test('string_equals',
             lambda v: """section .data
             str1: db '""" + v + """',0
             str2: db '""" + v + """',0
        section .text
        %include "lib.inc"
        global _start
        _start:
        """ + before_call + """
        mov rdi, str1
        mov rsi, str2
        call string_equals
        """ + after_call + """
        mov rdi, rax
        mov rax, 60
        syscall""",
        lambda i,o,r: r == 1),
 
        Test('string_equals not equals',
             lambda v: """section .data
             str1: db '""" + v + """',0
             str2: db '""" + v + """!!',0
        section .text
        %include "lib.inc"
        global _start
        _start:
        """ + before_call + """
        mov rdi, str1
        mov rsi, str2
        call string_equals
        """ + after_call + """
        mov rdi, rax
        mov rax, 60
        syscall""",
        lambda i,o,r: r == 0),

        Test('string_copy_too_long',
            lambda v: """
            section .rodata
            err_too_long_msg: db "string is too long", 10, 0
            section .data
        arg1: db '""" + v + """', 0
        arg2: times """ + str(len(v)/2)  +  """ db  66
        section .text
        %include "lib.inc"
        global _start 
        _start:
        """ + before_call + """
        mov rdi, arg1
        mov rsi, arg2
        mov rdx, """ + str(len(v)/2 ) + """
        call string_copy
        test rax, rax
        jnz .good
        mov rdi, err_too_long_msg 
        call print_string
        jmp _exit
        .good:
        """ + after_call + """
        mov rdi, arg2 
        call print_string
        _exit:
        mov rax, 60
        xor rdi, rdi
        syscall""", 
        lambda i,o,r: o.find("too long") != -1 ) 
        ]


inputs= {'string_length' 
        : [ 'asdkbasdka', 'qwe qweqe qe', ''],
         'print_string'  
         : ['ashdb asdhabs dahb', ' ', ''],
         'string_copy'   
         : ['ashdb asdhabs dahb', ' ', ''],
         'string_copy_too_long'   
         : ['ashdb asdhabs dahb', ' ', ''],
         'print_char'    
         : "a c",
         'print_uint'    
         : ['-1', '12345234121', '0', '12312312', '123123'],
         'print_int'     
         : ['-1', '-12345234121', '0', '123412312', '123123'],
         'read_char'            
         : ['-1', '-1234asdasd5234121', '', '   ', '\t   ', 'hey ya ye ya', 'hello world' ],
         'read_word'            
         : ['-1'], # , '-1234asdasd5234121', '', '   ', '\t   ', 'hey ya ye ya', 'hello world' ],
         'read_word_length'     
         : ['-1', '-1234asdasd5234121', '', '   ', '\t   ', 'hey ya ye ya', 'hello world' ],
         'read_word_too_long'     
         : [ 'asdbaskdbaksvbaskvhbashvbasdasdads wewe', 'short' ],
         'parse_uint'           
         : ["0", "1234567890987654321hehehey", "1" ],
         'parse_int'                
         : ["0", "1234567890987654321hehehey", "-1dasda", "-eedea", "-123123123", "1" ],
         'string_equals'            
         : ['ashdb asdhabs dahb', ' ', '', "asd" ],
         'string_equals not equals' 
         : ['ashdb asdhabs dahb', ' ', '', "asd" ]
}
              
if __name__ == "__main__":
    found_error = False
    for t in tests:
        for arg in inputs[t.name]:
            if not found_error:
                try:
                    print '          testing', t.name,'on "'+ arg +'"'
                    res = t.perform(arg)
                    if res: 
                        print '  [', colored('  ok  ', 'green'), ']'
                    else:
                        print '* [ ', colored('fail', 'red'),  ']'
                        found_error = True
                except:
                    print '* [ ', colored('fail', 'red'),  '] with exception' , sys.exc_info()[0]
                    found_error = True
    if found_error:
        print 'Not all tests have been passed'
    else:
        print colored( "Good work, all tests are passed", 'green')
