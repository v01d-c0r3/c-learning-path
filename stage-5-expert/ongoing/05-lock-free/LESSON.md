# Lesson: Lock-free data structures & reclamation

## Compare-and-swap (CAS) — the foundation

CAS atomically does: if *addr == expected, set *addr = desired and return true.

```c
atomic_compare_exchange_strong(&x, &expected, desired)
```

If another thread modified `x` between your read and your CAS, the CAS fails and you retry.

## Treiber stack — lock-free push/pop

```c
typedef struct Node { int val; struct Node *next; } Node;
typedef struct { _Atomic(Node*) top; } Stack;

void push(Stack *s, int v) {
    Node *n = malloc(sizeof(Node));
    n->val = v;
    Node *old;
    do {
        old = atomic_load(&s->top);
        n->next = old;
    } while (!atomic_compare_exchange_weak(&s->top, &old, n));
}
```

The loop retries if another thread pushed between the load and the CAS.

## ABA problem

Thread 1 reads top = A. Thread 2 pops A, pushes B, pushes A again. Thread 1's CAS succeeds — but the list has changed! Fix with a version tag:

```c
typedef struct { Node *ptr; uintptr_t tag; } TaggedPtr;
// CAS on {ptr, tag} — tag increments on each operation
```

## Memory reclamation — why you can't just free

In lock-free code, another thread might be reading a node while you free it. Solutions:

- **Hazard pointers** — threads publish which nodes they're accessing; free only nodes not in any hazard pointer list
- **Epoch-based reclamation** — defer frees until all threads have passed through a new epoch
- **RCU (Read-Copy-Update)** — used in the Linux kernel; readers are extremely cheap

## Michael-Scott queue

Classic lock-free FIFO queue using two CAS operations (head and tail). The key insight: use a sentinel (dummy) node to decouple head and tail operations.

```
sentinel → [A] → [B] → [C] → NULL
^head                          ^tail
```

---

## My notes

**What confused me:**

**What clicked:**

**The ABA problem in my own words:**

**Things to look up later:**
