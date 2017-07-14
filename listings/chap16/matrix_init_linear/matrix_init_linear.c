#include <stdio.h>
#include <malloc.h>
#define DIM (16*1024)

int main( int argc, char** argv ) {
    size_t i, j;
    int* mat = (int*)malloc( DIM * DIM * sizeof( int ) );
    for( i = 0; i < DIM; ++i )
        for( j = 0; j < DIM; ++j ) 
            mat[i*DIM+j] = 42;
    puts("TEST DONE");
    return 0;
}
