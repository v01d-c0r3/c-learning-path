#include <stdio.h>
#include <stdatomic.h>
#include <pthread.h>

#define THREADS  8
#define OPS     100000

atomic_int counter = 0;

void *inc(void *arg) {
    for (int i = 0; i < OPS; i++)
        atomic_fetch_add_explicit(&counter, 1, memory_order_relaxed);
    return NULL;
}

int main(void) {
    pthread_t tids[THREADS];
    for (int i = 0; i < THREADS; i++) pthread_create(&tids[i], NULL, inc, NULL);
    for (int i = 0; i < THREADS; i++) pthread_join(tids[i], NULL);
    printf("counter = %d (expected %d)\n", counter, THREADS * OPS);
    return 0;
}
