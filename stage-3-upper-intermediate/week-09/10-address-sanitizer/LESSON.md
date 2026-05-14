# Lesson: AddressSanitizer & advanced debugging

## Sanitiser flags

```bash
gcc -fsanitize=address,undefined -g -o out file.c
```

| Sanitiser | Flag | Catches |
|-----------|------|---------|
| AddressSanitizer | `-fsanitize=address` | Buffer overflows, use-after-free, double-free, leaks |
| UndefinedBehaviourSanitizer | `-fsanitize=undefined` | Signed overflow, null deref, shift errors |
| ThreadSanitizer | `-fsanitize=thread` | Data races |
| MemorySanitizer | `-fsanitize=memory` | Uninitialised reads |

## Reading ASan output

```
==12345==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x...
READ of size 4 at 0x... thread T0
    #0 0x... in main asan_demo.c:6    ← your code, line 6
Shadow bytes around the buggy address:
  ...
```

The stack trace tells you exactly where the bad access happened.

## Common ASan findings

**Heap buffer overflow:**
```c
int *p = malloc(4 * sizeof(int));
p[4] = 99;   // ASan: heap-buffer-overflow
```

**Use after free:**
```c
free(p);
printf("%d\n", p[0]);   // ASan: heap-use-after-free
```

**Stack buffer overflow:**
```c
char buf[8];
strcpy(buf, "this string is too long");   // ASan: stack-buffer-overflow
```

## UBSan findings

```c
int x = INT_MAX;
x + 1;   // UBSan: signed integer overflow

int *p = NULL;
*p = 5;  // UBSan: null pointer dereference

int arr[3];
arr[5];  // UBSan: index 5 out of bounds for type 'int[3]'
```

## When to use which tool

- **Always:** `-Wall -Wextra -Werror` during development
- **During testing:** `-fsanitize=address,undefined` to catch runtime bugs
- **Before release:** valgrind for thorough leak checking
- **For concurrency:** `-fsanitize=thread` when using pthreads

---

## My notes

**What confused me:**

**What clicked:**

**Bugs ASan found in my code:**

**Things to look up later:**
