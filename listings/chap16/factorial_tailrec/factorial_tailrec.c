
__attribute__(( noinline ))
    int factorial( int acc, int arg ) {
        if ( arg == 0 ) return acc;
        return factorial( acc * arg, arg-1 );
    }

int main(int argc, char** argv) { return factorial(1, argc); }

