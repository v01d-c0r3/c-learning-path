# Lock-free data structures & reclamation

Implement a lock-free stack and understand hazard pointers.

## Learning goals

- Treiber stack with CAS
- ABA problem and solutions
- Epoch-based reclamation concept
- Michael-Scott queue skeleton

## Files

| File | Purpose |
|------|---------|
| `lock_free_stack.c` | Starter file — fill in the exercises below |

## Exercises

1. Read the learning goals above.
2. Complete the TODO sections in `lock_free_stack.c`.
3. Compile with: `gcc -Wall -Wextra -Werror -o out lock_free_stack.c && ./out`
4. Tick this topic off your checklist once all exercises pass.

## Resources

- [C reference (cppreference)](https://en.cppreference.com/w/c)
- [Beej's Guide to C](https://beej.us/guide/bgc/)
