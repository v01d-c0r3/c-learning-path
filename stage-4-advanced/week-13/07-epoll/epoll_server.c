#include <stdio.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 9001
#define MAX_EVENTS 64

/* TODO: implement a single-threaded echo server using epoll that
         handles multiple simultaneous clients                    */

int main(void) {
    return 0;
}
