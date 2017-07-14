#include <stdio.h>
#include <stdalign.h>

int main(void) {
    short x;
    printf("%zu\n", alignof(x)); 
    return 0;
}
