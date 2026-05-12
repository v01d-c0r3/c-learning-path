#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *dup_string(const char *s) {
    char *copy = malloc(strlen(s) + 1);
    strcpy(copy, s);
    return copy;  /* caller must free */
}

int main(void) {
    char *a = dup_string("hello");
    char *b = dup_string("world");
    printf("%s %s\n", a, b);
    /* TODO: fix the memory leaks so valgrind reports 0 bytes lost */
    return 0;
}
