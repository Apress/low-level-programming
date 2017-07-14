#ifndef _PAIR_H_
#define _PAIR_H_

#include <stdio.h>

struct pair {
    int x;
    int y;
};

void pair_apply( struct pair* pair, void (*f)(struct pair) );
void pair_tofile( struct pair* pair, FILE* file );

#endif
