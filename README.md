# malloc101
- memory allocator in c, providing basic functionalities
## Description
- Features
  - malloc(), calloc(), realloc(), free() functions are implemented
  - print_heap_structure() function to print the current linked list memory blocks
- Requesting memory
  - uses mmap()/munmap() system calls interact with the OS memory system
  - Memory is only requested from the OS when absolutely necessary, minimizing system calls for efficiency.
- Allocation Tracking
  - all allocated and freed memory segments are tracked through a linked list
  - whenever a call to malloc/realloc/calloc is made the list is searched first for any available memory
  - Free Segments are `Splitted` if they are greater than requested allocations to decrease internal fragmentaion 
- Freeing & Cleaning
  - When a memory block is freed, it is marked as available in the linked list, and adjacent free blocks are merged `Coalesced` to reduce fragmentation.
  - cleanup() is used to return all freed memory segments back to the OS's control using munmap()