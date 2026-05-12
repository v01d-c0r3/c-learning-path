#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc < 2) { fprintf(stderr, "usage: %s <file>\n", argv[0]); return 1; }

    /* TODO 1: open the file, fstat to get size */
    /* TODO 2: mmap it read-only                */
    /* TODO 3: count newlines by scanning the mapped region */
    /* TODO 4: munmap + close                   */

    return 0;
}
