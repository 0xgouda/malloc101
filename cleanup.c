#include "malloc.h"

// give back all freed memory
void cleanup() {
    Block *current = heap_start;
    while (current != NULL) {
        if (current->next != NULL && !current->next->free) {
            Block *next = current->next->next;
            munmap(current->next, current->next->size + BLOCK_SIZE);
            current->next = next;
            continue;
        }
        current = current->next;
    }
}