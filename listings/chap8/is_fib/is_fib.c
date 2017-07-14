#include <stdio.h>

int is_fib( int n ) {

    int a = 1;
    int b = 1;
    if ( n == 1 ) return 1;

    while ( a <= n && b <= n ) {
        int t = b;

        if (n == a || n == b) return 1;
        b = a;
        a = t + a; 
    }
    return 0;

} 

void check(int n) { printf( "%d -> %d\n", n, is_fib( n ) ); }

int main(void) {
    int i;
    for( i = 1; i < 11; i = i + 1 ) {
        check( i ); 
    } 
    return 0;
}
