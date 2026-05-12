/* Compile with: gcc -O2 -flto -o abi_demo abi_demo.c */
#include <stdio.h>

static inline int add(int a, int b) { return a + b; }

int main(void) {
    /* TODO: inspect the assembly output with gcc -S -O2
             note how add() is inlined at -O2 vs -O0     */
    printf("%d\n", add(3, 4));
    return 0;
}
