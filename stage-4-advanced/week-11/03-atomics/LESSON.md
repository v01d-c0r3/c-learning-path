# Lesson: _Atomic types & memory ordering

## Why atomics?

Mutex lock/unlock is expensive. For simple operations like incrementing a counter, C11 atomics provide lock-free thread safety.

```c
#include <stdatomic.h>

atomic_int counter = 0;

void *inc(void *_) {
    for (int i = 0; i < 1000000; i++) {
        atomic_fetch_add(&counter, 1);   // thread-safe increment
    }
    return NULL;
}
```

## Atomic operations

```c
atomic_int x = ATOMIC_VAR_INIT(0);

atomic_load(&x)           // read atomically
atomic_store(&x, 5)       // write atomically
atomic_fetch_add(&x, 1)   // add and return old value
atomic_fetch_sub(&x, 1)   // subtract
atomic_fetch_and(&x, mask)
atomic_fetch_or(&x, mask)
atomic_compare_exchange_strong(&x, &expected, desired)  // CAS
```

## Memory ordering

Controls how memory operations are reordered by CPU and compiler:

| Order | Meaning |
|-------|---------|
| `memory_order_relaxed` | No sync — just atomicity. Fastest. Use for counters. |
| `memory_order_acquire` | Reads after this cannot move before it |
| `memory_order_release` | Writes before this cannot move after it |
| `memory_order_seq_cst` | Total order. Default. Safest but slowest. |

```c
// Producer
data = 42;
atomic_store_explicit(&ready, 1, memory_order_release);

// Consumer
while (!atomic_load_explicit(&ready, memory_order_acquire));
printf("%d\n", data);   // guaranteed to see 42
```

## Compare-and-swap (CAS)

The foundation of lock-free programming:

```c
int expected = 0;
// if x == expected, set x = 1 and return true
if (atomic_compare_exchange_strong(&x, &expected, 1)) {
    // we "won" the CAS — x is now 1
} else {
    // someone else changed x — expected now holds the actual value
}
```

---

## My notes

**What confused me:**

**What clicked:**

**When to use relaxed vs seq_cst:**

**Things to look up later:**
