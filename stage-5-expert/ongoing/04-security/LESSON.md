# Lesson: Security — buffer overflows, format strings & hardening

## Stack buffer overflow

Writing past the end of a stack buffer overwrites the return address, enabling an attacker to redirect execution:

```c
void greet(char *input) {
    char buf[16];
    strcpy(buf, input);   // VULN: no bounds check
}
// Input longer than 16 bytes overwrites saved rip → arbitrary code execution
```

Fix: use `strncpy(buf, input, sizeof(buf)-1)` or `strlcpy`.

## Format string vulnerability

Passing user input directly as a printf format string:

```c
printf(user_input);          // VULN: user can supply "%s%s%s" → crash or leak
printf("%s", user_input);    // safe: user_input is treated as data, not format
```

With `%n` a format string bug can write to arbitrary memory addresses.

## Use-after-free

Accessing heap memory after it has been freed:

```c
int *p = malloc(sizeof(int));
free(p);
*p = 5;   // UB — p might be reallocated by now
```

Fix: set pointers to NULL after freeing.

## Compiler hardening flags

```bash
gcc -fstack-protector-all    # stack canaries — detect stack smashing
    -D_FORTIFY_SOURCE=2      # bounds-checked versions of string functions
    -pie -fPIE               # position-independent executable (ASLR)
    -Wl,-z,relro,-z,now      # read-only relocations (RELRO)
    -o hardened app.c
```

| Flag | Protection |
|------|-----------|
| Stack canary | Detects return address overwrite |
| ASLR + PIE | Randomises code/stack/heap addresses |
| RELRO | Makes GOT read-only after startup |
| FORTIFY_SOURCE | Bounds-checks strcpy, memcpy etc. |

## Check your binary

```bash
checksec --file=./app   # shows which protections are enabled
```

---

## My notes

**What confused me:**

**What clicked:**

**Vulnerabilities I found in the exercise:**

**Things to look up later:**
