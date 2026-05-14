# Lesson: Compiling with warnings & first debugger session

## Compiler warnings are your friend

Always compile with:
```bash
gcc -Wall -Wextra -Werror -g -o out buggy.c
```

`-g` adds debug symbols so gdb can show you line numbers and variable names.

Common warnings and what they mean:

| Warning | Meaning |
|---------|---------|
| `unused variable` | You declared a variable but never used it |
| `implicit declaration of function` | Missing #include |
| `uninitialized variable` | Reading a variable before setting it |
| `comparison between signed and unsigned` | Mixing int and size_t |
| `control reaches end of non-void function` | Function might not return a value |

## gdb — the GNU debugger

### Basic workflow

```bash
gcc -g -o out buggy.c     # compile with debug info
gdb ./out                  # start debugger
```

### Essential gdb commands

```
(gdb) run                  # start the program
(gdb) break main           # set breakpoint at start of main
(gdb) break 15             # set breakpoint at line 15
(gdb) next                 # execute next line (step over functions)
(gdb) step                 # execute next line (step into functions)
(gdb) print x              # print value of variable x
(gdb) print arr[0]         # print array element
(gdb) backtrace            # show call stack
(gdb) continue             # run until next breakpoint
(gdb) quit                 # exit gdb
```

### Example session

```bash
$ gdb ./out
(gdb) break main
Breakpoint 1 at 0x401136: file buggy.c, line 5.
(gdb) run
Breakpoint 1, main () at buggy.c:5
5       int total;
(gdb) next
6       for (int i = 1; i <= 10; i++)
(gdb) next
7           total =+ i;
(gdb) print total
$1 = 0      ← uninitialised — garbage value
(gdb) continue
(gdb) print total
$2 = 10     ← bug: =+ assigns, not adds
```

## AddressSanitizer — fast memory error detection

Easier than valgrind for quick checks:

```bash
gcc -fsanitize=address -g -o out buggy.c
./out
```

ASan will immediately report out-of-bounds access, use-after-free, and memory leaks with a clear stack trace.

## printf debugging

The simplest debugging technique — add print statements to trace values:

```c
printf("DEBUG: x = %d at line %d\n", x, __LINE__);
```

`__LINE__` is a built-in macro that expands to the current line number. Remove debug prints before committing code.

---

## My notes

**What confused me:**

**What clicked:**

**gdb commands I want to remember:**

**Bugs I found in the exercise:**

**Things to look up later:**
