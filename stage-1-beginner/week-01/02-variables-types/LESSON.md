# Lesson: Variables, primitive types & sizes

## What is a variable?

A variable is a named location in memory that holds a value. In C you must declare the type before you can use it — the compiler needs to know how many bytes to reserve.

```c
int age = 25;       // 4 bytes, whole number
float price = 9.99; // 4 bytes, decimal (less precise)
double pi = 3.14159265358979; // 8 bytes, decimal (more precise)
char grade = 'A';   // 1 byte, a single character
```

## The core types and their sizes

| Type | Typical size | Range | printf specifier |
|------|-------------|-------|-----------------|
| `char` | 1 byte | -128 to 127 | `%c` (char) or `%d` (number) |
| `int` | 4 bytes | -2,147,483,648 to 2,147,483,647 | `%d` |
| `unsigned int` | 4 bytes | 0 to 4,294,967,295 | `%u` |
| `long` | 4 or 8 bytes | platform-dependent | `%ld` |
| `float` | 4 bytes | ~6-7 decimal digits precision | `%f` |
| `double` | 8 bytes | ~15-16 decimal digits precision | `%f` or `%lf` |

> Sizes can vary by platform. Always use `sizeof()` to check on your machine.

## sizeof() — your best friend

```c
#include <stdio.h>

int main(void) {
    printf("int    = %zu bytes\n", sizeof(int));
    printf("double = %zu bytes\n", sizeof(double));
    printf("char   = %zu bytes\n", sizeof(char));
    return 0;
}
```

`%zu` is the correct format specifier for `sizeof` (it returns `size_t`, an unsigned type).

## Signed vs unsigned

A signed type can hold negative numbers. An unsigned type uses all bits for positive numbers, giving double the positive range.

```c
signed char   sc = -5;   // fine
unsigned char uc = -5;   // WRONG — wraps around to 251
```

This wrapping (overflow) is one of C's most common bugs. The compiler won't warn you unless you use `-Wall`.

## Integer literals

```c
int dec = 255;      // decimal
int hex = 0xFF;     // hexadecimal — same value
int oct = 0377;     // octal — same value
int bin = 0b11111111; // binary (GCC extension)
```

## Type conversion — implicit and explicit

C will silently convert between types, sometimes losing data:

```c
int i = 3.99;       // i becomes 3 — decimal part dropped silently
float f = 1/3;      // f becomes 0.0 — integer division happens first!
float g = 1.0/3;    // g becomes 0.333... — correct, one operand is float
```

Force a conversion with a cast:
```c
float result = (float)1 / 3;   // explicitly convert 1 to float first
```

---

## My notes

**What confused me:**

**What clicked:**

**Types I keep mixing up:**

**Things to look up later:**
