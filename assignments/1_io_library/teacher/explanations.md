# Explanations for the io-library assignment

Here we provide explanations for the functions from io-library assignment from the original book.

The file `test.py` reads the `lib.inc` from the directory it is located and parses this file for testing purposes. So, let's
explain the `lib.inc`:

## Define code section

```asm
section .text
```

This defines code section, so we may put code under it.

## Define `string_length` function

The `string_length` function is very simple. At first, we ensure that `rax` is zero by using `xor rax, rax`. Then we start a loop
with looking for `\0` on each its iteration. The check for zero is done via `cmp`. We use `cmp byte [rdi+rax]` because we want
only to check the byte part, not the whole 64-bit integer. After check we either go to `.end` label which exits from the function
with `ret` instruction which pops return address from the stack and sets `RIP` to it, or continue the iteration by incrementing
`rax` value and going to next iteration.

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

To print a string you must know its length before printing it, because in `write` system call you must pass a size of data which you
want to write. Before calling the `string_length` function, it would be good to save our registers onto stack. Actually, using our
`string_length` implementation it is not necessary to save it, we should do this because the `string_length` can manipulate it
someday and the only thing we were told is that the `string_length` accepts its source string argument trough the `rdi` register,
we were told nothing about will it manipulate it or not, or do anything else. This is some kind of "calling convention". So,
we save `rdi` by pushing it onto stack before call and return it into `rsi` right after call because the `write` system call
gets data from `rsi` register, and more - `rdi` register is used for specifying destination file descriptor - `1` in our case,
which stands for `stdout`.

The source string (function argument) is passed through the `rdi` register. The function returns `void` in C-terminology, which
means it returns nothing (it is a procedure).

print_string:
    push rdi
    call string_length
    pop rsi
    mov rdx, rax 
    mov rax, 1
    mov rdi, 1 
    syscall
    ret
    
## Define `print_char` function

To print a char, we can use an already implemented `print_string` function. The `print_string` can be used because it accepts
a pointer to data which is a byte-array. Byte-array of course can consist of one character. In C we would pretend that
it is a one-item byte array, but in asm we actually don't need to do anything at all. We simply pass an address to this `char`
scalar. We should remember about `print_string` limitation and that it does not say how it will work with registers, so we
should save our state and restore after. Even though saving of `rdi` register is done in `print_string`, we don't know that as
we are a user of this code, not writer. Another advantage is that we allow `print_string` function to do anything with the `rdi`
because we saved it, and our `rdi` is actually a pointer to *our* stack which `print_string` can't manipulate at all. We should
restore the stack state after the job is done, so we `pop rdi` after calling the `print_string`.

The source character (function argument) is passed through the `rdi` register. The function returns `void` in C-terminology, which
means it returns nothing (it is a procedure).

print_char:
    push rdi
    mov rdi, rsp
    call print_string 
    pop rdi
    ret
    
## TODO
## Write other functions

# Recommendations

If you don't understand how something works, here or anywhere else in assembly language, just use a debugger, go through the code
step-by-step keeping the state of everything in your mind, and you'll understand what is going on, what was the developer meant
writing this code. I personally recommend `pwndbg` extension for `gdb` debugger, it has very useful features and user interface.
