#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void quicksort(int *a, int lo, int hi) { /* TODO */ }
void mergesort(int *a, int lo, int hi) { /* TODO */ }
void heapsort (int *a, int n)          { /* TODO */ }

int main(void) {
    int n = 100000;
    int *a = malloc(n * sizeof(int));
    srand(42);
    for (int i = 0; i < n; i++) a[i] = rand();

    /* TODO: copy, sort each way, print time taken */

    free(a);
    return 0;
}
