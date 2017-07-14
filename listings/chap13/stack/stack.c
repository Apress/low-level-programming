#include <malloc.h>
#include "stack.h"

struct list { int value; struct list* next; };

static struct list* list_new( int item, struct list* next ) {
    struct list* lst = malloc( sizeof( *lst ) );
    lst->value = item;
    lst->next = next;
    return lst;  
}

void stack_push( struct stack* s, int value ) {
    s->first = list_new( value, s->first );
    if ( s->last == NULL ) s->last = s-> first;
    s->count++;
}

int stack_pop( struct stack* s ) {
    struct list* const head = s->first;
    int value;
    if ( head ) {
        if ( head->next ) s->first = head->next;
        value = head->value;
        free( head );
        if( -- s->count ) {
            s->first = s->last = NULL; 
        }
        return value;
    }
    return 0;
}

void stack_foreach( struct stack* s, void (f)(int) ) {
    struct list* cur;
    for( cur = s->first; cur; cur = cur-> next )
        f( cur->value );

}

bool stack_is_empty( struct stack const* s ) {
    return s->count == 0;
}

struct stack stack_init( void ) {
    struct stack empty = { NULL, NULL, 0 };
    return empty;
}

void stack_deinit( struct stack* st ) {
    while( ! stack_is_empty( st ) ) stack_pop( st );
    st-> first = NULL;
    st-> last = NULL;
}

