#include <stdio.h>

struct parent {
    const char* field_parent;
};

struct child { 
    struct parent base;
    const char* field_child;
};

void parent_print( struct parent* this ) {
    printf( "%s\n", this->field_parent ); 
}

int main( int argc, char** argv ) {
    struct child c;
    c.base.field_parent = "parent";
    c.field_child = "child";
    parent_print( (struct parent*) &c );

    return 0;
}
