# Lesson: Dynamic memory — malloc / calloc / realloc / free

## Stack vs heap

**Stack** — automatic, fast, limited size (~8MB). Variables declared inside functions live here. Freed automatically when the function returns.

**Heap** — manual, slower, huge (limited by RAM). Allocated with `malloc`. You must free it yourself — forgetting causes memory leaks.

```c
void foo(void) {
    int x = 5;           // stack — gone when foo returns
    int *p = malloc(4);  // heap — survives until you call free(p)
}
```

## malloc — allocate raw memory

```c
#include <stdlib.h>

int *arr = malloc(5 * sizeof(int));  // allocate space for 5 ints

if (arr == NULL) {                   // ALWAYS check — malloc can fail
    fprintf(stderr, "Out of memory\n");
    exit(1);
}

arr[0] = 10;
arr[1] = 20;
// ... use the array ...
free(arr);       // ALWAYS free when done
arr = NULL;      // set to NULL after freeing — prevents accidental reuse
```

`malloc` returns `void*` which implicitly converts to any pointer type. The memory it returns is **uninitialised** — it contains garbage values.

## calloc — allocate and zero-initialise

```c
int *arr = calloc(5, sizeof(int));  // 5 ints, all set to 0
```

Prefer `calloc` when you want zeroed memory. Slightly slower than malloc.

## realloc — resize an allocation

```c
int *arr = malloc(5 * sizeof(int));
// ... fill arr ...

// grow to 10 ints
arr = realloc(arr, 10 * sizeof(int));
if (arr == NULL) { /* handle error */ }
```

**Important:** `realloc` may move the memory to a new address. Always assign back to the pointer. Never do:

```c
realloc(arr, new_size);   // WRONG — leaks old memory if it moved
```

## free — release memory

```c
free(ptr);       // returns memory to the heap
ptr = NULL;      // good practice — makes double-free detectable
```

**Double free** — calling `free` twice on the same pointer is undefined behaviour (likely crash). Setting to NULL after freeing prevents this.

**Memory leak** — forgetting to `free` allocated memory. In a long-running program this exhausts RAM.

## Detecting leaks with valgrind

```bash
gcc -g -o out heap.c
valgrind --leak-check=full ./out
```

Output will say "definitely lost: N bytes in M blocks" for each leak, with a stack trace showing where it was allocated.

## Common patterns

```c
// allocate a string on the heap
char *dup = malloc(strlen(src) + 1);  // +1 for \0
strcpy(dup, src);
// ... use dup ...
free(dup);

// allocate a struct
typedef struct { int x; int y; } Point;
Point *p = malloc(sizeof(Point));
p->x = 3;
p->y = 4;
free(p);
```

---

## My notes

**What confused me:**

**What clicked:**

**The malloc/free rule in my own words:**

**Bugs I need to watch for:**

**Things to look up later:**
