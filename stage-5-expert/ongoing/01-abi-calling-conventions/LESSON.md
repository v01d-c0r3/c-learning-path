# Lesson: Calling conventions, ABI & link-time optimisation

## What is an ABI?

The Application Binary Interface defines how compiled code communicates at the binary level: how function arguments are passed, where return values go, which registers a function must preserve, and how the stack is laid out.

## System V AMD64 ABI (Linux x86-64)

Integer/pointer arguments go in registers (in order): `rdi, rsi, rdx, rcx, r8, r9`. Additional args go on the stack. Return value goes in `rax`.

```c
int add(int a, int b) { return a + b; }
// a → rdi (lower 32 bits: edi)
// b → rsi (lower 32 bits: esi)
// return value → rax (lower 32: eax)
```

View the assembly:
```bash
gcc -O0 -S -o add.s add.c   # produces human-readable assembly
```

## Caller-saved vs callee-saved registers

**Caller-saved** (`rax, rcx, rdx, rsi, rdi, r8-r11`) — a function may modify these freely. The caller must save them before calling if it needs them.

**Callee-saved** (`rbx, rbp, r12-r15`) — a function must restore these before returning.

## Link-time optimisation (LTO)

Without LTO, each `.c` file is compiled independently — the compiler can't optimise across files. With LTO, the linker runs optimisation across the entire program:

```bash
gcc -O2 -flto -o app main.c utils.c   # enables whole-program optimisation
```

Benefits: inlining across translation units, dead code elimination, better constant propagation. Can significantly reduce binary size and improve performance.

## nm and objdump

```bash
nm app           # list symbols (functions, globals) in a binary
objdump -d app   # disassemble — show assembly for each function
readelf -h app   # show ELF header info
```

---

## My notes

**What confused me:**

**What clicked:**

**Things to look up later:**
