#include <stdio.h>
#include <time.h>
#define N 1024

float A[N][N], B[N][N], sum_row, sum_col;

int main(void) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            A[i][j] = B[i][j] = (float)(i*N+j);

    clock_t t0 = clock();
    /* TODO 1: row-major sum of A into sum_row */
    clock_t t1 = clock();
    /* TODO 2: column-major sum of B into sum_col */
    clock_t t2 = clock();

    printf("row: %.3f ms, col: %.3f ms\n",
           1000.0*(t1-t0)/CLOCKS_PER_SEC,
           1000.0*(t2-t1)/CLOCKS_PER_SEC);
    return 0;
}
