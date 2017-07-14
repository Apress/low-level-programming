#include <stdio.h>

int global = 42;

extern int global_alias
__attribute__((alias ("global"), visibility ("hidden" ) ));


void fun( void ) {
    puts("1337\n");
}

extern void fun_alias( void )
__attribute__((alias ("fun"), visibility ("hidden" ) ));

int tester(void) {
    printf( "%d\n", global );
    printf( "%d\n", global_alias );

    fun();
    fun_alias();
    return 0;
}
