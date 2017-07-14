#include <stdio.h>

int f(void) { puts( "F" ); return 0; }
int g(void) { puts( "G" ); return 1; }

int main(void) {
    f() && g();
    return 0;
}
