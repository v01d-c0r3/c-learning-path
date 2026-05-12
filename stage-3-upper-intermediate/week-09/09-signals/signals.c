#include <stdio.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t running = 1;

void handle_sigint(int sig) {
    /* TODO: set running = 0 */
    (void)sig;
}

int main(void) {
    /* TODO 1: Register handle_sigint with sigaction */
    /* TODO 2: Loop printing a counter until Ctrl-C  */
    printf("Running — press Ctrl-C to stop\n");
    int count = 0;
    while (running) { printf("\r%d", ++count); fflush(stdout); sleep(1); }
    printf("\nStopped at %d\n", count);
    return 0;
}
