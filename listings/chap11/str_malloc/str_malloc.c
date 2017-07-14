#include <malloc.h>
#include <string.h>

int main( int argc, char** argv ) 
{
    char* str = (char*)malloc( 25 );
    strcpy( str, "wow, such a nice string!" );

    free( str );    
}
