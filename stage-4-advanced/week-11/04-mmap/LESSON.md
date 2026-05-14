# Lesson: mmap, virtual memory & memory-mapped files

## Virtual memory

Every process has its own virtual address space. The OS maps virtual pages to physical RAM pages (or swap) on demand. This is why two processes can both have a pointer to address `0x1000` — they map to different physical memory.

## mmap — map memory directly

```c
#include <sys/mman.h>

// Anonymous mmap — like malloc but page-aligned
void *p = mmap(NULL, size, PROT_READ|PROT_WRITE,
               MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
if (p == MAP_FAILED) { perror("mmap"); }
// ... use p ...
munmap(p, size);
```

## Memory-mapped files

Map a file directly into your address space — read it like an array, no fread needed:

```c
int fd = open("data.bin", O_RDONLY);
struct stat st;
fstat(fd, &st);

char *data = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
close(fd);   // fd can be closed after mmap

// Access file contents like an array
printf("%c\n", data[0]);

// Count newlines efficiently
int lines = 0;
for (size_t i = 0; i < st.st_size; i++)
    if (data[i] == '\n') lines++;

munmap(data, st.st_size);
```

The OS pages data in from disk on demand — you don't load the whole file upfront.

## mprotect — change memory permissions

```c
mprotect(p, size, PROT_READ);           // make read-only
mprotect(p, size, PROT_READ|PROT_EXEC); // make executable (JIT compilers)
mprotect(p, size, PROT_NONE);           // no access — guard pages
```

## Shared memory between processes

```c
// MAP_SHARED — changes are visible to other processes mapping the same file
void *shared = mmap(NULL, size, PROT_READ|PROT_WRITE,
                    MAP_SHARED, fd, 0);
```

---

## My notes

**What confused me:**

**What clicked:**

**mmap vs malloc — when to use each:**

**Things to look up later:**
