# CMake, shared/static libs & cross-compilation

Build a multi-target CMake project with a library and an executable.

## Learning goals

- Write a CMakeLists.txt with add_library + add_executable
- Link with target_link_libraries
- Build a shared .so and a static .a
- Cross-compile for ARM with a toolchain file

## Files

| File | Purpose |
|------|---------|
| `main.c` | Starter file — fill in the exercises below |

## Exercises

1. Read the learning goals above.
2. Complete the TODO sections in `main.c`.
3. Compile with: `gcc -Wall -Wextra -Werror -o out main.c && ./out`
4. Tick this topic off your checklist once all exercises pass.

## Resources

- [C reference (cppreference)](https://en.cppreference.com/w/c)
- [Beej's Guide to C](https://beej.us/guide/bgc/)
