# Lesson: Mutexes, condition variables & semaphores

## The problem: data races

When two threads read and write shared data concurrently, results are unpredictable:

```c
int counter = 0;
void *inc(void *_) { for (int i=0; i<1000000; i++) counter++; return NULL; }
// Two threads running inc() may give counter < 2000000 — race condition
```

## Mutex — mutual exclusion

A mutex ensures only one thread runs a critical section at a time:

```c
#include <pthread.h>

pthread_mutex_t mu = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

void *inc(void *_) {
    for (int i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&mu);
        counter++;                    // critical section
        pthread_mutex_unlock(&mu);
    }
    return NULL;
}
```

Lock before accessing shared data. Unlock as soon as possible — holding locks too long kills performance.

## Deadlock

Occurs when two threads each hold a lock the other needs:

```c
// Thread A: lock(mu1); lock(mu2);
// Thread B: lock(mu2); lock(mu1);  ← deadlock
```

Prevention: always acquire locks in the same order across all threads.

## Condition variables — wait for a condition

```c
pthread_mutex_t mu   = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  cond = PTHREAD_COND_INITIALIZER;
int ready = 0;

// Consumer
pthread_mutex_lock(&mu);
while (!ready) {
    pthread_cond_wait(&cond, &mu);  // atomically unlocks mu and waits
}
// ... consume ...
pthread_mutex_unlock(&mu);

// Producer
pthread_mutex_lock(&mu);
ready = 1;
pthread_cond_signal(&cond);    // wake one waiter (broadcast wakes all)
pthread_mutex_unlock(&mu);
```

Always use `while` not `if` for the condition check — spurious wakeups are possible.

## Semaphore

A semaphore is a counter. `sem_wait` decrements (blocks at 0). `sem_post` increments:

```c
#include <semaphore.h>

sem_t sem;
sem_init(&sem, 0, 1);   // initial value 1 = binary semaphore (like mutex)
sem_wait(&sem);
// critical section
sem_post(&sem);
sem_destroy(&sem);
```

---

## My notes

**What confused me:**

**What clicked:**

**Mutex vs semaphore — difference in my own words:**

**Things to look up later:**
