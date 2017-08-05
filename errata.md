# Errata

This file describes inaccuracies, typos, errors in the first edition.

The page number is provided first.

### Page 4.
* "... description, compared to a ~~calculation model~~ model of computation"

* "a modern computer from the simple schematic in ~~Figure 1-2~~ Figure 1-1".

### Page 6.

"~~zero division~~ division by zero"

### Page 8. 

"...while main memory uses ~~condensers~~ capacitors"

### Page 45.

"...fills the upper half of a wide register with ~~sign bit~~zero bits!"

### Page 57.  

"~~Use `print_string` routine...~~": the entire list item should be removed.

### Page 67. 

"... will also accept ~~`rip` and~~ `rflags` register~~s~~."

### Page 141.

"3. as ..." should be "3. * as ..."

### Page 257. 

In the listing `bmp_struct.c`, `struct` keyword should start with a lower case letter.

### Page 266.

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

### Page 303

"4. Defined in dynamic library and used globally.

~~Should be a part of linked list item rather than a paragraph on its own.~~ This is also done by using GOT (and PLT for functions)."
