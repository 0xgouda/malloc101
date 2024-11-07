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
            if (next && next->free &&
                current + current->size + BLOCK_SIZE + 1 == next) {

                current->size += BLOCK_SIZE + next->size;
                current->next = next->next;
                continue;
            }
        }
        current = current->next;
    }
}