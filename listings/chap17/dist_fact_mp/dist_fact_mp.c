#include <pthread.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdio.h>
#include <malloc.h>

#define THREADS 4

struct fact_task {
    uint64_t num;
    uint64_t from, to;
    uint64_t result;
};

void* fact_worker( void* arg ) {
    struct fact_task* const task =  arg;
    task-> result = 0;
    for( uint64_t i = task-> from; i < task-> to; i++ )
        if ( task->num % i == 0 ) task-> result ++;
    return NULL;
}

/* assuming threads_count < num */
uint64_t factors_mp( uint64_t num, size_t threads_count ) {

    struct fact_task* tasks = malloc( threads_count * sizeof( *tasks ) );
    pthread_t* threads = malloc( threads_count * sizeof( *threads ) );

    uint64_t start = 1;
    size_t step = num / threads_count;

    for( size_t i = 0; i < threads_count; i++ ) {
        tasks[i].num = num;
        tasks[i].from = start;
        tasks[i].to = start + step;
        start += step;
    }
    tasks[threads_count-1].to = num+1; 

    for ( size_t i = 0; i < threads_count; i++ ) 
        pthread_create( threads + i, NULL, fact_worker, tasks + i );

    uint64_t result = 0; 
    for ( size_t i = 0; i < threads_count; i++ ) {
        pthread_join( threads[i], NULL );
        result += tasks[i].result;
    }

    free( tasks );
    free( threads );
    return result;
}


int main( void ) {
    uint64_t input = 2000000000;
    printf( "Factors of %"PRIu64": %"PRIu64"\n", 
            input, factors_mp(input, THREADS ) );
    return 0;
}
