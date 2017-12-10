int list_sum_bad( const struct list* l ) {
    size_t i;
    int sum = 0;
    size_t sz = list_size( l );
    for( i = 0; i < sz; l = l-> next ) 
      sum = sum + list_get( l, i );
    return sum;
}

int list_sum_good( const struct list* l ) {
  size_t i;
  int sum = 0;
  /* We do not want to launch the full computation 
   * of size at each cycle iteration */
  size_t sz = list_size( l ) ; 
  for( i = 0; i < sz; l = l-> next ) 
    sum = sum + l->value;
  return sum;
}
