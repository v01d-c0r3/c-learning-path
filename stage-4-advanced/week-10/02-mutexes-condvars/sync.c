#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define BUF_SIZE 8

int buffer[BUF_SIZE];
int head = 0, tail = 0;
pthread_mutex_t mu = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  not_full  = PTHREAD_COND_INITIALIZER;
pthread_cond_t  not_empty = PTHREAD_COND_INITIALIZER;

void enqueue(int v) { /* TODO */ }
int  dequeue(void)  { /* TODO */ return -1; }

void *producer(void *arg) { /* TODO: enqueue 20 items */ return NULL; }
void *consumer(void *arg) { /* TODO: dequeue 20 items */ return NULL; }

int main(void) {
    pthread_t p, c;
    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);
    pthread_join(p, NULL);
    pthread_join(c, NULL);
    return 0;
}
