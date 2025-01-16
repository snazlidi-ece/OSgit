#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd); // Create pipe

    if (fork() == 0) {
        // Child process
        char buffer[20];
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
    } else {
        // Parent process
        write(fd[1], "Hello", 6);
    }

    return 0;
}
