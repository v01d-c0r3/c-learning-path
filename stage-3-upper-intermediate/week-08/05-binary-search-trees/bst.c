#include <stdio.h>
#include <stdlib.h>

typedef struct BST { int val; struct BST *left, *right; } BST;

BST *insert(BST *root, int val) { /* TODO */ return root; }
BST *search(BST *root, int val) { /* TODO */ return NULL; }
BST *delete(BST *root, int val) { /* TODO */ return root; }
void inorder(BST *root)          { /* TODO */ }

int main(void) {
    BST *root = NULL;
    int vals[] = {5,3,7,1,4,6,8};
    for (int i = 0; i < 7; i++) root = insert(root, vals[i]);
    inorder(root); printf("\n");   /* expect: 1 3 4 5 6 7 8 */
    return 0;
}
