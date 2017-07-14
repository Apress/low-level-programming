#include <stdio.h>

int main(void) { 
    const int x = 10;
    *( (int*)&x ) = 30;

    printf( "%d\n", x );
    return 0;
}
