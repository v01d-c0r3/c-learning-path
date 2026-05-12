# _Atomic types & memory ordering

Use C11 atomics to build thread-safe counters and flags without mutexes.

## Learning goals

- _Atomic int, atomic_load, atomic_store
- atomic_fetch_add / sub / and / or
- memory_order_relaxed vs sequentially consistent
- Build a lock-free reference counter

## Files

| File | Purpose |
|------|---------|
| `atomics.c` | Starter file — fill in the exercises below |

## Exercises

1. Read the learning goals above.
2. Complete the TODO sections in `atomics.c`.
3. Compile with: `gcc -Wall -Wextra -Werror -o out atomics.c && ./out`
4. Tick this topic off your checklist once all exercises pass.

## Resources

- [C reference (cppreference)](https://en.cppreference.com/w/c)
- [Beej's Guide to C](https://beej.us/guide/bgc/)
