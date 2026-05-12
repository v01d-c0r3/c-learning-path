# AddressSanitizer & advanced debugging

Use Clang/GCC sanitisers to catch memory errors automatically.

## Learning goals

- Compile with -fsanitize=address,undefined
- Interpret ASan stack traces
- Find use-after-free and out-of-bounds errors
- Use UBSan to catch undefined behaviour

## Files

| File | Purpose |
|------|---------|
| `asan_demo.c` | Starter file — fill in the exercises below |

## Exercises

1. Read the learning goals above.
2. Complete the TODO sections in `asan_demo.c`.
3. Compile with: `gcc -Wall -Wextra -Werror -o out asan_demo.c && ./out`
4. Tick this topic off your checklist once all exercises pass.

## Resources

- [C reference (cppreference)](https://en.cppreference.com/w/c)
- [Beej's Guide to C](https://beej.us/guide/bgc/)
