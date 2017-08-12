/* Good */
void f(void) {
    int x;
    ...
}

/* Bad: `x` is declared after `printf` call */

void f(void) {
    int y = 12;
    printf( "%d", y);
    int x = 10; 
    ...
}

/* Good, but declaring `i` in the `for` initializer like this requires C99. */
for( int i = 0; i < 10; i++ ) {
    ...
}

/* Good: `i` is declared before `for`. Does not require C99. */
int f(void) { 
    int i;
    for( i = 0; i < 10; i++ ) {
        ...
    }
}

/* Good: any block can have additional variables declared in its beginning */
/* `x` is local to one `for` iteration and is always reinitialized to 10 */
for( i = 0; i < 10; i++ ) {
    int x = 10;
}
