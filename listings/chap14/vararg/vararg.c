#include <stdarg.h>
#include <stdio.h>

void printer( unsigned long argcount, ... ) {
    va_list args;
    unsigned long i;
    va_start( args, argcount );
    for (i = 0; i < argcount; i++ )
        printf(" %d\n", va_arg(args, int )  );

    va_end( args );
}


int main () {
    printer(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 );
    return 0;
}
