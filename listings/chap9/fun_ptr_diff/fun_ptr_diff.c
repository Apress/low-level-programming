#include <stdio.h>

double g( int number ) { return 0.5 + number; }   

void fun( double (f)(int) ) {
    printf(" f: %p\n", &f );
} 

void fun_( double (*f)(int) ) {
    printf("*f: %p\n", &f );
} 

void arr( int arr[] ) {
    printf("arr[]: %p \n", arr );
}
void arr_( int* arr ) {
    printf("arr* : %p \n", arr );
}

int main( void ) { 
    int data[10];
    fun( g );
    fun_( g );
    arr( data );
    arr_( data );
    return 0; 
}
