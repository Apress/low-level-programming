#include <string.h>
#include <malloc.h>

struct int_array {
    size_t size; 
    int array[];
};

struct int_array* array_create( size_t size ) {
    struct int_array* array = malloc( 
              sizeof( *array ) 
            + sizeof( int ) * size );
    array-> size = size;
    memset( array->array, 0, size );
    return array;
}

