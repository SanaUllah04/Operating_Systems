#include <unistd.h>
#include <stdio.h>

int main() {
    char *args[] = {"ls", "-l", NULL};
    char *env[] = {NULL};

    printf("Before Running Exec syscall\n");

    execve("/bin/ls", args, env);

    // This line will not be reached if execve is successful
    perror("execve"); // execve returns only on failure
    return 1;
}
