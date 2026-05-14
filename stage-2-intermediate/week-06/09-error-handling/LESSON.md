# Lesson: Error handling with errno & perror

## C's error handling philosophy

C does not have exceptions. Errors are communicated through:
1. **Return values** — functions return -1, NULL, or 0 on failure
2. **errno** — a global integer set by system calls to indicate what went wrong
3. **perror / strerror** — functions that turn errno into a human-readable message

## errno

`errno` is a global variable (technically a macro) defined in `<errno.h>`. System calls set it when they fail:

```c
#include <errno.h>
#include <stdio.h>

FILE *f = fopen("nonexistent.txt", "r");
if (f == NULL) {
    printf("errno = %d\n", errno);       // e.g. 2
    printf("error = %s\n", strerror(errno));  // "No such file or directory"
}
```

`errno` is only meaningful immediately after a failing call — subsequent calls may overwrite it.

## perror — print error with context

```c
FILE *f = fopen("secret.txt", "r");
if (f == NULL) {
    perror("fopen");   // prints: "fopen: No such file or directory"
    return 1;
}
```

`perror(msg)` prints `msg: <errno description>` to stderr. Always use it over printf for system errors.

## Common errno values

| Value | Constant | Meaning |
|-------|----------|---------|
| 1 | `EPERM` | Operation not permitted |
| 2 | `ENOENT` | No such file or directory |
| 12 | `ENOMEM` | Out of memory |
| 13 | `EACCES` | Permission denied |
| 17 | `EEXIST` | File already exists |
| 22 | `EINVAL` | Invalid argument |

## Return code conventions

```c
// Functions return 0 on success, negative on error
int result = do_something();
if (result < 0) {
    fprintf(stderr, "Error: %d\n", result);
    return result;  // propagate error up
}

// Functions return NULL on failure
char *buf = malloc(100);
if (buf == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
}
```

## assert — catching programmer errors

```c
#include <assert.h>

void process(int *arr, int len) {
    assert(arr != NULL);    // crash immediately with a message if false
    assert(len > 0);
    // ...
}
```

`assert` is for impossible conditions that indicate bugs. It can be disabled in release builds with `-DNDEBUG`. Do not use it for expected errors (file not found, user input invalid).

## A safe malloc wrapper

```c
void *safe_malloc(size_t n) {
    void *p = malloc(n);
    if (p == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    return p;
}
```

---

## My notes

**What confused me:**

**What clicked:**

**The errno pattern in my own words:**

**Things to look up later:**
