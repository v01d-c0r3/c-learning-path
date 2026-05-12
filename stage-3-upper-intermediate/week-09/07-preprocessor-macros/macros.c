#include <stdio.h>

#define MAX(a, b)  /* TODO: safe max macro */
#define ARRAY_LEN(a) (sizeof(a) / sizeof((a)[0]))

/* TODO: X-macro to define an enum + string table for colours */
#define COLOURS \
    X(RED)      \
    X(GREEN)    \
    X(BLUE)

int main(void) {
    printf("%d\n", MAX(3, 7));
    int arr[] = {1,2,3,4,5};
    printf("len=%zu\n", ARRAY_LEN(arr));
    return 0;
}
