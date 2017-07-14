int* max;
int* cur;

int f( unsigned int e ) 
{ 
    if ( max - cur > e )
        return 1;
    else
        return 0;
}
