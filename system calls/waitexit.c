#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include <stdlib.h>

int main(){

    pid_t pid;
    int status;

    pid = fork();

    if(pid > 0){
        printf("This is the parent process.\n");
        printf("Parent Process ID: %d\n", getpid());

        wait(&status);
    }else if(pid == 0){
        printf("This is the child process\n");
        printf("Child Process ID: %d\n" , getpid());
        sleep(2);
        
        exit(42);
    }else{
        perror("Fork failed");
        return 1;
    }


    return 0;
}