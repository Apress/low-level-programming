#include <pthread.h>
#include <inttypes.h>
#include <stdio.h>
#include <unistd.h>

pthread_t t1, t2;

uint64_t value = 0;

void* impl1( void* _ ) {
    for (int n = 0; n < 10000000; n++) { 
        value += 1;        
    }
    return NULL;
}

int main(void) {
    pthread_create(  &t1, NULL, impl1, NULL );
    pthread_create(  &t2, NULL, impl1, NULL );

    pthread_join( t1, NULL );
    pthread_join( t2, NULL );
    printf( "%"PRIu64"\n", value );
    return 0;
}
