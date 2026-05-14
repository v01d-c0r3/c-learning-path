# Lesson: TCP/UDP socket programming

## The socket model

A socket is a file descriptor for network I/O. TCP is reliable and ordered. UDP is fast but unreliable.

## TCP server

```c
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int server_fd = socket(AF_INET, SOCK_STREAM, 0);  // TCP socket

// Reuse address — avoids "address already in use" on restart
int opt = 1;
setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

struct sockaddr_in addr = {
    .sin_family = AF_INET,
    .sin_addr.s_addr = INADDR_ANY,
    .sin_port = htons(9000)    // htons: host byte order to network byte order
};
bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));
listen(server_fd, 10);    // backlog of 10 pending connections

int client_fd = accept(server_fd, NULL, NULL);   // blocks until client connects

char buf[1024];
ssize_t n = recv(client_fd, buf, sizeof(buf), 0);
send(client_fd, buf, n, 0);   // echo back

close(client_fd);
close(server_fd);
```

## TCP client

```c
int fd = socket(AF_INET, SOCK_STREAM, 0);

struct sockaddr_in addr = {
    .sin_family = AF_INET,
    .sin_port = htons(9000)
};
inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

connect(fd, (struct sockaddr*)&addr, sizeof(addr));
send(fd, "hello", 5, 0);

char buf[1024];
recv(fd, buf, sizeof(buf), 0);
close(fd);
```

## Handling partial reads/writes

`send` and `recv` may transfer less than requested. Always loop:

```c
ssize_t send_all(int fd, const void *buf, size_t len) {
    size_t sent = 0;
    while (sent < len) {
        ssize_t n = send(fd, (char*)buf + sent, len - sent, 0);
        if (n <= 0) return n;
        sent += n;
    }
    return sent;
}
```

---

## My notes

**What confused me:**

**What clicked:**

**The server lifecycle (socket→bind→listen→accept) in my own words:**

**Things to look up later:**
