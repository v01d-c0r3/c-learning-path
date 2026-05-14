# Lesson: Functions — parameters, return values, scope

## Why functions?

Functions let you name a piece of logic, reuse it, and test it in isolation. Without them, every program is one giant `main`.

## Anatomy of a function

```c
//  return type  name     parameters
    int          add     (int a, int b) {
        return a + b;   // return value
    }
```

## Declaration vs definition

C reads files top to bottom. If you call a function before defining it, the compiler complains. Fix it with a **prototype** (declaration) at the top:

```c
#include <stdio.h>

int add(int a, int b);   // prototype — just the signature, no body

int main(void) {
    printf("%d\n", add(3, 4));  // OK — compiler knows add exists
    return 0;
}

int add(int a, int b) {  // definition — the actual body
    return a + b;
}
```

## Pass by value

C always passes arguments **by value** — the function gets a copy. Modifying a parameter inside the function does NOT change the original:

```c
void double_it(int x) {
    x = x * 2;  // only modifies the local copy
}

int main(void) {
    int n = 5;
    double_it(n);
    printf("%d\n", n);  // still 5!
    return 0;
}
```

To actually modify a variable from inside a function, you need pointers (Stage 2).

## void functions

A function that does something but returns nothing:

```c
void print_greeting(char *name) {
    printf("Hello, %s!\n", name);
    // no return needed (or use bare "return;")
}
```

## Scope — where variables live

```c
int global = 10;   // global scope — visible everywhere in the file

void foo(void) {
    int local = 20;    // local scope — only visible inside foo
    printf("%d\n", global);  // can see global
    printf("%d\n", local);   // can see local
}

int main(void) {
    printf("%d\n", global);  // can see global
    // printf("%d\n", local); // ERROR — local is not visible here
    return 0;
}
```

Prefer local variables. Global variables make programs hard to reason about.

## Recursion

A function that calls itself. Needs a base case to stop:

```c
int factorial(int n) {
    if (n <= 1) return 1;          // base case
    return n * factorial(n - 1);   // recursive case
}
// factorial(5) = 5 * 4 * 3 * 2 * 1 = 120
```

Every recursive call uses stack space. Too many calls = stack overflow.

---

## My notes

**What confused me:**

**What clicked:**

**Function patterns I want to remember:**

**Things to look up later:**
