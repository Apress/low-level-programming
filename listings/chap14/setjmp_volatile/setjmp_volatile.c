#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

int main( int argc, char** argv ) {
    int var = 0;
    volatile int b = 0;
    setjmp( buf );
    if (b < 3) {
        b++;
        var ++;
        printf( "\n\n%d\n", var );
        longjmp( buf, 1 );
    }

    return 0;
}
