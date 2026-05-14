# Lesson: File I/O — fopen, fread, fwrite, fclose

## Opening and closing files

```c
#include <stdio.h>

FILE *f = fopen("data.txt", "r");   // open for reading
if (f == NULL) {
    perror("fopen");   // prints error message
    return 1;
}
// ... use f ...
fclose(f);
```

Always check if `fopen` returned NULL. Always `fclose` when done.

## Mode strings

| Mode | Meaning |
|------|---------|
| `"r"` | Read — file must exist |
| `"w"` | Write — creates or truncates |
| `"a"` | Append — creates or appends |
| `"r+"` | Read and write — file must exist |
| `"rb"` | Read binary |
| `"wb"` | Write binary |

## Text mode — reading and writing lines

```c
// Write
FILE *f = fopen("output.txt", "w");
fprintf(f, "Line %d\n", 1);
fprintf(f, "Hello, %s\n", "World");
fclose(f);

// Read line by line
FILE *f = fopen("output.txt", "r");
char line[256];
while (fgets(line, sizeof(line), f) != NULL) {
    printf("%s", line);   // fgets keeps the \n
}
fclose(f);
```

## Binary mode — reading and writing raw bytes

Binary mode is for structs, images, audio — anything that isn't text:

```c
typedef struct { int x; int y; } Point;

// Write
FILE *f = fopen("points.bin", "wb");
Point pts[3] = {{1,2},{3,4},{5,6}};
fwrite(pts, sizeof(Point), 3, f);   // write 3 Point structs
fclose(f);

// Read back
FILE *f = fopen("points.bin", "rb");
Point pts[3];
fread(pts, sizeof(Point), 3, f);    // read 3 Point structs
fclose(f);
printf("%d %d\n", pts[1].x, pts[1].y);   // 3 4
```

`fwrite(ptr, size, count, file)` — writes count items, each of size bytes.

## File position — fseek and ftell

```c
fseek(f, 0, SEEK_END);   // jump to end
long size = ftell(f);    // get position = file size in bytes
fseek(f, 0, SEEK_SET);   // jump back to start
```

| Constant | Meaning |
|----------|---------|
| `SEEK_SET` | From beginning |
| `SEEK_CUR` | From current position |
| `SEEK_END` | From end |

## Checking for errors

```c
if (fwrite(data, size, count, f) != count) {
    perror("fwrite");
}
if (ferror(f)) {
    printf("An error occurred\n");
}
```

---

## My notes

**What confused me:**

**What clicked:**

**Text vs binary mode — the difference in my own words:**

**Things to look up later:**
