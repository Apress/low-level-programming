#include <malloc.h>


int main( void ) {
    int* array;

    /* malloc returns the allocated memory starting address
     * Notice that its argument is the byte size, elements count multiplied
     * by element size */
    array = malloc( 10 * sizeof( int ));

    /* actions on array are performed here */

    free( array ); /* now the related memory region is deallocated */
    return 0;
}

