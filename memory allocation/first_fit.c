#include<stdio.h>

//Initialize the blocks and processes
//initialize the allocation array
// create a nested for loop in which select i as process and find the first block that fits in
// decrease the memory size from the allocated block

void firstFit(int process[] , int m , int blocks[] , int n){
    //Allocation array:
    int allocation[n];
    //set valkues of allocation as -1
    for (int i = 0; i<n; i++){
        allocation[i] = -1;
    }
    //try to allocate the blocks
    // i is the process and j is the block
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            if (process[i] <= blocks[j]){
                allocation[i] = j;
                blocks[j] -= process[i];
                break;
            }
        }
    }
    //printing the allocation block
    printf("Block no.\tProcess Size\tBlock SIze\n");
    for (int i = 0; i<n; i++){
        if(allocation[i] != -1){
            printf("%d\t\t%d\t\t%d\n", i+1 , process[i] , allocation[i]+1);
        }
        else{
            printf("%d\t\t%d\t\tNot allocated",i+1 , process[i]);
        }
    }
}

int main(){

    int process[] = {212 , 315 , 125 , 1270};
    int blocks[] = {200 , 300 , 400 , 500};

    int m = sizeof(process)/sizeof(process[0]);
    int n = sizeof(blocks)/sizeof(blocks[0]);

    firstFit(process , m , blocks , n);

    return 0;
}