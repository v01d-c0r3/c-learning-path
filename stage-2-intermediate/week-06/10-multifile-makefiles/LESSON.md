# Lesson: Multi-file projects, headers & Makefiles

## Why split across files?

As projects grow, putting everything in one file becomes unmanageable. Splitting into files lets you:
- Compile only changed files (faster builds)
- Reuse code across projects
- Work on parts independently

## Header files — the interface

A `.h` file declares what exists. A `.c` file defines how it works.

```c
// mathutils.h — declarations only
#ifndef MATHUTILS_H    // header guard — prevents double inclusion
#define MATHUTILS_H

int add(int a, int b);
int subtract(int a, int b);

#endif  // MATHUTILS_H
```

```c
// mathutils.c — definitions
#include "mathutils.h"

int add(int a, int b)      { return a + b; }
int subtract(int a, int b) { return a - b; }
```

```c
// main.c — use the library
#include <stdio.h>
#include "mathutils.h"   // use quotes for your own headers, <> for system

int main(void) {
    printf("%d\n", add(3, 4));
    return 0;
}
```

## Compiling a multi-file project manually

```bash
gcc -c mathutils.c -o mathutils.o   # compile to object file
gcc -c main.c -o main.o             # compile to object file
gcc main.o mathutils.o -o program   # link together
```

## Makefiles — automate the build

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Default target
all: program

# Link
program: main.o mathutils.o
	$(CC) main.o mathutils.o -o program

# Compile
main.o: main.c mathutils.h
	$(CC) $(CFLAGS) -c main.c -o main.o

mathutils.o: mathutils.c mathutils.h
	$(CC) $(CFLAGS) -c mathutils.c -o mathutils.o

# Remove build artefacts
clean:
	rm -f *.o program
```

**Indentation in Makefiles must be a TAB, not spaces.** This is a notorious gotcha.

Run with:
```bash
make          # builds 'all' target
make clean    # removes object files and binary
```

make only recompiles files that have changed (based on timestamps), making large builds fast.

## extern — sharing globals across files

```c
// config.h
extern int debug_level;   // declaration — tells compiler it exists somewhere

// config.c
int debug_level = 0;      // definition — the actual variable

// main.c
#include "config.h"
debug_level = 2;          // works — linker finds it in config.o
```

Minimise globals. Pass values as function parameters instead where possible.

---

## My notes

**What confused me:**

**What clicked:**

**The .h vs .c distinction in my own words:**

**Makefile rules I want to remember:**

**Things to look up later:**
