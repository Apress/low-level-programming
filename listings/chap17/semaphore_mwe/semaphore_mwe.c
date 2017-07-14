#include <semaphore.h>
#include <inttypes.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

sem_t sem;

uint64_t counter1 = 0;
uint64_t counter2 = 0;

pthread_t t1, t2, t3;

void* t1_impl( void* _ ) {
    while( counter1 < 10000000 ) counter1++;
    sem_post( &sem );
    return NULL;
}

void* t2_impl( void* _ ) {
    while( counter2 < 20000000 ) counter2++;
    sem_post( &sem );
    return NULL;
}

void* t3_impl( void* _ ) {
    sem_wait( &sem ); 
    sem_wait( &sem ); 
    printf("End: counter1 = %" PRIu64 " counter2 = %" PRIu64 "\n", 
            counter1, counter2 );
    return NULL;
}

int main(void) {
    sem_init( &sem, 0, 0 );
    pthread_create( &t3, NULL, t3_impl, NULL );

    sleep( 1 );
    pthread_create( &t1, NULL, t1_impl, NULL );
    pthread_create( &t2, NULL, t2_impl, NULL );

    sem_destroy( &sem );
    pthread_exit( NULL );
    return 0;
}
