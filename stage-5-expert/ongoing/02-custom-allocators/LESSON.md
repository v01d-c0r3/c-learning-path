# Lesson: Custom allocators — arena, pool & slab

## Why custom allocators?

`malloc` is general-purpose and relatively slow due to bookkeeping, fragmentation, and thread safety overhead. Custom allocators exploit known allocation patterns to be faster.

## Arena allocator (bump pointer)

All allocations from a pre-allocated block. Reset in O(1) by moving the pointer back. No per-object free.

```c
typedef struct {
    char  *base;
    size_t used;
    size_t cap;
} Arena;

void *arena_alloc(Arena *a, size_t n) {
    n = (n + 7) & ~7;   // align to 8 bytes
    if (a->used + n > a->cap) return NULL;
    void *p = a->base + a->used;
    a->used += n;
    return p;
}

void arena_reset(Arena *a) { a->used = 0; }   // O(1) "free all"
```

Ideal for: per-frame allocations in games, per-request allocations in servers.

## Pool allocator

Fixed-size objects from a free list. O(1) alloc and free, no fragmentation.

```c
typedef struct Block { struct Block *next; } Block;

typedef struct {
    void  *memory;
    Block *free_list;
    size_t obj_size;
} Pool;

void *pool_alloc(Pool *p) {
    if (!p->free_list) return NULL;
    Block *b = p->free_list;
    p->free_list = b->next;
    return b;
}

void pool_free(Pool *p, void *ptr) {
    Block *b = ptr;
    b->next = p->free_list;
    p->free_list = b;
}
```

Ideal for: linked list nodes, fixed-size messages, network packets.

## Slab allocator

Groups objects of the same type into slabs (pages). Used by the Linux kernel for kernel object caches.

Key idea: a slab holds N objects of the same type. When all objects in a slab are freed, the slab is returned to the OS.

## Benchmarking

```c
clock_t t0 = clock();
for (int i = 0; i < 1000000; i++) {
    void *p = arena_alloc(&arena, 64);
    (void)p;
}
double ms = 1000.0 * (clock() - t0) / CLOCKS_PER_SEC;
```

Arena alloc is typically 10-100x faster than malloc for small, short-lived objects.

---

## My notes

**What confused me:**

**What clicked:**

**Arena vs pool — when to use each:**

**Things to look up later:**
