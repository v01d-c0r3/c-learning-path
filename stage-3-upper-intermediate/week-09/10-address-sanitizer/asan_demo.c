#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p = malloc(4 * sizeof(int));
    p[4] = 99;          /* BUG: out-of-bounds write  */
    free(p);
    printf("%d\n", p[0]); /* BUG: use-after-free     */
    free(p);              /* BUG: double-free         */

    /* Compile with:
       gcc -fsanitize=address,undefined -g -o asan_demo asan_demo.c
       ./asan_demo
       Then fix all bugs so ASan reports nothing.                  */
    return 0;
}
