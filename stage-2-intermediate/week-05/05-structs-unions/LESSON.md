# Lesson: Structs, unions & bitfields

## Structs — grouping related data

```c
struct Point {
    int x;
    int y;
};

struct Point p1;       // declare a Point
p1.x = 3;             // access with dot operator
p1.y = 4;

struct Point p2 = {10, 20};          // initialise at declaration
struct Point p3 = {.x=10, .y=20};   // designated initialiser (C99, clearer)
```

## typedef — cleaner names

```c
typedef struct {
    char name[32];
    int  age;
    float gpa;
} Student;

Student s = {"Alice", 20, 3.8};   // no "struct" keyword needed
printf("%s is %d years old\n", s.name, s.age);
```

## Pointer to struct — use `->`

When you have a pointer to a struct, use `->` instead of `.`:

```c
Student *sp = &s;
printf("%s\n", sp->name);    // equivalent to (*sp).name
sp->age = 21;
```

`->` is just shorthand for dereferencing and accessing a member.

## Struct padding & alignment

The compiler may insert padding bytes between members to align them efficiently:

```c
struct Example {
    char  a;    // 1 byte
    // 3 bytes padding here
    int   b;    // 4 bytes — must be 4-byte aligned
    char  c;    // 1 byte
    // 3 bytes padding at end
};
// sizeof(struct Example) = 12, not 6!
```

You can check with `sizeof`. To pack tightly (e.g. for network protocols):
```c
struct __attribute__((packed)) Tight { char a; int b; char c; };
// sizeof = 6 — but may be slow to access on some CPUs
```

## Unions — shared memory

A union's members all share the same memory location. Only one member is valid at a time. Size = size of largest member.

```c
union Data {
    int   i;
    float f;
    char  str[8];
};

union Data d;
d.i = 42;
printf("%d\n", d.i);    // 42
d.f = 3.14;
printf("%d\n", d.i);    // garbage — f overwrote i's memory
```

Useful for type punning and tagged unions (storing different types with a type tag).

## Bitfields

Pack integer fields into a specific number of bits:

```c
struct Flags {
    unsigned int read    : 1;   // 1 bit
    unsigned int write   : 1;   // 1 bit
    unsigned int execute : 1;   // 1 bit
    unsigned int padding : 5;   // 5 bits to fill a byte
};

struct Flags f = {1, 0, 1, 0};
printf("read=%u exec=%u\n", f.read, f.execute);
```

Useful for hardware registers and protocol fields.

---

## My notes

**What confused me:**

**What clicked:**

**The -> vs . rule in my own words:**

**Things to look up later:**
