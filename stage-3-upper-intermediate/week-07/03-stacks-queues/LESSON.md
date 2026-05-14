# Lesson: Stacks & queues

## Stack — LIFO (Last In, First Out)

Think of a stack of plates. You push onto the top and pop from the top.

Operations: `push`, `pop`, `peek` — all O(1).

```c
#define MAX 256

typedef struct {
    int data[MAX];
    int top;           // index of top element, -1 when empty
} Stack;

void stack_init(Stack *s) { s->top = -1; }
int  stack_empty(Stack *s) { return s->top == -1; }
int  stack_full(Stack *s)  { return s->top == MAX - 1; }

void push(Stack *s, int v) {
    if (stack_full(s)) { fprintf(stderr, "Stack overflow\n"); return; }
    s->data[++s->top] = v;
}

int pop(Stack *s) {
    if (stack_empty(s)) { fprintf(stderr, "Stack underflow\n"); return -1; }
    return s->data[s->top--];
}

int peek(Stack *s) {
    if (stack_empty(s)) return -1;
    return s->data[s->top];
}
```

## Stack use case: balanced brackets

```c
int balanced(const char *expr) {
    Stack s; stack_init(&s);
    for (int i = 0; expr[i]; i++) {
        char c = expr[i];
        if (c=='(' || c=='[' || c=='{') push(&s, c);
        else if (c==')' || c==']' || c=='}') {
            if (stack_empty(&s)) return 0;
            char top = pop(&s);
            if ((c==')' && top!='(') ||
                (c==']' && top!='[') ||
                (c=='}' && top!='{')) return 0;
        }
    }
    return stack_empty(&s);
}
```

## Queue — FIFO (First In, First Out)

Think of a queue at a shop. You enqueue at the back and dequeue from the front.

```c
typedef struct {
    int data[MAX];
    int head, tail, count;
} Queue;

void queue_init(Queue *q) { q->head = q->tail = q->count = 0; }

void enqueue(Queue *q, int v) {
    if (q->count == MAX) return;
    q->data[q->tail] = v;
    q->tail = (q->tail + 1) % MAX;   // wrap around — circular buffer
    q->count++;
}

int dequeue(Queue *q) {
    if (q->count == 0) return -1;
    int v = q->data[q->head];
    q->head = (q->head + 1) % MAX;
    q->count--;
    return v;
}
```

The circular buffer trick avoids shifting elements on every dequeue.

---

## My notes

**What confused me:**

**What clicked:**

**Stack vs queue — when to use which:**

**Things to look up later:**
