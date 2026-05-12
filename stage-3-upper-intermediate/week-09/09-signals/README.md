# Signals & signal handlers

Handle asynchronous events with POSIX signal handlers.

## Learning goals

- Register a handler with sigaction
- Handle SIGINT for graceful shutdown
- Use volatile sig_atomic_t for shared flags
- Understand async-signal-safe functions

## Files

| File | Purpose |
|------|---------|
| `signals.c` | Starter file — fill in the exercises below |

## Exercises

1. Read the learning goals above.
2. Complete the TODO sections in `signals.c`.
3. Compile with: `gcc -Wall -Wextra -Werror -o out signals.c && ./out`
4. Tick this topic off your checklist once all exercises pass.

## Resources

- [C reference (cppreference)](https://en.cppreference.com/w/c)
- [Beej's Guide to C](https://beej.us/guide/bgc/)
