#include <stdio.h>
int puts( const char* str ) {
    return printf("We took control over your C library! \n");
}
