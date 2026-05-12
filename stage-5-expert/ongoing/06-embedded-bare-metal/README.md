# Embedded & bare-metal: linker scripts, MMIO, RTOS

Write firmware-style C that runs without an OS.

## Learning goals

- Read and write a custom linker script
- Toggle a GPIO via MMIO (simulated)
- Write an ISR in C
- Understand startup code (_start, .bss zeroing)

## Files

| File | Purpose |
|------|---------|
| `bare_metal_sim.c` | Starter file — fill in the exercises below |

## Exercises

1. Read the learning goals above.
2. Complete the TODO sections in `bare_metal_sim.c`.
3. Compile with: `gcc -Wall -Wextra -Werror -o out bare_metal_sim.c && ./out`
4. Tick this topic off your checklist once all exercises pass.

## Resources

- [C reference (cppreference)](https://en.cppreference.com/w/c)
- [Beej's Guide to C](https://beej.us/guide/bgc/)
