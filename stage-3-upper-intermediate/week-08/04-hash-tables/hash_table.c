#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 16

typedef struct Entry { char *key; int value; struct Entry *next; } Entry;
typedef struct { Entry **buckets; int size; int count; } HashMap;

unsigned int hash(const char *key, int size) {
    /* TODO: djb2 or FNV-1a */
    return 0;
}

void hm_put(HashMap *m, const char *key, int value) { /* TODO */ }
int  hm_get(HashMap *m, const char *key, int *out)   { /* TODO */ return 0; }

int main(void) {
    HashMap m = {0};
    m.size = INITIAL_SIZE;
    m.buckets = calloc(INITIAL_SIZE, sizeof(Entry*));

    hm_put(&m, "alice", 90);
    hm_put(&m, "bob",   85);

    int v;
    if (hm_get(&m, "alice", &v)) printf("alice: %d\n", v);

    return 0;
}
