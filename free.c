#include "malloc.h"

void myfree(void *ptr) {
    if (ptr == NULL) return;

    Block *block = (Block *) ((uintptr_t) ptr - BLOCK_SIZE);
    block->free = 1;

    Block *current = heap_start;
    // Coalescing
    while (current != NULL) {
        if (current->free) {
            Block *next = current->next;
            if (next && next->free) {
                current->size += BLOCK_SIZE + next->size;
                current->next = next->next;
            }
        }
        current = current->next;
    }
}