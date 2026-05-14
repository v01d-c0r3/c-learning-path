# Lesson: select/poll/epoll I/O multiplexing

## The problem: handling many connections

A blocking `accept`/`recv` waits for one client. To handle many clients without one thread per client, use I/O multiplexing — get notified when any fd is ready.

## select — portable but limited

```c
fd_set readfds;
FD_ZERO(&readfds);
FD_SET(fd1, &readfds);
FD_SET(fd2, &readfds);

struct timeval tv = {5, 0};  // 5 second timeout
int ready = select(max_fd+1, &readfds, NULL, NULL, &tv);

if (FD_ISSET(fd1, &readfds)) { /* fd1 is readable */ }
```

Limitation: max 1024 fds, rebuilds the set on every call.

## poll — better but still O(n)

```c
struct pollfd fds[MAX];
fds[0].fd = server_fd;
fds[0].events = POLLIN;

int ready = poll(fds, nfds, 5000);  // 5000ms timeout
if (fds[0].revents & POLLIN) { /* readable */ }
```

## epoll — scalable Linux I/O (O(1) per event)

```c
int epfd = epoll_create1(0);

struct epoll_event ev;
ev.events = EPOLLIN;
ev.data.fd = server_fd;
epoll_ctl(epfd, EPOLL_CTL_ADD, server_fd, &ev);  // register fd

struct epoll_event events[MAX_EVENTS];
int n = epoll_wait(epfd, events, MAX_EVENTS, -1); // -1 = block forever

for (int i = 0; i < n; i++) {
    int fd = events[i].data.fd;
    if (fd == server_fd) {
        int client = accept(server_fd, NULL, NULL);
        ev.data.fd = client;
        epoll_ctl(epfd, EPOLL_CTL_ADD, client, &ev);
    } else {
        // handle client data
    }
}
```

epoll only returns the fds that are actually ready — scales to millions of connections.

## Level-triggered vs edge-triggered

- **LT (default):** notified as long as data is available. Safe, easy.
- **ET (`EPOLLET`):** notified only when new data arrives. Must drain the buffer completely. Faster but tricky.

---

## My notes

**What confused me:**

**What clicked:**

**epoll vs select — key differences:**

**Things to look up later:**
