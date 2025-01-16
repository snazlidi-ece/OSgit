#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("pids.txt", O_CREAT | O_WRONLY | O_APPEND, 0644); // Open file for writing

    if (fd == -1) {
        perror("File open failed");
        return 1;
    }

    pid_t pid = fork(); // Create a child process

    if (pid == -1) {
        perror("fork failed");
        return 1;
    } else {
        char buffer[64];
        int len = snprintf(buffer, sizeof(buffer), "PID: %d\n", getpid());
        write(fd, buffer, len); // Write the PID to the file
    }

    close(fd); // Close the file
    return 0;
}
