# Lesson: pthreads — thread creation & lifecycle

## What is a thread?

A thread is an independent execution path within a process. Threads share memory (heap, globals) but have their own stack and instruction pointer.

## Creating threads

```c
#include <pthread.h>

void *worker(void *arg) {
    int id = *(int*)arg;   // cast void* back to your type
    printf("Thread %d running\n", id);
    return NULL;           // or return a heap-allocated result
}

int main(void) {
    pthread_t tid;
    int id = 42;
    pthread_create(&tid, NULL, worker, &id);
    // main continues here concurrently with worker
    pthread_join(tid, NULL);   // wait for thread to finish
    return 0;
}
```

**Compile with `-pthread`:**
```bash
gcc -pthread -o out threads.c
```

## pthread_create arguments

```c
pthread_create(
    &tid,     // output: thread ID
    NULL,     // attributes (NULL = defaults)
    worker,   // function to run
    &id       // argument passed to function (must outlive thread)
);
```

## pthread_join vs pthread_detach

```c
pthread_join(tid, &retval);    // block until thread finishes, get return value
pthread_detach(tid);           // don't wait — thread cleans itself up
```

Always either join or detach every thread. A thread that is neither is a resource leak.

## Passing multiple arguments

Wrap in a struct:

```c
typedef struct { int id; char *name; } Args;

void *worker(void *arg) {
    Args *a = (Args*)arg;
    printf("Thread %d: %s\n", a->id, a->name);
    return NULL;
}
```

## Thread-local storage

```c
__thread int counter = 0;   // each thread gets its own copy
```

---

## My notes

**What confused me:**

**What clicked:**

**Things to look up later:**
