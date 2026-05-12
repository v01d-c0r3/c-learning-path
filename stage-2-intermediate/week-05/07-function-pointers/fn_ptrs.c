#include <stdio.h>
#include <stdlib.h>

int cmp_asc(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

/* TODO 1: Write cmp_desc */
/* TODO 2: Build a dispatch table: "asc"->cmp_asc, "desc"->cmp_desc */
/* TODO 3: Sort an array both ways using qsort + your comparators    */

int main(void) {
    int arr[] = {5, 2, 8, 1, 9, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, n, sizeof(int), cmp_asc);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
