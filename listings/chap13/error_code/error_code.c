enum div_res {
    DIV_OK,
    DIV_BYZERO
};

enum div_res div( int x, int y, int* result ) {
    if ( y != 0 ) { *result = x/y; return DIV_OK; }
    else return DIV_BYZERO;
}
