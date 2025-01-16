#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int sig) {
    printf("Child got signal %d\n", sig);
}

int main() {
    if (fork() == 0) {
        // Child process
        signal(SIGUSR1, signal_handler); // Handle signal
        pause(); // Wait for signal
    } else {
        // Parent process
        sleep(1); // Ensure child is ready
        kill(0, SIGUSR1); // Send signal to child
    }

    return 0;
}
