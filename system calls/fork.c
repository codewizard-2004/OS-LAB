#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>


int main(){
    pid_t pid = fork();

    if(pid > 0){
        printf("This is the parent process\n");
        printf("Parent Process: %d\n" , getpid());
        printf("Child Process: %d\n" , pid);
    }else if(pid == 0){
        printf("This is a child process\n");
        printf("Child Process: %d\n" , getpid());
        printf("Parent Process: %d\n" , getppid());
    }else{
        perror("fork failed");
        return 1;
    }
    
    return 0;
}