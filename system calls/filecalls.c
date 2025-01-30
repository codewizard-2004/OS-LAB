#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    // 1. Using `close()`
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }
    printf("File opened successfully.\n");

    // Close the file using `close()`
    if (close(fd) == -1) {
        perror("Failed to close file");
        return 1;
    }
    printf("File closed successfully.\n");

    // 2. Using `stat()`
    struct stat file_info;
    if (stat("example.txt", &file_info) == -1) {
        perror("Failed to get file status");
        return 1;
    }
    
    printf("\nFile information (using stat):\n");
    printf("File size: %ld bytes\n", file_info.st_size);
    printf("File permissions: %o\n", file_info.st_mode & 0777);  // Get the permissions

    // 3. Using `opendir()` and `readdir()` to read a directory
    DIR *dir = opendir("."); 
    if (dir == NULL) {
        perror("Failed to open directory");
        return 1;
    }

    printf("\nListing directory contents:\n");
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);  // Print the name of each directory entry
    }

    closedir(dir);  // Close the directory stream
    printf("Directory closed successfully.\n");

    return 0;
}
