#include <stdio.h>

int is_prime( unsigned long n ) {
    
    unsigned long i;
   
    if ( n < 2UL  ) return 0; 
    if ( n == 2UL ) return 1;

    for ( i = 2UL; i < n/2UL+1UL; i ++ ) if (! (n % i) ) return 0;

    return 1;
}

int main( int argc, char** argv ) {

    unsigned long n = 0UL;

    while ( ! scanf( "%lu", &n ) );

    printf( "%lu is %s prime \n", n, is_prime( n )? "" : "not" );

    return 0;
}
