#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

int main(void) {
    struct rusage r;
    struct timeval start;
    struct timeval end;

    getrusage(RUSAGE_SELF, &r );
    start = r.ru_utime;

    for( uint64_t i = 0; i < 100000000; i++ );

    getrusage(RUSAGE_SELF, &r );
    end = r.ru_utime;

    long res = ((end.tv_sec - start.tv_sec) * 1000000L) + 
        end.tv_usec - start.tv_usec;

    printf( "Time elapsed in microseconds: %ld\n", res );
    return 0;
}
