cmake_minimum_required(VERSION 3.29)
project(malloc101 C)

set(CMAKE_C_STANDARD 23)

add_executable(malloc101 test.c
        cleanup.c
        free.c
        malloc.c
        realloc.c
        print_heap.c
        calloc.c
        search_heap.c
        insert_in_list.c)
