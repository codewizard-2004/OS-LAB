#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  // For INT_MAX and INT_MIN

struct Block {
    int size;
    int allocation;
    struct Block* link;
};

struct Block* create_block(int size) {
    struct Block* new = (struct Block*)malloc(sizeof(struct Block));
    new->size = size;
    new->allocation = 0;
    new->link = NULL;
    return new;
}

// First Fit strategy
void firstFit(struct Block* head, int process[], int n) {
    for (int i = 0; i < n; i++) {
        struct Block* ptr = head;

        while (ptr != NULL) {
            if (ptr->size >= process[i] && ptr->allocation == 0) {
                ptr->allocation = process[i];
                printf("Process %d of size %d allocated to Block of size %d\n", i + 1, process[i], ptr->size);

                int remainingSize = ptr->size - process[i];
                if (remainingSize > 0) {
                    struct Block* newBlock = create_block(remainingSize);
                    newBlock->link = ptr->link;
                    ptr->size = process[i];
                    ptr->link = newBlock;
                }
                break;
            }
            ptr = ptr->link;
        }
    }
}

// Best Fit strategy
void bestFit(struct Block* head, int process[], int n) {
    for (int i = 0; i < n; i++) {
        struct Block* ptr = head;
        struct Block* bestBlock = NULL;
        int minRemainingSpace = INT_MAX;

        while (ptr != NULL) {
            if (ptr->size >= process[i] && ptr->allocation == 0) {
                int remainingSpace = ptr->size - process[i];
                if (remainingSpace < minRemainingSpace) {
                    minRemainingSpace = remainingSpace;
                    bestBlock = ptr;
                }
            }
            ptr = ptr->link;
        }

        if (bestBlock != NULL) {
            bestBlock->allocation = process[i];
            printf("Process %d of size %d allocated to Block of size %d\n", i + 1, process[i], bestBlock->size);

            int remainingSize = bestBlock->size - process[i];
            if (remainingSize > 0) {
                struct Block* newBlock = create_block(remainingSize);
                newBlock->link = bestBlock->link;
                bestBlock->size = process[i];
                bestBlock->link = newBlock;
            }
        } else {
            printf("Process %d of size %d could not be allocated.\n", i + 1, process[i]);
        }
    }
}

// Worst Fit strategy
void worstFit(struct Block* head, int process[], int n) {
    for (int i = 0; i < n; i++) {
        struct Block* ptr = head;
        struct Block* worstBlock = NULL;
        int maxRemainingSpace = INT_MIN;

        while (ptr != NULL) {
            if (ptr->size >= process[i] && ptr->allocation == 0) {
                int remainingSpace = ptr->size - process[i];
                if (remainingSpace > maxRemainingSpace) {
                    maxRemainingSpace = remainingSpace;
                    worstBlock = ptr;
                }
            }
            ptr = ptr->link;
        }

        if (worstBlock != NULL) {
            worstBlock->allocation = process[i];
            printf("Process %d of size %d allocated to Block of size %d\n", i + 1, process[i], worstBlock->size);

            int remainingSize = worstBlock->size - process[i];
            if (remainingSize > 0) {
                struct Block* newBlock = create_block(remainingSize);
                newBlock->link = worstBlock->link;
                worstBlock->size = process[i];
                worstBlock->link = newBlock;
            }
        } else {
            printf("Process %d of size %d could not be allocated.\n", i + 1, process[i]);
        }
    }
}

void printMemory(struct Block* head) {
    struct Block* current = head;
    printf("\nMemory Block Status:\n");
    printf("| %-15s | %-10s | %-10s |\n", "Block Size", "Allocated", "Remaining");
    printf("|-----------------|------------|------------|\n");

    while (current != NULL) {
        printf("| %-15d | %-10d | %-10d |\n", current->size, current->allocation, current->size - current->allocation);
        current = current->link;
    }
    printf("|-----------------|------------|------------|\n");
}

int main() {
    // Create a list of memory blocks
    struct Block* head = create_block(100);  // Block of size 100
    head->link = create_block(50);           // Block of size 50
    head->link->link = create_block(200);    // Block of size 200
    head->link->link->link = create_block(150); // Block of size 150

    int process[] = {30, 60, 100, 40};  // Processes with their sizes
    int n = sizeof(process) / sizeof(process[0]);

    printf("\nFirst Fit Allocation:\n");
    firstFit(head, process, n);
    printMemory(head);

    // Reset the memory blocks for the next allocation strategy
    head = create_block(100);
    head->link = create_block(50);
    head->link->link = create_block(200);
    head->link->link->link = create_block(150);

    printf("\nBest Fit Allocation:\n");
    bestFit(head, process, n);
    printMemory(head);

    // Reset the memory blocks again for Worst Fit
    head = create_block(100);
    head->link = create_block(50);
    head->link->link = create_block(200);
    head->link->link->link = create_block(150);

    printf("\nWorst Fit Allocation:\n");
    worstFit(head, process, n);
    printMemory(head);

    return 0;
}
