/* This is a comment. The next line has a preprocessor directive */
#include <stdio.h>

/* `main` is the entry point for the program, like _start in assembly 
 * Actually, the hidden function _start is calling `main`.
 * `main` returns the `return code` which is then given to the `exit` system
 * call.
 * The `void` keyword instead of argument list means that `main` accepts no
 * arguments */
int main(void) { 
   /* A variable local to `main`. Will be destructed as soon as `main` ends*/
   int x = 43;
   int y;	
   y = x - 1;
   /* Calling a standard function `printf` with three arguments. 
    * It will print 'Hello, world! y=42 x=43
    * All %d will be replaced by the consecutive arguments */
   printf( "Hello, world! y=%d x=%d\n", y, x);

   return 0;
}
