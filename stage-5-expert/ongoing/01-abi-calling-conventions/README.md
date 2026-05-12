# Calling conventions, ABI & link-time optimisation

Read and write assembly stubs that interoperate with C, and enable LTO.

## Learning goals

- Inspect System V AMD64 ABI with gdb
- Write a minimal .s stub that calls a C function
- Enable -flto and observe code size changes
- Read nm and objdump output

## Files

| File | Purpose |
|------|---------|
| `abi_demo.c` | Starter file — fill in the exercises below |

## Exercises

1. Read the learning goals above.
2. Complete the TODO sections in `abi_demo.c`.
3. Compile with: `gcc -Wall -Wextra -Werror -o out abi_demo.c && ./out`
4. Tick this topic off your checklist once all exercises pass.

## Resources

- [C reference (cppreference)](https://en.cppreference.com/w/c)
- [Beej's Guide to C](https://beej.us/guide/bgc/)
