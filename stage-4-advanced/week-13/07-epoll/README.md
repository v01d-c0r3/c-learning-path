# select/poll/epoll I/O multiplexing

Handle many connections in a single thread with event-driven I/O.

## Learning goals

- select for portability
- poll with a dynamic array
- epoll for scalable Linux I/O
- Level-triggered vs edge-triggered

## Files

| File | Purpose |
|------|---------|
| `epoll_server.c` | Starter file — fill in the exercises below |

## Exercises

1. Read the learning goals above.
2. Complete the TODO sections in `epoll_server.c`.
3. Compile with: `gcc -Wall -Wextra -Werror -o out epoll_server.c && ./out`
4. Tick this topic off your checklist once all exercises pass.

## Resources

- [C reference (cppreference)](https://en.cppreference.com/w/c)
- [Beej's Guide to C](https://beej.us/guide/bgc/)
