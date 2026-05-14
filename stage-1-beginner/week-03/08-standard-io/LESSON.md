# Lesson: Standard I/O with printf & scanf

## printf — formatted output

```c
printf("Hello\n");                    // plain string
printf("Name: %s\n", "Alice");        // string
printf("Age: %d\n", 25);             // integer
printf("Score: %.2f\n", 98.756);     // float, 2 decimal places → 98.76
printf("Hex: %x\n", 255);            // hexadecimal → ff
printf("Char: %c\n", 'A');           // character
```

### Format specifier anatomy

```
%[flags][width][.precision]type
```

```c
printf("%10d\n",   42);    //  right-align in 10 chars:          42
printf("%-10d|\n", 42);    //  left-align:                42|
printf("%010d\n",  42);    //  pad with zeros:        0000000042
printf("%+d\n",    42);    //  always show sign:      +42
printf("%.4f\n",   3.14);  //  4 decimal places:      3.1400
```

## scanf — formatted input

```c
int age;
scanf("%d", &age);   // & is address-of — scanf needs to know WHERE to store the value
```

**`&` is mandatory with scanf** for basic types. Without it, scanf writes to a garbage address and crashes.

```c
char name[64];
scanf("%63s", name);   // reads one word (stops at whitespace); limit to 63 chars
```

## fgets — safe line input (prefer over scanf for strings)

```c
char line[128];
fgets(line, sizeof(line), stdin);  // reads a whole line including spaces
// fgets keeps the \n at the end — strip it if needed:
line[strcspn(line, "\n")] = '\0';
```

**Never use `gets()`** — it has no bounds checking and was removed from C11.

## Reading numbers safely

```c
int n;
if (scanf("%d", &n) != 1) {
    fprintf(stderr, "Error: expected a number\n");
}
```

`scanf` returns the number of items successfully read. Always check it.

## fprintf and stderr

```c
fprintf(stdout, "Normal output\n");     // same as printf
fprintf(stderr, "Error message\n");     // goes to error stream
```

Errors should go to `stderr` so they can be separated from normal output.

## Flushing output

`printf` output is buffered — it may not appear immediately. Force it with:

```c
fflush(stdout);
```

Or use `\n` — newlines usually flush the buffer in line-buffered mode (terminal).

---

## My notes

**What confused me:**

**What clicked:**

**Format specifiers I keep forgetting:**

**Things to look up later:**
