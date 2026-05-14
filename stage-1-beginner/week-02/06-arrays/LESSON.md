# Lesson: 1D & 2D arrays

## What is an array?

A contiguous block of memory holding multiple values of the same type. Elements are accessed by index starting at 0.

```c
int scores[5];              // declares 5 ints — uninitialised (contains garbage)
int scores[5] = {10, 20, 30, 40, 50};  // declares and initialises
int scores[]  = {10, 20, 30, 40, 50};  // size inferred from initialiser
```

## Accessing elements

```c
int arr[5] = {10, 20, 30, 40, 50};
printf("%d\n", arr[0]);   // 10 — first element
printf("%d\n", arr[4]);   // 50 — last element
arr[2] = 99;              // modify third element
```

**There is no bounds checking in C.** `arr[5]` or `arr[-1]` are out of bounds — they access random memory and can crash your program or corrupt data silently.

## Iterating over an array

```c
int arr[5] = {10, 20, 30, 40, 50};
int len = sizeof(arr) / sizeof(arr[0]);  // = 5

for (int i = 0; i < len; i++) {
    printf("%d\n", arr[i]);
}
```

`sizeof(arr) / sizeof(arr[0])` is the standard idiom for getting array length. It only works when `arr` is declared in the same scope — not after passing to a function.

## Passing arrays to functions

Arrays decay to a pointer when passed to a function — you lose the size information:

```c
void print_array(int *arr, int len) {  // must pass length separately
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int nums[5] = {1, 2, 3, 4, 5};
    print_array(nums, 5);
    return 0;
}
```

## 2D arrays

```c
int grid[3][4];   // 3 rows, 4 columns

// initialise
int grid[3][4] = {
    {1,  2,  3,  4},
    {5,  6,  7,  8},
    {9, 10, 11, 12}
};

// access row 1, column 2 (zero-indexed)
printf("%d\n", grid[1][2]);   // 7

// iterate
for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 4; col++) {
        printf("%3d ", grid[row][col]);
    }
    printf("\n");
}
```

## Memory layout

A 2D array is stored in **row-major order** in memory — all of row 0 first, then row 1, etc. This means iterating row by row (as above) is cache-friendly and fast.

---

## My notes

**What confused me:**

**What clicked:**

**Array patterns I want to remember:**

**Things to look up later:**
