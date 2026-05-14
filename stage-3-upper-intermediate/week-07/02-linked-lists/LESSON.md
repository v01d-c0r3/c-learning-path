# Lesson: Singly & doubly linked lists

## Why linked lists?

Arrays have fixed size and expensive insertion/deletion in the middle. Linked lists grow dynamically and insert/delete in O(1) if you have the node pointer.

## Singly linked list

Each node holds data and a pointer to the next node. The last node points to NULL.

```
[10|→] → [20|→] → [30|NULL]
```

```c
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Create a new node
Node *new_node(int val) {
    Node *n = malloc(sizeof(Node));
    n->data = val;
    n->next = NULL;
    return n;
}

// Insert at front — O(1)
Node *insert_front(Node *head, int val) {
    Node *n = new_node(val);
    n->next = head;
    return n;   // new head
}

// Print all nodes
void print_list(Node *head) {
    for (Node *cur = head; cur != NULL; cur = cur->next) {
        printf("%d → ", cur->data);
    }
    printf("NULL\n");
}
```

## Reverse a singly linked list

Classic interview question. Use three pointers:

```c
Node *reverse(Node *head) {
    Node *prev = NULL;
    Node *cur  = head;
    while (cur != NULL) {
        Node *next = cur->next;   // save next
        cur->next  = prev;        // reverse link
        prev       = cur;         // advance prev
        cur        = next;        // advance cur
    }
    return prev;   // prev is now the new head
}
```

## Doubly linked list

Each node also has a `prev` pointer, enabling backward traversal and O(1) deletion without finding the predecessor:

```c
typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;
```

## Floyd's cycle detection

Detect a loop in a linked list using two pointers — slow moves one step, fast moves two:

```c
int has_cycle(Node *head) {
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return 1;   // cycle detected
    }
    return 0;
}
```

## Freeing a list

```c
void free_list(Node *head) {
    while (head != NULL) {
        Node *next = head->next;
        free(head);
        head = next;
    }
}
```

---

## My notes

**What confused me:**

**What clicked:**

**The reverse algorithm step by step:**

**Things to look up later:**
