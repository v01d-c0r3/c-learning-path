# Undefined behaviour & sanitisers

Find and fix the most dangerous classes of C UB.

## Learning goals

- Signed integer overflow
- Strict aliasing violations
- Misaligned access
- Compile with -fsanitize=undefined and fix all reports

## Files

| File | Purpose |
|------|---------|
| `ub_demo.c` | Starter file — fill in the exercises below |

## Exercises

1. Read the learning goals above.
2. Complete the TODO sections in `ub_demo.c`.
3. Compile with: `gcc -Wall -Wextra -Werror -o out ub_demo.c && ./out`
4. Tick this topic off your checklist once all exercises pass.

## Resources

- [C reference (cppreference)](https://en.cppreference.com/w/c)
- [Beej's Guide to C](https://beej.us/guide/bgc/)
