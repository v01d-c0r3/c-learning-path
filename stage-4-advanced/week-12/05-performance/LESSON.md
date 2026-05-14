# Lesson: Cache locality, profiling & SIMD intro

## CPU caches

RAM is slow (~100ns). CPUs have small, fast caches (L1: ~1ns, L2: ~4ns, L3: ~10ns). Code that accesses memory in predictable, sequential patterns is fast. Code that jumps around is slow.

## Cache-friendly vs cache-hostile

```c
// Cache-friendly: row-major traversal (sequential memory access)
for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
        sum += matrix[i][j];   // each access is 4 bytes after the last

// Cache-hostile: column-major traversal (jumps by N*4 bytes each step)
for (int j = 0; j < N; j++)
    for (int i = 0; i < N; i++)
        sum += matrix[i][j];   // jumps across rows — cache misses
```

On a 1024×1024 matrix, row-major is typically 5-10x faster.

## Profiling with perf

```bash
gcc -O2 -g -o out perf_demo.c
perf stat ./out            # high-level counters: cache misses, cycles
perf record ./out          # record detailed profile
perf report                # interactive browser of hotspots
```

Look for: `cache-misses`, `LLC-load-misses` (last-level cache). High values = fix memory access patterns.

## Compiler optimisation levels

| Flag | Meaning |
|------|---------|
| `-O0` | No optimisation (default) |
| `-O1` | Basic optimisations |
| `-O2` | Most optimisations — use for production |
| `-O3` | Aggressive — may increase code size |
| `-Os` | Optimise for size |

## SIMD — Single Instruction, Multiple Data

Process multiple values in one CPU instruction:

```c
#include <immintrin.h>   // AVX2

// Add 8 ints at once using 256-bit AVX2 registers
__m256i a = _mm256_loadu_si256((__m256i*)arr_a);
__m256i b = _mm256_loadu_si256((__m256i*)arr_b);
__m256i c = _mm256_add_epi32(a, b);
_mm256_storeu_si256((__m256i*)arr_c, c);
```

Compile with `-mavx2`. For portable SIMD, let the compiler auto-vectorise with `-O2 -ftree-vectorize`.

---

## My notes

**What confused me:**

**What clicked:**

**Cache miss vs cache hit in my own words:**

**Things to look up later:**
