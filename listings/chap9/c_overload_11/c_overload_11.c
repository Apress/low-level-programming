#include <stdio.h>

#define print_fmt(x) (_Generic( (x), \
            int: "%d",\
            double: "%f",\
            default: "%x"))

#define print(x) printf( print_fmt(x), x ); puts("");

int main(void) {
    int x = 101;
    double y = 42.42;
    print(x);
    print(y);
    return 0;
}
