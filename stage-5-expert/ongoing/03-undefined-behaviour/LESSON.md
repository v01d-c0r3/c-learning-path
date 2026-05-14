# Lesson: Undefined behaviour & sanitisers

## What is undefined behaviour?

When your code violates C's rules in certain ways, the standard says the behaviour is "undefined" — the compiler can do anything: crash, silently produce wrong results, or (dangerously) "work" but only until a compiler update breaks it.

## Common UB and how to fix it

**Signed integer overflow:**
```c
int x = INT_MAX;
x + 1;   // UB — wraps on most hardware but not guaranteed by standard
// Fix: use unsigned, or check before:
if (x < INT_MAX) x++;
```

**Null pointer dereference:**
```c
int *p = NULL;
*p = 5;   // UB — crash (usually)
// Fix: always check for NULL before dereferencing
```

**Strict aliasing violation:**
```c
float f = 3.14f;
int *p = (int*)&f;   // UB — accessing float memory as int
*p;

// Fix: use memcpy for type punning
int i; memcpy(&i, &f, sizeof(i));   // defined behaviour
```

**Out-of-bounds access:**
```c
int arr[3];
arr[5] = 1;   // UB — corrupts adjacent memory
```

**Shift past width:**
```c
unsigned u = 1u << 32;   // UB on 32-bit int — use 1ull << 32 instead
```

## UBSanitiser

```bash
gcc -fsanitize=undefined -g -o out file.c
./out
```

Reports: signed-integer-overflow, null-dereference, out-of-bounds, misaligned-access, invalid-shift.

## Why compilers exploit UB

The compiler assumes your code has no UB. It uses this to optimise aggressively:

```c
// Compiler sees: if p is NULL, dereferencing is UB, so p must not be NULL here
// It may eliminate the NULL check entirely!
if (p) { *p = 5; }
foo(p);   // compiler may assume p != NULL here
```

This is why UB is dangerous even when it "seems to work" — compiler optimisation makes it blow up in non-obvious ways.

---

## My notes

**What confused me:**

**What clicked:**

**UB I found in my code:**

**Things to look up later:**
