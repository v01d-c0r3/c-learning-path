# Lesson: Detecting & fixing memory leaks with valgrind

## What valgrind does

Valgrind instruments your binary to track every memory allocation and access. It catches:

- **Memory leaks** — allocated memory never freed
- **Invalid reads/writes** — accessing memory out of bounds
- **Use of uninitialised memory** — reading a variable before setting it
- **Double free** — freeing the same memory twice

## Running valgrind

```bash
gcc -g -o out leaky.c          # -g is essential for useful output
valgrind --leak-check=full ./out
```

## Reading valgrind output

```
==12345== HEAP SUMMARY:
==12345==   in use at exit: 20 bytes in 1 blocks
==12345==   total heap usage: 2 allocs, 1 frees, 1,044 bytes allocated
==12345==
==12345== 20 bytes in 1 blocks are definitely lost in loss record 1 of 1
==12345==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/...)
==12345==    by 0x10916B: main (leaky.c:8)     ← your code, line 8
```

**"definitely lost"** — you have a pointer to this memory but never freed it. This is a true leak.

**"still reachable"** — memory that was allocated and still has a live pointer at exit. Often global variables. Less critical.

**"indirectly lost"** — pointed to by definitely lost memory. Fix the root leak first.

## Common leak patterns and fixes

```c
// LEAK: early return without freeing
char *buf = malloc(100);
if (error) return -1;   // bug — buf never freed on this path
free(buf);

// FIX:
char *buf = malloc(100);
if (error) { free(buf); return -1; }
free(buf);
```

```c
// LEAK: reassigning pointer without freeing
int *p = malloc(sizeof(int));
p = malloc(sizeof(int));   // bug — first allocation lost
free(p);

// FIX:
int *p = malloc(sizeof(int));
free(p);
p = malloc(sizeof(int));
free(p);
```

## AddressSanitizer — faster alternative

If valgrind is too slow (it's ~20x slower), use ASan:

```bash
gcc -fsanitize=address,leak -g -o out leaky.c
./out
```

ASan catches the same issues at ~2x slowdown and gives colourful output.

---

## My notes

**What confused me:**

**What clicked:**

**Leaks I found in the exercise:**

**valgrind output I didn't understand:**

**Things to look up later:**
