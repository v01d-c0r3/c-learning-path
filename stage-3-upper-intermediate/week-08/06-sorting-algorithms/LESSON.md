# Lesson: Quicksort, mergesort & heapsort

## Quicksort — O(n log n) average, O(n²) worst

Pick a pivot, partition array into smaller/larger, recurse on both halves. In-place.

```c
int partition(int *a, int lo, int hi) {
    int pivot = a[hi];   // Lomuto partition scheme
    int i = lo - 1;
    for (int j = lo; j < hi; j++) {
        if (a[j] <= pivot) {
            i++;
            int tmp = a[i]; a[i] = a[j]; a[j] = tmp;  // swap
        }
    }
    int tmp = a[i+1]; a[i+1] = a[hi]; a[hi] = tmp;
    return i + 1;
}

void quicksort(int *a, int lo, int hi) {
    if (lo < hi) {
        int p = partition(a, lo, hi);
        quicksort(a, lo, p - 1);
        quicksort(a, p + 1, hi);
    }
}
```

Fast in practice due to cache locality. Worst case (sorted input) is O(n²) — randomise pivot to avoid.

## Mergesort — O(n log n) guaranteed

Divide in half, sort each half, merge. Requires O(n) auxiliary space.

```c
void merge(int *a, int lo, int mid, int hi) {
    int n = hi - lo + 1;
    int *tmp = malloc(n * sizeof(int));
    int i = lo, j = mid+1, k = 0;
    while (i <= mid && j <= hi)
        tmp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= hi)  tmp[k++] = a[j++];
    for (int x = 0; x < n; x++) a[lo+x] = tmp[x];
    free(tmp);
}

void mergesort(int *a, int lo, int hi) {
    if (lo < hi) {
        int mid = lo + (hi - lo) / 2;   // avoid overflow vs (lo+hi)/2
        mergesort(a, lo, mid);
        mergesort(a, mid+1, hi);
        merge(a, lo, mid, hi);
    }
}
```

Stable sort — equal elements preserve original order. Preferred for linked lists.

## Heapsort — O(n log n), O(1) space

Build a max-heap, repeatedly extract the max:

```c
void heapify(int *a, int n, int i) {   // sift down from index i
    int largest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) {
        int tmp = a[i]; a[i] = a[largest]; a[largest] = tmp;
        heapify(a, n, largest);
    }
}

void heapsort(int *a, int n) {
    for (int i = n/2-1; i >= 0; i--) heapify(a, n, i);  // build heap
    for (int i = n-1; i > 0; i--) {
        int tmp = a[0]; a[0] = a[i]; a[i] = tmp;   // move max to end
        heapify(a, i, 0);
    }
}
```

## Comparison

| Algorithm | Best | Average | Worst | Space | Stable |
|-----------|------|---------|-------|-------|--------|
| Quicksort | O(n log n) | O(n log n) | O(n²) | O(log n) | No |
| Mergesort | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes |
| Heapsort  | O(n log n) | O(n log n) | O(n log n) | O(1) | No |

---

## My notes

**What confused me:**

**What clicked:**

**When to pick which sort:**

**Things to look up later:**
