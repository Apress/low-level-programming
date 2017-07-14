#include <stdio.h>

const int g_array[] = {1,2,3,4,5};

int array_sum( int const* array, size_t count ) {
    size_t i;
    int sum = 0;
    for( i = 0; i < count; i++ )
        sum = sum + array[i];
    return sum;
}

int main( int argc, char** argv ) {
    printf(
            "The sum is: %d\n", 
            array_sum(g_array, sizeof(g_array) / sizeof(int)) 
          );
    return 0;
}
