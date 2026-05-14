# Lesson: Double indirection & pointer-to-pointer

## What is double indirection?

A pointer to a pointer — `int **pp` — holds the address of another pointer.

```c
int   x  = 42;
int  *p  = &x;    // p  holds address of x
int **pp = &p;    // pp holds address of p

printf("%d\n", **pp);   // dereference twice to get x = 42
**pp = 99;              // modifies x through two levels of indirection
```

## Why you need it: modifying a pointer from a function

Passing a pointer by value means the function gets a copy. To modify the original pointer (not just the value it points to), pass a pointer-to-pointer:

```c
void allocate(int **out, int n) {
    *out = malloc(n * sizeof(int));   // modifies the pointer in the caller
}

int main(void) {
    int *arr = NULL;
    allocate(&arr, 5);   // pass address of the pointer
    arr[0] = 10;
    free(arr);
}
```

## argv — char**

`main`'s `argv` is a classic example of double indirection:

```c
int main(int argc, char **argv) {
    // argv[0] = program name
    // argv[1] = first argument
    // argv[argc] = NULL sentinel

    for (int i = 0; i < argc; i++) {
        printf("arg[%d] = %s\n", i, argv[i]);
    }
}
```

`argv` is an array of `char*` pointers — each element points to a C string.

## Array of strings

```c
char *words[] = {"apple", "banana", "cherry", NULL};
char **p = words;

while (*p != NULL) {
    printf("%s\n", *p);
    p++;
}
```

---

## My notes

**What confused me:**

**What clicked:**

**Double indirection in my own words:**

**Things to look up later:**
