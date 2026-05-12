# Detecting & fixing memory leaks with valgrind

Use valgrind --leak-check=full to find and eliminate memory errors.

## Learning goals

- Run valgrind on a compiled binary
- Interpret 'definitely lost' vs 'still reachable'
- Fix all reported errors
- Run with AddressSanitizer as an alternative

## Files

| File | Purpose |
|------|---------|
| `leaky.c` | Starter file — fill in the exercises below |

## Exercises

1. Read the learning goals above.
2. Complete the TODO sections in `leaky.c`.
3. Compile with: `gcc -Wall -Wextra -Werror -o out leaky.c && ./out`
4. Tick this topic off your checklist once all exercises pass.

## Resources

- [C reference (cppreference)](https://en.cppreference.com/w/c)
- [Beej's Guide to C](https://beej.us/guide/bgc/)
