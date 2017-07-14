#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
/*
void swap(int64_t* arg ) {
    int32_t t;

    int32_t* v = (int32_t*)arg;
    t = v[0];
    v[0] = v[1];
    v[1] = t;
}

int main(void) {
    int64_t x = 1;
    swap( &x );
    printf( "%"PRId64"\n", x); 
    return 0;
}*/
typedef uint64_t DWORD;
typedef uint32_t WORD;

int SwapWords ( DWORD val )
{
          WORD * p = (WORD*) &val;
                WORD t;
                      t = p[0];
                            p[0] = p[1];
                                  p[1] = t;
                                        return val;
}

int main()
{
          printf ( "%d\n", SwapWords(1) );
                return 0;
}
