int list_sum( const struct list* l ) {
    size_t i;
    int sum = 0;
    /* We do not want to launch  the full size computation at each cycle iteration */
    size_t sz = list_size( l ) ; 
    for( i = 0; i < list_size(l); l = l-> next ) 
        sum = sum + l->value;
    return sum;
}
