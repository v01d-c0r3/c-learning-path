# Lesson: Pointer fundamentals — & and *

## What is a pointer?

A pointer is a variable that stores a **memory address**. Instead of holding a value like `42`, it holds the location in memory where `42` is stored.

```c
int  x = 42;     // x holds the value 42
int *p = &x;     // p holds the address of x
```

```
Memory:
Address  Value
0x1000   42      ← x lives here
0x1008   0x1000  ← p lives here, holds x's address
```

## The two pointer operators

```c
&x    // "address of x" — gives you x's location in memory
*p    // "dereference p" — gives you the value at the address p holds
```

```c
int x = 42;
int *p = &x;

printf("%p\n", (void*)p);  // prints address, e.g. 0x7ffd1234
printf("%d\n", *p);        // prints 42 — value at that address
*p = 99;                   // modifies x through the pointer
printf("%d\n", x);         // prints 99 — x was changed!
```

## Why pointers exist

1. **Modify variables from inside functions** (pass by reference)
2. **Work with heap memory** (malloc returns a pointer)
3. **Efficiently handle large data** (pass pointer instead of copying)
4. **Build data structures** like linked lists and trees

## NULL — the empty pointer

`NULL` means "this pointer points to nothing". Always initialise pointers and check for NULL before dereferencing:

```c
int *p = NULL;

if (p != NULL) {
    printf("%d\n", *p);  // safe
}
// Never do: printf("%d\n", *p) without checking — instant crash
```

## const with pointers — four combinations

```c
int x = 10;
int y = 20;

int *p               = &x;  // can change what p points to AND the value
const int *p         = &x;  // can change what p points to, NOT the value
int * const p        = &x;  // CANNOT change what p points to, can change value
const int * const p  = &x;  // CANNOT change either
```

The rule: `const` applies to whatever is immediately to its left (or right if nothing is to the left).

## Pointer size

All pointers are the same size regardless of type — 8 bytes on 64-bit systems, 4 bytes on 32-bit:

```c
printf("%zu\n", sizeof(int*));     // 8
printf("%zu\n", sizeof(char*));    // 8
printf("%zu\n", sizeof(double*));  // 8
```

The type (`int*` vs `char*`) tells the compiler how many bytes to read when dereferencing, not how big the pointer is.

---

## My notes

**What confused me:**

**What clicked:**

**The & and * difference in my own words:**

**Things to look up later:**
