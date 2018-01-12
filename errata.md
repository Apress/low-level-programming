# Errata

This file describes inaccuracies, typos, errors in the first edition.

The page number is provided first, then the section number. The sections are
important for those who read the Kindle version, since the page numbers differ
there. 


### Page 4, Section 1.1.2.
* "... description, compared to a ~~calculation model~~ model of computation"

* "a modern computer from the simple schematic in ~~Figure 1-2~~ Figure 1-1".

### Page 6, Section 1.2.3.

"~~zero division~~ division by zero"

### Page 8, Section 1.3. 

"...while main memory uses ~~condensers~~ capacitors"

### Page 10, Section 1.3.1

"The smallest parts ~~pf~~ of rsp"

### Page 11, Section 1.3.2
"Figure 1-3.  Approximation of Intel 64: general purpose registers"

To prevent confusion: `rip` and `rflags` are not general purpose registers, although they are shown on this figure. The name should be "general purpose registers, `rip` and `rflags`".

### Page 35, Section 2.7.

* In the table showing all functions to implement, `string_copy` should be placed after `string_length`. 
* `read_word` should also return word length in `rdx` when the value
  returned in `rax` is not 0.

* Footnote: 
" Their codes are 0x20, 0x9, and ~~0x10~~ 0xA, respectively."


### Page 38, Section 2.8
Question 44: 

Instead of `rax = 0x112233445567788`, should be `rax = 0x11 22 33 44 55 66 77 88` (missing 6).

### Page 45, Section 3.4.1.

"...fills the upper half of a wide register with ~~sign bit~~zero bits!"

### Page 45, Section 3.4.2.

CISC (~~Complete~~ Complex Instruction Set Computer)

### Page 57, Section 4.9.  

"~~Use `print_string` routine...~~": the entire list item should be removed.

### Page 67, Section 5.1.5. 

"... will also accept ~~`rip` and~~ `rflags` register~~s~~."

### Page 69, Section 5.1.6. 

"In case the argument is neither ~~string~~ number nor identifier,"

### Page 71, Section 5.1.9. 

"For each ~~_current_~~ _n_ up to _limit_"

### Page 73, Section 5.1.10

In Listing 5-19, "Mymacro" should be substituted with "mymacro".

### Page 74, Section 5.2

"For instance, the object file is completed separately from other files but refers to outside code and data.
It is not yet clear ~~whether~~ **where** that code or data will reside in memory"

### Page 81, Listing 5-28

Listing 5-28 depicts an erronous symbol table. Corrected listing:
[listings/chap5/objdump_tf/objdump_tf](listings/chap5/objdump_tf/objdump_tf)

### Page 83, Listing 5-31 

The `-shared` flag should be used when creating `libso.so` (third line), not
the executable. Corrected listing:
[listings/chap5/libso/libso](listings/chap5/libso/libso)

### Page 92, Section 6.1

"Thus, setting IOPL in an application individually allows us to forbid it from writing even if it is working
at a higher privilege level than the user applications."

"If the IOPL check has passed, the processor checks the bit corresponding to the used port. The operation proceeds only if this bit is not set."

Clarification:

There are two checks when a CPU tries to execute an instruction that works 
with I/O ports such as `in` or `out`.

1. The I/O privilege level check is performed to see, whether the application 
has a right to access any ports at all.

    This is done based on two special bits in `rflags` register. They encode a 
    privilege level of the task, called IOPL. This two-bit number is compared to
    the task's CPL (stored in `cs` register).

    If CPL > IOPL, the program has not enough privileges to access I/O ports at all.

    Otherwise, a second check is performed:

2.The I/O permission map is used to determine, whether we can access a specific
port or not (bit set to 1 means "forbidden").

### Pate 98, Section 6.3.2

Code segment shadow register:

* "Type = 11_~~2~~" -- this is not a binary 11, but a decimal one.

11 (dec) = 1011 (binary)

### Pate 99, Section 6.3.2

Same typo: 

Stack segment shadow register:

* "Type = 11_~~2~~" -- this is not a binary 11, but a decimal one.

11 (dec) = 1011 (binary)

### Page 108, Section 7.1.5
" * This way we handle ^ and ..."

This line should not be an isolated element of the bulleted list, but rather a part of 
a previous one.

### Page 113, Section 7.2.4

Figure 7-10: the "Dictionary Entry" block lacks 'flags' after 'dup0'.

Should be:

| link | d | u | p | 0 | flags | dup_impl |

### Page 118, Section 7.3

"...guaranteed to survive function calls unchanged (~~caller-saved~~__callee-saved__): r13, r14, or r15."

### Page 124, Section 

* `0branch <offset>` ~~Branch~~ `0branch` is a compile-only word. Jump to a location if TOS = 0.

Both `0branch` and `branch` are compile-only.

### Page 137, Section 8.3.5 

Then, as the break is not ending this case, after executing the first
~~`printf`~~ `puts` the control will fall to the next instruction labeled case
15, another ~~`printf`~~ `puts`.

### Page 141, Section 8.4.2.

"3. as ..." should be "3. * as ..."

### Page 171, Section 9.2.4

"... similar to how ~~DEFINE~~ `#define` works"

### Page 175, Section 9.4.1

Listing 9-54: the comment should be between `/*` and `*/`, but it is not closed
(lacks `*/`).

Corrected listing: [listings/chap9/macro_str/macro_str.c](listings/chap9/macro_str/macro_str.c).

### Page 186, Section 10.2.2

"while in the other object file ~~main.o~~ it is marked D"

### Page 189, Section 10.3

Listing 10-25 is not properly indented.


Corrected listing: [listings/chap10/ldd_locating_libc/ldd_locating_libc](listings/chap10/ldd_locating_libc/ldd_locating_libc).

### Page 199, Section 10.8

* Local variables (static or not) -- ~~internal~~ no linkage.

### Page 200, Section 10.9

"...studied include guards and learned to isolate functions and variables inside a file."

Clarification:

We learned how to separate programs in mutliple files correctly.

### Page 203, Section 11.1.3

"In other words, while assigning `short*` to `long*` is a clear error."

Missing `*` after `long`. Should be:

"In other words, while assigning `short*` to `long*` is a clear error."


### Page 204, Section 11.1.5
* This schematic might provoke confusion due to notation:

```c
int < unsigned int (unsigned  int)int <  unsigned  int
```

Read  `<` as an arrow.

```c
int <- unsigned int <- (unsigned  int)int <-  unsigned  int
```

* "Apparently, the result of this comparison will be almost always
equal to ~~0~~ __1__, which is wrong, because -1 is smaller than any unsigned integer."



### Page 205, Section 11.1.5


* This schematic might provoke confusion due to notation:

```c
signed long < unsigned int < long < (signed long)unsigned int
```


Read  `<` as an arrow.

```c
signed long <- unsigned int <- long <- (signed long)unsigned int
```

### Page 214, Section 11.5


"As we have chosen the GNU/Linux 64-bit system for studying purposes, ~~it~~ our data model is LP64."

"The `printf` function (and similar format input/output ~~)~~ functions ..."

### Page 229, Section 12.2.5

In Listing 12-7, the line has a typo in `::=` notation. :

```
<expr0> = <expr1> "+" <expr> | <expr1> "-" <expr> | <expr1>
```

should be:

```
<expr0> ::= <expr1> "+" <expr> | <expr1> "-" <expr> | <expr1>
```

### Page 232, Section 12.3.1

"The compiler has ~~two~~ to do two things each time _any_ pointer..."

### Page 233, Section 12.3.1

"Writing out of block bounds (but close to them) is likely to corrupt this
information, which will result in a crash during one of future calls to malloc
~~of~~ or free, making this bug a time-bomb."

### Page 239, Section 12.6

"We then introduced the notion of pragmatics. ~~ and elaborated one of the most
important things~~"

### Page 242, Sectino 13.1

* Listing 13-1 is wrong. It shows an example of good `list_sum`, where the list is
__not__ traversed from the beginning on each access. Corrected listing shows both
good and bad versions:
[listings/chap13/list_sum_bad/list_sum_bad.c](listings/chap13/list_sum_bad/list_sum_bad.c)

* "Sometimes the task demands the opposite. For example, if we are writing the code for a controller in
absence of a good optimizing compiler and with very restricted resources,..."

Clarification: here "controller" has a meaning of a hardware piece, microcontroller. 

### Page 257, Section 13.10.1. 

In the listing `bmp_struct.c`, `struct` keyword should start with a lower case letter.

### Page 252, Section 13.6

The line 

```
assert: assert.c:6: main: Assertion 'x != 0' failed.
```

should be substituted with:

```
assert: assert.c:4: main: Assertion 'x != 0' failed.
```

### Page 257, Section 13.10.1

In Listing 13-16, `Struct` should be `struct`.

### Page 258

"To achieve that, define a structure ~~`structure`~~ `image` "


### Page 266, Section 14.1.2.

"It means that the ~~last~~ first argument __after those passed in registers__ will be on top of the stack before the call is performed."

Example:

```c
int f(int, int, int, int, int, int, int, int, int, int);

...
f(1,2,3,4,5,6,7,8,9,10);
```

The call of `f` will be translated as follows:

```asm
push       10 
push        9
push        8
push        7
mov    r9,  6
mov    r8,  5
mov    rcx, 4
mov    rdx, 3
mov    rsi, 2
mov    rdi, 1 
```

### Page 267, Section 14.1.2.

An important addition for the third item: when `call` is executed, the stackshould be 16-bit aligned. Some compiled functions will count on that. 

### Page 268, Section 14.1.3.

`maximum.c` should be compiled with `-fno-stack-protector` flag. [Related discussion](https://github.com/Apress/low-level-programming/issues/28)


### Page 286, Section 14.7.3

There are several typos on this page, which revolve around the number of "%x" in the program input. The correct number of "%x"'s for this example should be __9__.

* The launch string and a sample output will look like that:

```
> ./printf_vuln <<< "%x %x %x %x %x %x %x %x %x"
21a902a fb79a790 fb7988e0 21a902b 0 25207825 20782520 78252078 fb007825%   
```

  Note that `<<<` in Bash means that the latter string will be directed directly
  to the program __stdin__.

* As we see, it actually gave us four numbers that share a certain informal
similarity, a 0 and ~~two~~ four more numbers. Our hypothesis is that the last
~~two~~ four numbers are taken from the stack already.



### Page 291, Section 15.1

* "...the other program has to interfere (i.e., dynamic loader **or dynamic linker**)."
* "Perform relocation of the ~~applications and dependencies~~ application and its dependencies."


### Page 296, Section 15.4.1

This place is a part of ~~GOT~~ the .rodata section.

### Page 303, Section 15.6

"4. Defined in dynamic library and used globally.

~~Should be a part of linked list item rather than a paragraph on its own.~~ 


### Page 304, Section 15.7.1

Notice that the global symbol `sofun` is marked as ~~`:func`~~ *`:function`*


### Page 311, Section 15.8

* "crti and ~~crto~~ crtn contain the prologue and epilogue ..."

* Need spaces between "of" and `__init`, "of" and `__fini` in the sentence:
"the prologue and epilogue of `__init` function (and likewise for `__fini` function)."


### Page 322, Section 15.10.5

The variables not visible ~~as~~ **from** other objects.

### Page 324, Section 15.11

Question 305: Can we share a ~~**.data**~~ **.rodata** section when it is being relocated?

### Page 330, Section 16.1.3

Short version: The Listing 16-2 shows an example that triggers undefined behavior, but works in most cases. On some systems another example works more stable, which is why we are replacing this listing with another one.

In the old listing, when the condition "`rbx` is 0" is matched, the stack unwinding stops. We rely on the fact that the link to the previous stack frame turns zero somewhere around `main` and `_start` functions. However in reality it is not enforced for the first function called to store anything near its return address, so Kunio Yoshikawa made another example. There, a condition to stop unwinding stack revolves around an address of a local variable of `main` function. 

Corrected listing:
[listings/chap16/stack_unwind/stack_unwind.asm](listings/chap16/stack_unwind/stack_unwind.asm)
### Page 336, Section 16.1.7

Clarification: The `nop` instructions after `ret` in listings 16-15 and 16-16 are just there because of disassembler's incapability of finding the function end address. They are not needed.


### Page 340, Section 16.2.1

"Instructions and ~~code~~ data inhabit virtually always..."

### Page 341, Section 16.2.2
`Void` should be `void`.

### Page 344, Section 16.2.3

The last sentence should not be there:

"... the results for no prefetch, while Listing 16-25 shows the results with
prefetching. I corresponds to instruction cache, D to the data cache, LL – Last
Level Cache). ~~There are almost 100% data cache misses, which is very bad.~~""


### Page 348, Section 16.2.5

The sentense "There are almost 100% data cache misses, which is very bad." belongs here. The line between two cache diagnostic outputs should be:


"There are almost 100% data cache misses, which is very bad. As we see, accessing memory sequentially decreases cache misses radically:"


### Page 351, Section 16.4

`unpckhpd` -- Unpack and Interleave High Packed Double
`unpcklps` -- Unpack and Interleave Low Packed Double
`packsswb` -- Pack with Signed Saturation
`packusswb` -- Pack with Unsigned Saturation 


### Page 352, Section 16.4.1

In listing 16-32, one coefficient for sepia transformation is off: it is `.543f` instead of `.534f`:


```c
 static const float c[3][3] =  {
    { .393f, .769f, .189f },
    { .349f, .686f, .168f },
    { .272f, .543f, .131f } }; 
```

Corrected listing:
[listings/chap16/image_sepia_c_example/image_sepia_c_example.c](listings/chap16/image_sepia_c_example/image_sepia_c_example.c)

### Page 360, Section 17.4

* `Mov` should be `mov` in

```asm
mov rdx, [rbx]
mov rax, [rdx]
```


* In C this is the situation when we use the ~~➤~~ `->` operator to get to a
  field of a certain structure through the pointer to that structure.
  
### Page 373, Section 17.4

"We create a type to hold the information about single task called `struct
fact_task`. It includes the number itself, the range bounds ~~to~~ `from` and `to`, and the
slot for the result, ..." 

### Page 403, Section 17.8.5

To dispose of a mutex, the call to ~~`pthread_mutex_unlock`~~ `pthread_mutex_destroy` is used.


### Page 384, Section 17.9

After "For more information on semaphores, refer to the man pages for the following functions:", the bullet list starts with a wrong item. `em_close` should be `sem_close`


### Page 385, Section 17.10

Clarification:

"In a multiprocessor system, stores to the same location have a total order."

This was taken from from "Intel® 64 and IA-32 Architectures Software Developer’s Manual". However the wording is changed now to: 

"Any two stores are seen in a consistent orderby processors other than those performing the stores"


### Page 403, Appendix A 

The right command to examine 8 bytes is `x /xg`, where `/xg` is a hexadecimal (x) 8-byte (g) format string.

So, the correct version would be:


* "Examine the top 8 bytes of the stack:

```
(gdb) x /xg $rsp
0x7fffffffdf90: 0x0000000000000001
```

* Examine the second qword stored in the stack:

```
(gdb) x/xg $rsp+8
0x7fffffffd168:	0x00007fffffffd513
```


### Page 410, Section 19.2 

"The target program should produce the file program. To do it we should build
files `main.o` and `lib.o` first. If we change the file ~~`main.o`~~ `main.asm` and ...


### Page 417, Section 20.4

The `close` system call has an erroneous description.
The correct version follows:

```c
int close(int fd)
```

Close the file with the given **descriptor**.

| rax | rdi | rsi | rdx | r10 | r8  | r9  |
| --- | --- | --- | --- | --- | --- | --- |
| 3   | fd  |     |     |     |     |     |

Arguments:
1. `fd`   a valid file descriptor that should be closed.

Returns `rax` = zero on success, -1 on error. Global variable `errno` holds the error code.
Includes to use in C:

```c
#include <unistd.h>
```


### Page 419, Section 20.4

"Returns `rax` = zero ~~un~~ on success, -1 on error."
