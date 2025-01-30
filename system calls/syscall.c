#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // for fork(), exec(), getpid()
#include <sys/wait.h>  // for wait()

int main() {
    pid_t pid;
    int status;

    pid = fork();  // Create a new process

    if (pid > 0) {  // Parent process
        printf("Parent Process:\n");
        printf("Parent PID: %d\n", getpid());  // Print parent process ID
        printf("Waiting for child process to finish...\n");

        wait(&status);  // Wait for the child to finish
        if (WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        }
        printf("Parent process is done.\n");
    } 
    else if (pid == 0) {  // Child process
        printf("Child Process:\n");
        printf("Child PID: %d\n", getpid());  // Print child process ID

        // Replace the child process with the 'ls' command (list files in current directory)
        execlp("ls", "ls", "-l", NULL);

        // If execlp() fails, exit the child process
        perror("execlp failed");
        exit(1);
    } 
    else {  // fork() failed
        perror("Fork failed");
        return 1;
    }

    return 0;
}
