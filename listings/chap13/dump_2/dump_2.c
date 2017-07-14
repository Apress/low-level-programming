void dump( FILE* f ) {
    fprintf(f, "this is the dump %d", 42 ); 
}
void fun( void ) {
    FILE* f = fopen( "dump.txt", "w" );
    dump( f ); 
    fclose( f );
}
