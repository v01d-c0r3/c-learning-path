#include <stdio.h>
#include "mathutils.h"   /* TODO: create this header */

/* Project structure:
   main.c        — entry point (this file)
   mathutils.h   — declarations for add, subtract, multiply
   mathutils.c   — definitions
   Makefile      — build rules

   TODO 1: Create mathutils.h with proper header guard
   TODO 2: Create mathutils.c with the three function bodies
   TODO 3: Write a Makefile that compiles all .c to .o then links
   TODO 4: Add a clean target that removes *.o and the binary
*/

int main(void) {
    printf("%d\n", add(3, 4));
    printf("%d\n", subtract(10, 3));
    printf("%d\n", multiply(6, 7));
    return 0;
}
