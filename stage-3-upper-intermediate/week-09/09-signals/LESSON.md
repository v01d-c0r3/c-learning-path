# Lesson: Signals & signal handlers

## What is a signal?

A signal is an asynchronous notification sent to a process. The OS delivers it, interrupting normal execution.

Common signals:

| Signal | Number | Default action | Meaning |
|--------|--------|---------------|---------|
| `SIGINT` | 2 | Terminate | Ctrl+C |
| `SIGTERM` | 15 | Terminate | Polite kill |
| `SIGKILL` | 9 | Terminate | Forceful kill (cannot be caught) |
| `SIGSEGV` | 11 | Core dump | Segfault |
| `SIGALRM` | 14 | Terminate | Timer expired |

## sigaction — register a handler

```c
#include <signal.h>

void handle_sigint(int sig) {
    (void)sig;   // suppress unused parameter warning
    write(STDOUT_FILENO, "\nCaught SIGINT\n", 15);  // write is async-safe
}

int main(void) {
    struct sigaction sa = {0};
    sa.sa_handler = handle_sigint;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);

    while (1) { pause(); }   // wait for signal
    return 0;
}
```

Use `sigaction` over the older `signal()` function — it's more portable and predictable.

## Async-signal safety

Signal handlers can interrupt code at any point. Only **async-signal-safe** functions can be called from a handler. `printf` is NOT safe — use `write` instead.

## volatile sig_atomic_t — shared flags

```c
volatile sig_atomic_t running = 1;

void handle_sigint(int sig) {
    (void)sig;
    running = 0;   // safe — sig_atomic_t reads/writes are atomic
}

int main(void) {
    // register handler...
    while (running) {
        // do work
    }
    printf("Graceful shutdown\n");
}
```

`volatile` tells the compiler not to cache `running` in a register — it must re-read it from memory each iteration.

---

## My notes

**What confused me:**

**What clicked:**

**Why volatile is needed here:**

**Things to look up later:**
