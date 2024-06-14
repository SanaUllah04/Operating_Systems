#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int pfds[2];
    char buf[30];

    if (pipe(pfds) == -1) {
        perror("pipe");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) { // Child process
        close(pfds[1]); // Close the write end of the pipe

        printf("Child process reading from file descriptor #%d\n", pfds[0]);
        read(pfds[0], buf, 5);
        printf("Child process read: %s\n", buf);

        close(pfds[0]); // Close the read end of the pipe
    } else { // Parent process
        close(pfds[0]); // Close the read end of the pipe

        printf("Parent process writing to file descriptor #%d\n", pfds[1]);
        write(pfds[1], "test", 5);

        close(pfds[1]); // Close the write end of the pipe

        wait(NULL); // Wait for the child process to finish
    }

    return 0;
}
