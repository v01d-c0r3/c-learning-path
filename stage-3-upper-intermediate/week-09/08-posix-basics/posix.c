#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(void) {
    /* TODO 1: Open a file with open(), write "hello\n", close() */
    /* TODO 2: fork() and print "child" / "parent" in each process */
    /* TODO 3: In child, execl("/bin/ls", "ls", "-l", NULL)        */
    /* TODO 4: Parent waits with wait() and prints child exit code  */
    return 0;
}
