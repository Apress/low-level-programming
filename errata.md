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

### Page 35, Section 2.7.

* `read_word` should also return word length in `rdx` when the value
  returned in `rax` is not 0.

* Footnote: 
" Their codes are 0x20, 0x9, and ~~0x10~~ 0xA, respectively."


### Page 37, Section 1.3.2
"Figure 1-3.  Approximation of Intel 64: general purpose registers"

To prevent confusion: `rip` and `rflags` are not general purpose registers, although they are shown on this figure. The name should be "general purpose registers, `rip` and `rflags`".

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

### Page 83, Listing 5-31 

The `-shared` flag should be used when creating `libso.so` (third line), not
the executable. Corrected listing:
[listings/chap5/libso/libso](listings/chap5/libso/libso)

### Page 92, Section 6.1

"Thus, setting IOPL in an application individually allows us to forbid it from writing even if it is working
at a higher privilege level than the user applications."

TODO clarify

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

### Page 189, Section 10.3

Listing 10-25 is not properly indented.


Corrected listing: [listings/chap10/ldd_locating_libc/ldd_locating_libc](listings/chap10/ldd_locating_libc/ldd_locating_libc).



### Page 257, Section 13.10.1. 

In the listing `bmp_struct.c`, `struct` keyword should start with a lower case letter.

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

### Page 291, Section 15.1

Perform relocation of the ~~applications and dependencies~~ application and its dependencies.

### Page 296, Section 15.4.1

This place is a part of ~~GOT~~ the .rodata section.

### Page 303, Section 15.6

"4. Defined in dynamic library and used globally.

~~Should be a part of linked list item rather than a paragraph on its own.~~ This is also done by using GOT (and PLT for functions)."

### Page 311, Section 15.8

"crti and ~~crto~~ crtn contain the prologue and epilogue ..."
