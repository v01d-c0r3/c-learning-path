# Lesson: Hash tables

## The core idea

A hash table maps keys to values in O(1) average time. It uses a hash function to convert a key into an array index.

```
key "alice"  →  hash()  →  index 3  →  arr[3] = {key:"alice", value:90}
```

## Hash function

A good hash function distributes keys evenly. djb2 is simple and effective for strings:

```c
unsigned int hash(const char *key, int size) {
    unsigned int h = 5381;
    while (*key) {
        h = ((h << 5) + h) + (unsigned char)*key;   // h * 33 + c
        key++;
    }
    return h % size;
}
```

## Collision handling — separate chaining

Two keys can hash to the same index (collision). Chaining stores a linked list at each bucket:

```
bucket[3] → ["alice":90] → ["charlie":85] → NULL
```

```c
typedef struct Entry {
    char *key;
    int   value;
    struct Entry *next;
} Entry;

typedef struct {
    Entry **buckets;
    int    size;
} HashMap;
```

## Collision handling — open addressing

Instead of a linked list, find the next empty slot:

```c
// Linear probing: try index+1, index+2, ...
int probe(HashMap *m, const char *key) {
    int idx = hash(key, m->size);
    while (m->slots[idx].used && strcmp(m->slots[idx].key, key) != 0) {
        idx = (idx + 1) % m->size;   // wrap around
    }
    return idx;
}
```

## Load factor & resizing

Load factor = items / buckets. When it exceeds ~0.75, performance degrades and you must resize (double the bucket array and rehash everything).

## Time complexity

| Operation | Average | Worst case |
|-----------|---------|------------|
| Insert | O(1) | O(n) |
| Lookup | O(1) | O(n) |
| Delete | O(1) | O(n) |

Worst case is all keys colliding into one bucket.

---

## My notes

**What confused me:**

**What clicked:**

**Chaining vs open addressing tradeoffs:**

**Things to look up later:**
