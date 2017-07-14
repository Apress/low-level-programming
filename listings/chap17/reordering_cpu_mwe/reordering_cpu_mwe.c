#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

sem_t sem_begin0, sem_begin1, sem_end;

int x, y, read0, read1;

void *thread0_impl( void *param )
{
    for (;;) {

        sem_wait( &sem_begin0 ); 

        x = 1;
        // This only disables compiler reorderings:
        asm volatile("" ::: "memory"); 
        // The following line disables also hardware reorderings:
        // asm volatile("mfence" ::: "memory"); 
        read0 = y;

        sem_post( &sem_end ); 
    }
    return NULL; 
};

void *thread1_impl( void *param )
{
    for (;;) {
        
        sem_wait( &sem_begin1 );  

        y = 1;
        // This only disables compiler reorderings:
        asm volatile("" ::: "memory"); 
        // The following line disables also hardware reorderings
        // asm volatile("mfence" ::: "memory"); 
        read1 = x;

        sem_post( &sem_end );  
    }
    return NULL; 
};

int main( void ) {

    sem_init( &sem_begin0, 0, 0);
    sem_init( &sem_begin1, 0, 0);
    sem_init( &sem_end, 0, 0);

    pthread_t thread0, thread1;
    pthread_create( &thread0, NULL, thread0_impl, NULL);
    pthread_create( &thread1, NULL, thread1_impl, NULL);

    for (uint64_t i = 0; i < 100000; i++)
    {
        x = 0;
        y = 0;
        sem_post( &sem_begin0 );
        sem_post( &sem_begin1 );

        sem_wait( &sem_end );
        sem_wait( &sem_end );

        if (read0 == 0 && read1 == 0 ) {
            printf( "reordering happened on iteration %" PRIu64 "\n", i );
            exit(0);
        }
    }
    puts("No reordering detected during 100000 iterations");
    return 0;
}
