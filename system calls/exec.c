#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>


int main() {
    pid_t pid = fork();  // Create a new process

    if (pid > 0) {  // Parent process
        printf("This is the parent process. My PID is: %d\n", getpid());
    } else if (pid == 0) {  // Child process
        printf("This is the child process. My PID is: %d\n", getpid());

        // Replace the child process with the 'ls' command
        execlp("ls", "ls", "-l", NULL);  // Lists files in the current directory
        // If execlp fails, this line will be executed
        perror("execlp failed");
        return 1;
    } else {  // fork failed
        perror("Fork failed");
        return 1;
    }

    return 0;
}
