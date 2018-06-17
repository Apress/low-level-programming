# Explanations for the io-library assignment

Here we provide explanations for the functions from io-library assignment from the original book.

The file `test.py` reads the `lib.inc` from the directory it is located and parses this file for testing purposes. So, let's
explain the `lib.inc`:

## Define code section

```asm
section .text
```

This defines code section, so we may put our code under it.

## Define `string_length` function

The `string_length` function is very simple. At first, we ensure that `rax` is zero by using `xor rax, rax`. Then we start a loop
with looking for `\0` on each its iteration. The check for zero is done via `cmp`. We use `cmp byte [rdi+rax]` because we want
only to check the byte part, not the whole 64-bit integer. The square brackets (`[` and `]`) is the **indirect adressing**
notation. The `[rdi+rax]` is a notation of **relative addressing** - we operate on a byte which starts from `rdi` with `rax`
offset. After check we either go to `.end` label which exits from the function with `ret` instruction which pops return address
from the stack and sets `RIP` to it, or continue the iteration by incrementing `rax` value and going to next iteration.

The source string (function argument) is passed through the `rdi` register. The function returns calculated string length through
the `rax` register.

```asm
string_length:
    xor rax, rax
.loop:
    cmp byte [rdi+rax], 0
    je .end 
    inc rax
    jmp .loop 
.end:
    ret
```

## Define `print_string` function

To print a string you must know its length before printing it, because in `write` system call you must pass a size of data which
you want to write. Before calling the `string_length` function, it would be good to save our registers onto stack. Actually, using our `string_length` implementation, it is not necessary to save it, we should do this because the `string_length` can
manipulate it someday and the only thing we were told is that the `string_length` accepts its source string argument through the
`rdi` register, we were told nothing about will it manipulate it or not, or do anything else. This is some kind of "calling convention". So, we save `rdi` by pushing it onto stack before the call and return it into `rsi` right after call, because the
`write` system call gets data from `rsi` register, and more - `rdi` register is used for specifying destination file descriptor
- `1` in our case, which stands for `stdout`.

The source string (function argument) is passed through the `rdi` register. The function returns `void` in C-terminology, which
means it returns nothing (it is a procedure).

```asm
print_string:
    push rdi
    call string_length
    pop rsi
    mov rdx, rax 
    mov rax, 1
    mov rdi, 1 
    syscall
    ret
```
    
## Define `print_char` function

To print a char, we can use an already implemented `print_string` function. The `print_string` can be used because it accepts
a pointer to data which is a byte-array. Byte-array of course can consist of one character. In C we would pretend that
it is a one-item byte array, but in asm we actually don't need to do anything at all. We simply pass an address to this `char`
scalar. We should remember about `print_string` limitation and that it does not say how it will work with registers, so we
should save our state and restore after. Even though saving of `rdi` register is done in `print_string`, we don't know that, as
we are a user of this code, not writer. Another advantage is that we allow `print_string` function to do anything with the `rdi`
because we saved it, and our `rdi` is actually a pointer to *our* stack which `print_string` can't manipulate at all. We should
restore the stack state after the job is done, so we `pop rdi` after calling the `print_string`.

The source character (function argument) is passed through the `rdi` register. The function returns `void` in C-terminology, which means it returns nothing (it is a procedure).

```asm
print_char:
    push rdi
    mov rdi, rsp
    call print_string 
    pop rdi
    ret
```

## Define `print_uint` function

Printing number is a little bit tricky thing. People familiar with C may know how to convert a number into string, because
the algorithm is very simple:

1. Get the source number.
2. Get the latest digit by taking a remainder of division by 10.
3. For converting it to ASCII-character, we simply [add `0x30` (or 48)](https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html) to it.
4. Pushing it into an array, in reverse order, so that if we continue further, we will be able to read it in correct order.

Here, in assembly language, the basics are the same, but the implementation is of course, different in many ways. We will need a loop, of course, as same as we will need taking a remainder of division by 10 but we will not use any arrays. We will allocate
memory on stack and modify the contents right in there, and pass the pointer to the stack to the `print_string` function.

Let's start with copying `rdi` into `rax` because we will need to modify the `rdi` register later. Then, we need to keep current
`rsp` address in `rdi` because it will point to the end of our number's string representation on the stack later. We also will have to know the future string's ending, so we push `0` onto the stack marking it the end of the our string. Then we allocate
16 bytes on the stack for our string by `sub rsp, 16`. Remember, that the stack grows to lower addresses from higher addresses? That is why the use `sub` for allocation, we move the `rsp` (stack pointer) down to lower addresses by 16 bytes. We then prepare
our division loop by pointing `rdi` to the first byte of our string on the stack and setting our divider into `r8` register.

Our loop starts with resetting `rdx` so we are sure we don't have a garbage in it. Then we perform the division and add `0x30`
via `or` command (a tricky-thing, yes). As you may know, applying bitwise or simply sets the bits in the source register, if
they were not set before. We absolutely know that they were not set because *we* are the one who set the number by division, and
it contains a number between 0 and 9 (between `0000` and `1001`) while `0x30` (48 in decimal) is `110000`, so we will never touch
the number part of register.  Then, we decrement `rdi` (which points to stack, remember?) again and set the number we just calculated (digit + `0x30`) into the value currently pointed by `rdi` register. As the last step, we check whether the remainder is zero after our manipulations (made by `div` instruction) and if it is, we exit the loop, otherwise we continue until it is zero.

After our loop is finished, the `rdi` is pointed to the beginning of our new string on the stack, so we may safely call 
`print_string` function (it accepts its source string argument through the `rdi`, remember?). As we are good programmers and
we don't want to blow up the stack and to interrupt the program execution, we must deallocate the allocated stack memory (like
`free` in *C* or `delete` in *C++* when you are manipulating the memory manually - as we did here with stack by `sub`), we use
`add rsp, 24`. You may wonder why `24`, this is because we also added `0` onto the stack so we actually moved it by `8` and by
`16` bytes during the function execution, hence `24`. We must delete it too, because we must restore the stack after our job
is done, so we move the stack pointer up by `24` bytes and not `16`. We may have a useless number in the `rdi` register after our
manipulations, so it is good to reset it. Note, that we could also do this by `xor` instruction, or we could store it on the
stack before everything and then just pop it after, so the `print_uint` function user will keep the number in the `rdi` register
untouched after the call.

The source number (function argument) is passed through the `rdi` register. The function returns `void` in C-terminology, which means it returns nothing (it is a procedure).

```asm
print_uint:
    mov rax, rdi
    mov rdi, rsp
    push 0
    sub rsp, 16

    dec rdi
    mov r8, 10

.loop:
    xor rdx, rdx
    div r8
    or  dl, 0x30
    dec rdi
    mov [rdi], dl
    test rax, rax
    jnz .loop

    call print_string

    add rsp, 24
    mov rdi, 0
    ret

```
    
## TODO
## Write other functions

# Recommendations

If you don't understand how something works, here or anywhere else in assembly language, just use a debugger, go through the code
step-by-step keeping the state of everything in your mind, and you'll understand what is going on, what developer meant
writing this code. I personally recommend `pwndbg` extension for `gdb` debugger, it has very useful features and user interface.
