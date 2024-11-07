#ifndef MALLOC_H
#define MALLOC_H

#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct Block {
    ssize_t size;
    struct Block *next;
    int free;
} Block;

#define BLOCK_SIZE sizeof(Block)

extern Block *heap_start;

void insert_in_list(Block* new_block);
void *search_heap(Block** prev, size_t size);
void *mymalloc(size_t size);
void *mycalloc(size_t num, size_t size);
void *myrealloc(void *ptr, size_t size);
void myfree(void *ptr);
void cleanup();
void print_heap_structure();

#endif