#include "malloc.h"

void insert_in_list(Block* new_block) {
    if (heap_start == NULL) {
        heap_start = new_block;
        return;
    }

    Block* current = heap_start;
    Block* prev = NULL;
    while (current != NULL) {
        if (new_block < current) {
            if (prev != NULL) {
                prev->next = new_block;
            }
            new_block->next = current;
        }
        prev = current;
        current = current->next;
    }
}