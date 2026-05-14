# Lesson: Hello, World & the compilation pipeline

## What is C?

C is a compiled, statically-typed, low-level language created in 1972. Unlike Python or JavaScript, C code is not interpreted line by line — it is translated directly into machine code your CPU runs. This makes it extremely fast, and also means mistakes can crash your program or corrupt memory silently.

## The four stages of compilation

When you run `gcc hello.c -o hello`, four things happen under the hood:

```
hello.c  →  [Preprocessor]  →  hello.i
         →  [Compiler]      →  hello.s   (assembly)
         →  [Assembler]     →  hello.o   (object file)
         →  [Linker]        →  hello     (executable)
```

**Preprocessor** — handles lines starting with `#`. It copies the contents of `<stdio.h>` into your file, expands macros, and strips comments. You can see the output with `gcc -E hello.c`.

**Compiler** — translates C into assembly for your CPU. See it with `gcc -S hello.c` — this produces `hello.s`.

**Assembler** — converts assembly into binary object code (`hello.o`). See it with `gcc -c hello.c`.

**Linker** — combines your object file with libraries (like the C standard library that contains `printf`) into the final executable.

## Your first program explained line by line

```c
#include <stdio.h>        // tell the preprocessor to include standard I/O declarations

int main(void) {          // every C program starts at main(); int = return type; void = no args
    printf("Hello!\n");   // call printf from stdio.h; \n = newline character
    return 0;             // 0 means "success" to the operating system
}
```

## Compiler flags you should always use

```bash
gcc -Wall -Wextra -Werror -o out hello.c
```

| Flag | Meaning |
|------|---------|
| `-Wall` | Enable most common warnings |
| `-Wextra` | Enable extra warnings `-Wall` misses |
| `-Werror` | Treat warnings as errors — forces you to fix them |
| `-o out` | Name the output binary `out` instead of `a.out` |
| `-g` | Include debug info (needed for gdb) |

## Running your program

```bash
./out        # ./ means "in the current directory"
```

## Common beginner errors

**"implicit declaration of function"** — you forgot `#include <stdio.h>`. The compiler doesn't know what `printf` is.

**"undefined reference to main"** — your `main` function is missing or spelled wrong.

**Permission denied on `./out`** — the file isn't executable. Run `chmod +x out`.

---

## My notes

> *Use this section as you work through the exercise. Write things in your own words — it massively helps retention.*

**What confused me:**

**What clicked:**

**Commands I want to remember:**

**Things to look up later:**
