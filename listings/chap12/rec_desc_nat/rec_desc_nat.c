#include <stdio.h>
#include <stdbool.h>

char const* stream = NULL  ; 

bool accept(char c) { 
    if (*stream == c) { 
        stream++; 
        return true; 
    } 
    else return false; 
} 
bool notzero( void ) {
    return accept( '1' ) || accept( '2' ) || accept( '3' ) 
        || accept( '4' ) || accept( '5' ) || accept( '6' ) 
        || accept( '7' ) || accept( '8' ) || accept( '9' );
} 
bool digit( void ) {
    return accept('0') || notzero();
} 
bool raw( void ) {
    if ( digit() ) { raw(); return true; }
    return false;
}
bool number( void ) {
    if ( notzero() ) {
        raw();
        return true;
    } else return accept('0');
} 
bool str( void ) {
    return number() && accept( 0 );
} 
void check( const char* string ) {
    stream = string;
    printf("%s -> %d\n", string, str() );
} 
int main(void) {
    check("12345");
    check("hello12");
    check("0002");
    check("10dbd");
    check("0");
    return 0;
}
