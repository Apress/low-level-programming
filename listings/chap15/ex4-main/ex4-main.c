#include <stdio.h>

extern int sofun( void );
extern const char sostr[];

int main( void ) {
    printf( "%d\n", sofun() );
    puts( sostr ); 
    return 0;
}

