#include <stdio.h>
#include <string.h>

void greet(char *name) {
    char buf[16];
    strcpy(buf, name);   /* VULN: no bounds check */
    printf("Hello, ");
    printf(name);        /* VULN: format string   */
    printf("\n");
}

int main(int argc, char **argv) {
    greet(argc > 1 ? argv[1] : "world");
    return 0;
}
/* TODO: fix both vulnerabilities, then compile with hardening flags:
   gcc -fstack-protector-all -D_FORTIFY_SOURCE=2 -pie -fPIE
       -Wl,-z,relro,-z,now -o vuln_demo vuln_demo.c               */
