#include <stdarg.h>
#include <stdio.h>

void logmsg( int client_id, const char* const str, ... ) {
    va_list args;
    char buffer[1024];
    char* bufptr = buffer;

    va_start( args, str );

    bufptr += sprintf(bufptr, "from client %d :", client_id );
    vsprintf( bufptr, str, args );
    fprintf( stderr, "%s", buffer );

    va_end( args ); 
}
