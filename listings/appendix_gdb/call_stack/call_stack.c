#include <stdio.h>

void g(int garg) {
    int glocal = 99;
    puts("Inside g");
}

void f(int farg) {
    int flocal = 44;
    g( flocal );
}

int main( void ) {
    f( 42 );
    return 0;
}

