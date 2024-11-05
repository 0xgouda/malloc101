#include "malloc.h"

void test1() {
    int *array1 = mymalloc(10);
    int *array2 = mymalloc(12);
    int *array3 = mymalloc(5);
    print_heap_structure();

    myfree(array1);
    myfree(array2);
    print_heap_structure();
    myfree(array3);

    cleanup();
}

void test2() {
    int *array1 = mymalloc(10);
    array1 = myrealloc(array1, 120);
    print_heap_structure();

    myfree(array1);
    print_heap_structure();

    cleanup();
}

void test3() {
    int *array1 = mycalloc(10, 5);
    print_heap_structure();

    array1 = myrealloc(array1, 120);
    print_heap_structure();

    myfree(array1);
    print_heap_structure();

    cleanup();
}

int main(void) {
    // test1();
    // test2();
    test3();
}


