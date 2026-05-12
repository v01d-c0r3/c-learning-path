# Cache locality, profiling & SIMD intro

Measure and improve program performance using perf and cache-friendly layout.

## Learning goals

- Use perf stat and perf record
- Compare row-major vs column-major matrix traversal
- Use __builtin_prefetch
- Intro to SSE/AVX intrinsics for SIMD add

## Files

| File | Purpose |
|------|---------|
| `perf_demo.c` | Starter file — fill in the exercises below |

## Exercises

1. Read the learning goals above.
2. Complete the TODO sections in `perf_demo.c`.
3. Compile with: `gcc -Wall -Wextra -Werror -o out perf_demo.c && ./out`
4. Tick this topic off your checklist once all exercises pass.

## Resources

- [C reference (cppreference)](https://en.cppreference.com/w/c)
- [Beej's Guide to C](https://beej.us/guide/bgc/)
