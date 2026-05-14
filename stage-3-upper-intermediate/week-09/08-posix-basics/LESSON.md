# Lesson: POSIX basics — open/read/write, fork/exec/wait

## POSIX file descriptors vs FILE*

C has two I/O APIs:
- **stdio** (`FILE*`, `fopen`, `fread`) — buffered, portable, easier
- **POSIX** (`int fd`, `open`, `read`) — unbuffered, Linux/Unix only, lower level

```c
#include <fcntl.h>
#include <unistd.h>

int fd = open("file.txt", O_RDONLY);         // read only
int fd = open("file.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644);  // write, create

ssize_t n = read(fd, buf, sizeof(buf));      // returns bytes read
ssize_t n = write(fd, buf, len);             // returns bytes written
close(fd);
```

File descriptor numbers: 0=stdin, 1=stdout, 2=stderr. `open` returns the next available number (3, 4, ...).

## fork — create a child process

```c
#include <unistd.h>
#include <sys/wait.h>

pid_t pid = fork();

if (pid < 0) {
    perror("fork");
} else if (pid == 0) {
    // CHILD process — pid == 0
    printf("I am the child, PID=%d\n", getpid());
    exit(0);
} else {
    // PARENT process — pid = child's PID
    printf("I am the parent, child PID=%d\n", pid);
    int status;
    wait(&status);   // wait for child to finish
    printf("Child exited with %d\n", WEXITSTATUS(status));
}
```

`fork` duplicates the process. Both parent and child continue from the `fork` call. Only the return value differs.

## exec — replace process image

```c
execl("/bin/ls", "ls", "-l", "/tmp", NULL);
// if exec succeeds, this line is never reached
perror("execl");   // only reached on error
```

`exec` replaces the current process with a new program. The PID stays the same. Combine with `fork` to run a subprocess:

```c
pid_t pid = fork();
if (pid == 0) {
    execl("/bin/ls", "ls", "-l", NULL);
    exit(1);   // only if exec fails
}
wait(NULL);
```

---

## My notes

**What confused me:**

**What clicked:**

**fork/exec in my own words:**

**Things to look up later:**
