# Lesson: Pointer arithmetic & array decay

## Pointer arithmetic

Adding or subtracting from a pointer moves it by multiples of the pointed-to type's size:

```c
int arr[5] = {10, 20, 30, 40, 50};
int *p = arr;        // points to arr[0]

p + 1   // points to arr[1] — moves 4 bytes (sizeof int)
p + 2   // points to arr[2] — moves 8 bytes
*(p+2)  // value at arr[2] = 30
```

This is why `arr[i]` is exactly equivalent to `*(arr + i)` — it's just syntactic sugar for pointer arithmetic.

## Array decay

When you use an array name in most expressions, it **decays** into a pointer to its first element:

```c
int arr[5] = {10, 20, 30, 40, 50};
int *p = arr;   // no & needed — arr decays to &arr[0]
```

This means these are all equivalent:
```c
arr[2]
*(arr + 2)
*(p + 2)
p[2]
```

## Walking an array with a pointer

```c
int arr[5] = {10, 20, 30, 40, 50};

for (int *p = arr; p < arr + 5; p++) {
    printf("%d\n", *p);
}
```

`arr + 5` points one past the last element — this is a valid sentinel value (you can compare against it, but not dereference it).

## Pointer subtraction

Subtracting two pointers gives the number of elements between them:

```c
int arr[5] = {10, 20, 30, 40, 50};
int *start = arr;
int *end = arr + 5;
ptrdiff_t len = end - start;   // = 5
printf("%td\n", len);
```

Use `ptrdiff_t` (from `<stddef.h>`) for pointer differences — it's the correct signed type.

## Where array decay breaks

The sizeof trick for array length ONLY works in the same scope as the array declaration:

```c
void print(int *arr) {
    // sizeof(arr) here = 8 (pointer size), NOT the array size!
    // This is why you always pass length as a separate parameter
}

int main(void) {
    int arr[5];
    int len = sizeof(arr) / sizeof(arr[0]);  // = 5 — works here
    print(arr);  // arr decays to pointer, size info lost
}
```

---

## My notes

**What confused me:**

**What clicked:**

**The decay rule in my own words:**

**Things to look up later:**
