#include <stdio.h>

int main(void) {
    int count;
    printf( "hello%n world\n", &count);
    printf( "%d\n", count );
    return 0;
}
