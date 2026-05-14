# Lesson: Binary search trees

## BST property

For every node: all values in the left subtree are smaller, all values in the right subtree are larger.

```
        5
       / \
      3   7
     / \ / \
    1  4 6  8
```

## Insert

```c
BST *insert(BST *root, int val) {
    if (root == NULL) {
        BST *n = malloc(sizeof(BST));
        n->val = val; n->left = n->right = NULL;
        return n;
    }
    if (val < root->val) root->left  = insert(root->left,  val);
    else if (val > root->val) root->right = insert(root->right, val);
    // duplicate: do nothing
    return root;
}
```

## Traversals

```c
void inorder(BST *root) {   // left → root → right — gives sorted output
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

void preorder(BST *root) {  // root → left → right — useful for copying tree
    if (!root) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

void postorder(BST *root) { // left → right → root — useful for freeing tree
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
    free(root);  // safe here — children already processed
}
```

## Delete — three cases

1. **No children** — just free the node
2. **One child** — replace node with its child
3. **Two children** — replace with in-order successor (smallest node in right subtree), then delete the successor

## Time complexity

| Operation | Average | Worst (unbalanced) |
|-----------|---------|-------------------|
| Insert | O(log n) | O(n) |
| Search | O(log n) | O(n) |
| Delete | O(log n) | O(n) |

A degenerate BST (inserting sorted data) becomes a linked list. Balanced BSTs (AVL, Red-Black) guarantee O(log n).

---

## My notes

**What confused me:**

**What clicked:**

**The three traversals and when to use each:**

**Things to look up later:**
