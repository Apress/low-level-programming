int myfunc ( int a, int b ) 
{
    return a + b;
}

int other( int x ) {
    return 1 + myfunc( 4, 5 );
}
