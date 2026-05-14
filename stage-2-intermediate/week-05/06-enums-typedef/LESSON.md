# Lesson: Enums & typedef

## Enums — named integer constants

Instead of magic numbers, use named constants that make code self-documenting:

```c
// without enum — what does 2 mean?
int direction = 2;

// with enum — clear meaning
typedef enum { NORTH, EAST, SOUTH, WEST } Direction;
Direction dir = SOUTH;
```

Enum values start at 0 by default and increment. You can set them explicitly:

```c
typedef enum {
    HTTP_OK        = 200,
    HTTP_NOT_FOUND = 404,
    HTTP_ERROR     = 500
} HttpStatus;

HttpStatus status = HTTP_NOT_FOUND;
printf("Status: %d\n", status);   // 404
```

## Enums in switch statements

The compiler can warn if you miss a case:

```c
typedef enum { RED, GREEN, BLUE } Color;

void print_color(Color c) {
    switch (c) {
        case RED:   printf("red\n");   break;
        case GREEN: printf("green\n"); break;
        case BLUE:  printf("blue\n");  break;
        // no default — compiler warns if a new Color value is added
    }
}
```

## typedef — type aliases

`typedef` creates a new name for an existing type:

```c
typedef unsigned long long uint64;
typedef char* string;
typedef int (*Comparator)(const void*, const void*);  // function pointer type
```

Most commonly used with structs to avoid writing `struct` everywhere:

```c
typedef struct Node {
    int data;
    struct Node *next;   // must use "struct Node" here, not just "Node"
} Node;

Node *head = NULL;   // clean — no "struct" needed
```

## typedef vs #define

```c
typedef unsigned char byte;   // proper type alias — works with pointers
#define BYTE unsigned char    // text substitution — can cause subtle bugs

byte *p;    // correct: pointer to byte
BYTE *p;    // expands to: unsigned char *p — same here, but...

typedef byte *byteptr;        // works as expected
#define BYTEPTR BYTE*
BYTEPTR a, b;   // expands to: unsigned char* a, b — b is NOT a pointer!
```

Prefer `typedef` over `#define` for types.

---

## My notes

**What confused me:**

**What clicked:**

**When I'd use an enum vs a #define:**

**Things to look up later:**
