#include <stdio.h>

long array[] = { 1, 2, 3 };

int main(void) {
    printf( "%zu \n", sizeof( array    ) ); /* output: 24 */ 
    printf( "%zu \n", sizeof( array[0] ) ); /* output: 8 */ 
    return 0;
}
