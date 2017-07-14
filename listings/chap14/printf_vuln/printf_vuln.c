#include <stdio.h>
int main(void) {
    char buffer[1024];
    gets(buffer);
    printf( buffer ); 
    return 0;
}
