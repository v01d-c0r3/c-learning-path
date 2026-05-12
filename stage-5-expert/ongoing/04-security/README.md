# Security: buffer overflows, format strings & hardening

Exploit and fix classic C vulnerabilities; apply compiler hardening.

## Learning goals

- Stack buffer overflow (controlled environment)
- Format string vulnerability
- Use-after-free
- Apply -fstack-protector-all, RELRO, PIE, -D_FORTIFY_SOURCE

## Files

| File | Purpose |
|------|---------|
| `vuln_demo.c` | Starter file — fill in the exercises below |

## Exercises

1. Read the learning goals above.
2. Complete the TODO sections in `vuln_demo.c`.
3. Compile with: `gcc -Wall -Wextra -Werror -o out vuln_demo.c && ./out`
4. Tick this topic off your checklist once all exercises pass.

## Resources

- [C reference (cppreference)](https://en.cppreference.com/w/c)
- [Beej's Guide to C](https://beej.us/guide/bgc/)
