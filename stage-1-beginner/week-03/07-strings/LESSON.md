# Lesson: Strings as null-terminated char arrays

## What is a string in C?

C has no built-in string type. A string is simply an array of `char` values with a **null terminator** (`\0`) at the end. The null byte tells functions where the string ends.

```c
char name[6] = {'H','e','l','l','o','\0'};  // explicit
char name[]  = "Hello";                      // same thing — compiler adds \0
```

Memory layout of `"Hello"`:

```
 H  e  l  l  o  \0
[0][1][2][3][4][5]
```

The array needs to be at least length+1 to hold the null terminator. `"Hello"` needs 6 bytes, not 5.

## String literals vs char arrays

```c
char *s1 = "Hello";    // pointer to read-only memory — do NOT modify
char  s2[] = "Hello";  // writable copy on the stack — safe to modify
```

Modifying `s1[0] = 'h'` is undefined behaviour (likely a crash). Always use `char arr[]` when you need to modify a string.

## The string.h library

```c
#include <string.h>

strlen(s)             // length NOT including \0
strcpy(dest, src)     // copy src into dest — dangerous if dest too small
strncpy(dest, src, n) // copy at most n bytes — safer
strcat(dest, src)     // append src to dest — dangerous if dest too small
strncat(dest, src, n) // append at most n bytes — safer
strcmp(s1, s2)        // 0 if equal, <0 if s1<s2, >0 if s1>s2
strstr(haystack, needle) // find needle in haystack, returns pointer or NULL
```

## Safe string example

```c
char buf[32] = "Hello";
strncat(buf, ", World!", sizeof(buf) - strlen(buf) - 1);
printf("%s\n", buf);   // Hello, World!
```

Always leave room for `\0`. A buffer overflow here corrupts memory.

## Iterating over a string

```c
char s[] = "Hello";
for (int i = 0; s[i] != '\0'; i++) {
    printf("%c\n", s[i]);
}

// or with a pointer
for (char *p = s; *p != '\0'; p++) {
    printf("%c\n", *p);
}
```

## Character functions — ctype.h

```c
#include <ctype.h>

isupper('A')    // true
islower('a')    // true
isdigit('5')    // true
isalpha('z')    // true
toupper('a')    // returns 'A'
tolower('Z')    // returns 'z'
```

---

## My notes

**What confused me:**

**What clicked:**

**String functions I keep forgetting:**

**Things to look up later:**
