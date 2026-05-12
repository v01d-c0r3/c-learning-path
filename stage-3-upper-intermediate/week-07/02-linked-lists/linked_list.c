#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *insert_front(Node *head, int val) {
    /* TODO */
    return head;
}

void print_list(Node *head) {
    /* TODO */
}

Node *reverse(Node *head) {
    /* TODO */
    return head;
}

int main(void) {
    Node *list = NULL;
    for (int i = 1; i <= 5; i++) list = insert_front(list, i);
    print_list(list);
    list = reverse(list);
    print_list(list);
    return 0;
}
