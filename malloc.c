#include "malloc.h"
Block *heap_start = NULL;

void *mymalloc(size_t size) {
    if (size <= 0) return NULL;

    // approximate the size to be multiple of BLOCK_SIZE
    size = (size + BLOCK_SIZE - 1) & ~(BLOCK_SIZE - 1);

    void *search_freed_heap; Block *last_node;
    if ((search_freed_heap = search_heap(&last_node, size)) != NULL) return search_freed_heap;

    // Request more Space from the OS
    size_t total_size = size + BLOCK_SIZE;
    void *ptr = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED) {
        return NULL;
    }

    Block *new_block = (Block *) ptr;
    new_block->size = size;
    new_block->free = 0;
    new_block->next = NULL;

    if (heap_start != NULL) {
        last_node->next = new_block;
    }
    else {
        heap_start = new_block;
    }
    return (void *)((uintptr_t) new_block + BLOCK_SIZE);
}