#include <stdio.h>

void f( void ) {
    char buffer[16];
    gets( buffer );
}

int main( int argc, char** argv ) {
    f();
    return 0;
}
