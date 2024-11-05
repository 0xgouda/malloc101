#include "malloc.h"

void *myrealloc(void *ptr, size_t size) {
    if (ptr == NULL) return mymalloc(size);
    
    if (!size) {
        myfree(ptr);
        return NULL;
    }

    Block *ptr_block = ptr - BLOCK_SIZE;

    void *search_freed_heap; Block *last_node;
    if ((search_freed_heap = search_heap(&last_node, size)) != NULL) return search_freed_heap;

    void *new_ptr = mymalloc(size);

    if (new_ptr != NULL) {
        memcpy(new_ptr, ptr, ptr_block->size < size ? ptr_block->size : size);
    }
    myfree(ptr);

    return new_ptr;
}