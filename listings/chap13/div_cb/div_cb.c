#include <stdio.h>

int div( int x, int y, void (onerror)(int, int)) {
    if ( y != 0 ) 
        return x/y; 
    else {
        onerror(x,y);
        return 0;
    }
}

static void div_by_zero(int x, int y) {
    fprintf( stderr, "Division by zero: %d / %d\n", x, y );
}

int main(void) {
    printf("%d %d\n", 
            div( 10, 2, div_by_zero ),
            div( 10, 0, div_by_zero ) ); 
    return 0;
}
