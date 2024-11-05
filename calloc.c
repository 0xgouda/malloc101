#include "malloc.h"

void *mycalloc(size_t num, size_t size) {
    if (size <= 0 || num <= 0 || num > SIZE_MAX / size) return NULL;

    size_t total_size = num * size;
    total_size = (total_size + BLOCK_SIZE - 1) & ~(BLOCK_SIZE - 1);

    void *ptr = mymalloc(total_size);

    if (ptr != NULL) {
        memset(ptr, 0, total_size);
    }

    return ptr;
}