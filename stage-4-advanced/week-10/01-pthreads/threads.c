#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4

void *worker(void *arg) {
    /* TODO: print thread id and arg, return NULL */
    return NULL;
}

int main(void) {
    pthread_t tids[NUM_THREADS];
    /* TODO: spawn NUM_THREADS threads, join them all */
    return 0;
}
