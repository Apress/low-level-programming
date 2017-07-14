typedef unsigned long size_t;
__attribute__((noinline))
    int no_stack_frame( void ) {
        char buffer[100];
        return 0;
    }

int main( int argc, char** argv ) {
    return no_stack_frame();
}
