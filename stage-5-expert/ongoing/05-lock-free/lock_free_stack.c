#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>

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

int pop(Stack *s, int *out) {
    /* TODO: CAS-based pop, handle ABA with version tag */
    return 0;
}

int main(void) {
    Stack s = {0};
    for (int i = 0; i < 5; i++) push(&s, i);
    int v;
    while (pop(&s, &v)) printf("%d ", v);
    printf("\n");
    return 0;
}
