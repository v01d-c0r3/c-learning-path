# C Learning Path

A structured repository for learning C from beginner to expert.

## Structure

| Stage | Folder | Weeks | Topics |
|-------|--------|-------|--------|
| 1 — Beginner | `stage-1-beginner/` | 1–3 | Syntax, types, arrays, strings, I/O |
| 2 — Intermediate | `stage-2-intermediate/` | 4–6 | Pointers, memory, structs, files |
| 3 — Upper-intermediate | `stage-3-upper-intermediate/` | 7–9 | Data structures, algorithms, POSIX |
| 4 — Advanced | `stage-4-advanced/` | 10–13 | Concurrency, sockets, performance |
| 5 — Expert | `stage-5-expert/` | Ongoing | ABI, allocators, security, lock-free |

## How to use

1. Work through each stage in order — later stages build on earlier ones.
2. Open the topic folder, read `README.md`, and complete the TODOs in the `.c` file.
3. Compile with: `gcc -Wall -Wextra -Werror -g -o out <file>.c && ./out`
4. Once all TODOs pass, tick the topic off in your checklist.

## Compile flags cheat sheet

```bash
# Basic
gcc -Wall -Wextra -Werror -g -o out file.c

# With sanitisers (stage 3+)
gcc -Wall -Wextra -Werror -g -fsanitize=address,undefined -o out file.c

# Optimised + LTO (stage 5)
gcc -O2 -flto -o out file.c
```

## Resources

- [Beej's Guide to C Programming](https://beej.us/guide/bgc/)
- [C reference — cppreference](https://en.cppreference.com/w/c)
- [Modern C — Jens Gustedt (free PDF)](https://gustedt.gitlabpages.inria.fr/modern-c/)
- [Linux man pages](https://man7.org/linux/man-pages/)
