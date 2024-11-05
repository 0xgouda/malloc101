#include "malloc.h"

// search the Heap List for empty space
void *search_heap(Block** prev, size_t size) {
    Block *current = heap_start;

    while (current != NULL) {
        if (current->free && current->size >= size) {
            // Splitting
            if (current->size > size + BLOCK_SIZE) {
                Block *new_block = (Block *) ((uintptr_t) current + BLOCK_SIZE + size);
                new_block->size = current->size - size - BLOCK_SIZE;
                new_block->next = current->next;
                new_block->free = 1;

                current->size = size;
                current->next = new_block;
            }

            current->free = 0;
            return (void *) ((uintptr_t) current + BLOCK_SIZE);
        }
        *prev = current;
        current = current->next;
    }
    return NULL;
}