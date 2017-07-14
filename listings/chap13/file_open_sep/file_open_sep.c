#include <stdio.h>

enum stat {
    STAT_OK,
    STAT_ERR_OPEN,
    STAT_ERR_CLOSE,
    STAT_ERR_WRITE
};

enum stat dump( FILE * f ) {
    if ( fprintf( f, "this is the dump %d", 42 ) ) return STAT_OK;
    return STAT_ERR_WRITE;
}

enum stat fun( void ) {
    enum stat dump_stat;
    FILE * f;

    f = fopen( "dump.txt", "w" );
    if (!f) return STAT_ERR_OPEN;

    dump_stat = dump( f );

    if ( dump_stat != STAT_OK ) return dump_stat;
    if (! fclose( f ) ) return STAT_ERR_CLOSE;

    return STAT_OK;
}
