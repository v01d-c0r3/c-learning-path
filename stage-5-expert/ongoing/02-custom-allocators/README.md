# Custom allocators: arena, pool & slab

Implement three allocator strategies and benchmark against malloc.

## Learning goals

- Arena allocator (bump pointer, reset in O(1))
- Pool allocator (fixed-size objects, free-list)
- Slab allocator (aligned slabs for structs)
- Benchmark allocation throughput

## Files

| File | Purpose |
|------|---------|
| `arena.c` | Starter file — fill in the exercises below |

## Exercises

1. Read the learning goals above.
2. Complete the TODO sections in `arena.c`.
3. Compile with: `gcc -Wall -Wextra -Werror -o out arena.c && ./out`
4. Tick this topic off your checklist once all exercises pass.

## Resources

- [C reference (cppreference)](https://en.cppreference.com/w/c)
- [Beej's Guide to C](https://beej.us/guide/bgc/)
