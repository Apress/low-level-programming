#ifndef _MEM_H_
#define _MEM_H_

#define __USE_MISC

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#include <sys/mman.h>  

#define HEAP_START ((void*)0x04040000)

struct mem;

#pragma pack(push, 1)
struct mem {
    struct mem* next;
    size_t capacity;
    bool is_free;
};
#pragma pack(pop)

void* _malloc( size_t query );
void  _free( void* mem );
void* heap_init( size_t initial_size );

#define DEBUG_FIRST_BYTES 4


void memalloc_debug_struct_info( FILE* f,
        struct mem const* const address );

void memalloc_debug_heap( FILE* f,  struct mem const* ptr );

#endif
