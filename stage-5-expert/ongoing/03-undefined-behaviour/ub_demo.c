#include <stdio.h>
#include <stdint.h>

int main(void) {
    /* UB 1: signed overflow */
    int x = 2147483647;
    printf("%d\n", x + 1);        /* UB */

    /* UB 2: strict aliasing */
    float f = 3.14f;
    int  *p = (int *)&f;           /* UB — use memcpy instead */
    printf("%x\n", *p);

    /* UB 3: shift past width */
    unsigned u = 1u << 32;         /* UB on 32-bit int */
    printf("%u\n", u);

    /* Compile: gcc -fsanitize=undefined -g -o ub_demo ub_demo.c
       Fix every UB so UBSan reports nothing.                    */
    return 0;
}
