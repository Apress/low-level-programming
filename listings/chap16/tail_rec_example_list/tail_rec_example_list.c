#include <stdio.h>
#include <malloc.h>

struct llist {
    struct llist* next;
    int value;
};

struct llist* llist_at( 
        struct llist* lst, 
        size_t idx ) {
    if ( lst && idx ) return llist_at( lst->next, idx-1 );
    return lst;
}
struct llist* c( int value, struct llist* next) {
    struct llist* lst = malloc( sizeof(struct llist*) );
    lst->next = next;
    lst->value = value;
    return lst;
}

int main( void ) {
    struct llist* lst = c( 1, c( 2, c( 3, NULL )));
    printf("%d\n", llist_at( lst, 2 )->value );
    return 0;
}
