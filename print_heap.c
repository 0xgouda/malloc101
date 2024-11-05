#include "malloc.h"
#include "malloc.h"

void print_heap_structure() {
    printf("Heap List Start\n");
    for (Block *current = heap_start;
        current != NULL;
        current = current->next) {

        printf("Address: %p, Size: %li, Free: %i, Next: %p\n",
            current, current->size, current->free, current->next);
    }
    printf("Heap List End\n");
}
