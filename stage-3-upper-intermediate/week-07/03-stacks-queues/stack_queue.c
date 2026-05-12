#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

typedef struct { int data[MAX]; int top; } Stack;

void push(Stack *s, int v) { /* TODO */ }
int  pop (Stack *s)         { /* TODO */ return -1; }
int  peek(Stack *s)         { /* TODO */ return -1; }

int balanced(const char *expr) {
    /* TODO: return 1 if brackets/parens/braces are balanced */
    return 0;
}

int main(void) {
    printf("%d\n", balanced("({[]})"));   /* expect 1 */
    printf("%d\n", balanced("({[})"));    /* expect 0 */
    return 0;
}
