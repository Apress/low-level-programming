#include <stdio.h>
int array[] = {1,2,3,4,5};

void array_sum( void ) {
    int i;
    int sum = 0;
    for( i = 0; i < 5; i++ )
        sum = sum + array[i];
    printf("The sum is: %d\n", sum ); 

}

int main( int argc, char** argv ) {
    array_sum();
    return 0;
}
