# Lesson: Function pointers & callbacks

## What is a function pointer?

Just as a variable can hold an integer or a string, a function pointer holds the address of a function. You can call a function through its pointer.

```c
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

int (*op)(int, int);   // declare a function pointer: returns int, takes two ints
op = add;              // assign — no & needed for function names
printf("%d\n", op(3, 4));   // call through pointer — prints 7
op = sub;
printf("%d\n", op(3, 4));   // prints -1
```

## Reading the declaration

`int (*op)(int, int)` — read it as: "op is a pointer to a function that takes two ints and returns int."

The parentheses around `*op` are essential. Without them:

```c
int *op(int, int);   // completely different — a function returning int*
```

## typedef for cleaner syntax

```c
typedef int (*BinaryOp)(int, int);   // BinaryOp is now the type name

BinaryOp op = add;
printf("%d\n", op(10, 5));
```

## Callbacks — passing functions as arguments

```c
void apply(int *arr, int len, int (*transform)(int)) {
    for (int i = 0; i < len; i++) {
        arr[i] = transform(arr[i]);
    }
}

int double_it(int x) { return x * 2; }
int square(int x)    { return x * x; }

int main(void) {
    int arr[5] = {1, 2, 3, 4, 5};
    apply(arr, 5, double_it);   // arr = {2,4,6,8,10}
    apply(arr, 5, square);      // arr = {4,16,36,64,100}
    return 0;
}
```

## qsort — the standard library uses callbacks

```c
#include <stdlib.h>

int cmp_asc(const void *a, const void *b) {
    return *(int*)a - *(int*)b;   // cast void* back to int*
}

int arr[5] = {5, 2, 8, 1, 9};
qsort(arr, 5, sizeof(int), cmp_asc);
// arr = {1, 2, 5, 8, 9}
```

## Dispatch table — replace switch with an array of function pointers

```c
typedef void (*Handler)(void);

void handle_a(void) { printf("A\n"); }
void handle_b(void) { printf("B\n"); }
void handle_c(void) { printf("C\n"); }

Handler table[3] = { handle_a, handle_b, handle_c };
table[1]();   // calls handle_b — no switch needed
```

---

## My notes

**What confused me:**

**What clicked:**

**The function pointer declaration in my own words:**

**Things to look up later:**
