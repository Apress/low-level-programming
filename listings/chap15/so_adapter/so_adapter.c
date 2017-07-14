
static int _function( int x ) { return x + 1; }

void otherfunction( ) { 
    printf(" %d \n", _function( 41 ) );
}

int function( int x ) { return _function( x ); }

