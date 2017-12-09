# How to compile, link and run asm codes in Mac OS X?

Assume that we have a program named `hello_world.asm`:

```
; hello_world.asm
; ===============

global start                ; IMPORTANCE: don't underscore start (i.e _start)
                            ; otherwise the linker will complain!
section .data
db hello_string:    db  "Hello, world!", 10, 0

section .text

; main program
; ============
; We're about to make a syscall write(rdi, rsi, rdx)
; where:
; rdi - the file descriptor, in this case 1 (stdout)
; rsi - the buffer's address, i.e where is the data to be written out?
;       in our case, it is hello_string.
; rdx - the number of bytes to be written
start:
    ; write(rdi, rsi, rdx)
    mov rax, 0x2000004      ; write syscall number.
                            ; The actual syscall number for write is 4
                            ; but in order to make it work under Mac OS X
                            ; we have to add 0x2000000 to it before copying
                            ; into rax.

    mov rdi, 1              ; stdout
    mov rsi, hello_string   
    mov rdx, 14             ; the length of the hello_world string including
                            ; new line character (10) but not null character (0).  
    syscall 

    ; exit
    mov rax, 0x2000001      ; exit syscall number
    xor rdi, rdi            ; exit status
    syscall
```

Followings are steps to run this little program on Mac OS X system:

1. Compile: `nasm -f macho64 hello_world.asm`.
   
   This will output the file `hello_world.o` ready for the linker.

2. Linking: `ld -macosx_version_min 10.7.0 -lSystem -o hello_world`

   This will output the `hello_world` program ready to run.

3. Run: `./hello_world`

<b>NOTICE 1: </b>  If the `nasm` comes with Mac OS X doesn't support `macho64`
format, use [homebrew](https://brew.sh) to install the latest version of `nasm`.

In addition to that, you can use the command `nasm -hf` to check for all available formats.

<b>NOTICE 2: </b> Instead of manually typing those above commands whenever you want to
compile and run a program, you could employ `Makefile` to simplify the process. Here is the
example of `Makefile` for the above `hello_world.asm` program:

```
NASM=nasm -f macho64
LD=ld -macosx_version_min 10.7.0 -lSystem

# space separated list of targets (i.e executalbe object files)
# in this case, we have only one and we call it hello_world
all: hello_world

# where does this hello_world come from?
hello_world: hello_world.o
    $(LD) -o $@ $^

hello_world.o: hello_world.asm
    $(NASM) $<

clean:
    $(RM) *.o hello_world
```

# `lldb` as an alternative for `gdb`

<b>TODO</b>


