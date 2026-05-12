# mmap, virtual memory & memory-mapped files

Map files and anonymous memory directly into the process address space.

## Learning goals

- mmap / munmap / mprotect
- Map a file read-only and scan its contents
- Anonymous mmap as a malloc alternative
- Understand page faults and demand paging

## Files

| File | Purpose |
|------|---------|
| `mmap_demo.c` | Starter file — fill in the exercises below |

## Exercises

1. Read the learning goals above.
2. Complete the TODO sections in `mmap_demo.c`.
3. Compile with: `gcc -Wall -Wextra -Werror -o out mmap_demo.c && ./out`
4. Tick this topic off your checklist once all exercises pass.

## Resources

- [C reference (cppreference)](https://en.cppreference.com/w/c)
- [Beej's Guide to C](https://beej.us/guide/bgc/)
