#include <stdio.h>

/* This file has intentional bugs — find and fix them all */

int sum_to(int n) {
    int total;           /* BUG: uninitialised */
    for (int i = 1; i <= n; i++)
        total =+ i;      /* BUG: wrong operator */
    return total;
}

int main(void) {
    printf("Sum 1-10 = %d\n", sum_to(10));  /* expected: 55 */
    int arr[5] = {1,2,3,4,5};
    printf("arr[5] = %d\n", arr[5]);         /* BUG: out of bounds */
    return 0;
}
