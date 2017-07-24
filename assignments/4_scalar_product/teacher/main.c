#include <stdio.h>

const int x[] = { 1, 2, 3, 4, 5 };
const int y[] = { 5, 4, 3, 2, 1 };

int scalar( const int a[], const int b[], size_t sz ) {
    size_t i; 
    int res = 0;
    for ( i = 0; i < sz; i++ ) 
        res += a[i] * b[i];
    return res;
}

int main(void) {

    printf( "The scalar product is: %d\n", scalar( x, y, sizeof( x ) / sizeof( x[0] ) ) );
    
    return 0;
}
