# Lesson: Preprocessor macros & X-macro pattern

## Object-like macros — constants

```c
#define PI        3.14159265
#define MAX_SIZE  256
#define VERSION   "1.0.0"
```

Unlike `const`, macros have no type and no scope — they are textually substituted everywhere after the `#define`.

## Function-like macros — inline expressions

```c
#define MAX(a, b)  ((a) > (b) ? (a) : (b))
#define SQ(x)      ((x) * (x))
```

**Always wrap arguments and the whole expression in parentheses.** Without them:

```c
#define BAD_SQ(x)  x * x
BAD_SQ(1 + 2)   // expands to: 1 + 2 * 1 + 2 = 5, not 9!

#define GOOD_SQ(x) ((x) * (x))
GOOD_SQ(1 + 2)  // expands to: ((1 + 2) * (1 + 2)) = 9
```

**Macros evaluate arguments multiple times:**
```c
MAX(i++, j)   // i++ happens twice if i > j! Use inline functions instead.
```

## Variadic macros

```c
#define DEBUG(fmt, ...)  fprintf(stderr, "[DEBUG] " fmt "\n", ##__VA_ARGS__)

DEBUG("x = %d", x);         // [DEBUG] x = 42
DEBUG("hello world");        // [DEBUG] hello world
```

`##__VA_ARGS__` removes the comma when no extra args are passed (GCC extension).

## Predefined macros

```c
__FILE__    // current filename as string
__LINE__    // current line number as int
__func__    // current function name (C99)
__DATE__    // compilation date
__TIME__    // compilation time
```

## X-macro pattern

Generate parallel code (enum + string table + handlers) from one list — no duplication:

```c
#define COLORS \
    X(RED,   "red")   \
    X(GREEN, "green") \
    X(BLUE,  "blue")

// Generate enum
typedef enum {
    #define X(name, str) name,
    COLORS
    #undef X
} Color;

// Generate string table
const char *color_names[] = {
    #define X(name, str) str,
    COLORS
    #undef X
};

// color_names[RED] = "red", color_names[GREEN] = "green", etc.
```

Add a new colour to `COLORS` and both the enum and the string table update automatically.

---

## My notes

**What confused me:**

**What clicked:**

**The X-macro pattern in my own words:**

**Things to look up later:**
