#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct { char *base; size_t used; size_t cap; } Arena;

void  arena_init(Arena *a, size_t cap) { a->base = malloc(cap); a->used=0; a->cap=cap; }
void *arena_alloc(Arena *a, size_t n)  { /* TODO: bump pointer, align to 8 */ return NULL; }
void  arena_reset(Arena *a)            { a->used = 0; }
void  arena_free(Arena *a)             { free(a->base); }

int main(void) {
    Arena a;
    arena_init(&a, 1024*1024);
    /* TODO: allocate 10000 ints, measure time vs malloc loop */
    arena_free(&a);
    return 0;
}
