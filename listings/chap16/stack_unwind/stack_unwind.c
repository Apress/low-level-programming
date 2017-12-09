void unwind();
int *fptr; /* global pointer to a local variable of main */
void f( int count ) {
    if ( count ) f( count-1 ); else unwind(); 
}
int main(void) {
    int filler=0; /* make a local variable of main */
    fptr=&filler; /* set up a global pointer for unwind */
    f( 10 ); return 0;
}
