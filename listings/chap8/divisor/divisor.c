#include <stdio.h>

int first_divisor( int n ) {
    int i;
    if ( n == 1 ) return 1;
    for( i = 2; i <= n; i++ ) 
        if ( n % i == 0 ) return i; 
    return 0;
}

int main(void) {
    int i;
    for( i = 1; i < 11; i++ )
        printf( "%d \n", first_divisor( i ) ); 

    return 0;
}
