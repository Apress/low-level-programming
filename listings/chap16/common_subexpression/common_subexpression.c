#include <stdio.h>

__attribute__((noinline))
    void test(int x) {
        printf("%d %d", 
                x*x + 2*x + 1,
                x*x + 2*x - 1 );
    }

int main(int argc, char** argv) {
    test( argc );
    return 0;
}
