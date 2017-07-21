#include <stdio.h>

int main(void) {                                                                
    printf( "%d\n", * ((int*) 0x12345) );                    
    return 0;                                                                   
}                   
