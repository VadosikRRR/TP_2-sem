#ifndef __POOL_ALLOCATOR__
#define __POOL_ALLOCATOR__

typedef struct chunk {
    int data;
    struct chunk *p_next;
} chunk;

typedef struct pool_allocator {
    chunk *head;
    chunk *last_chunk;
    chunk *first_free_chunk;
} pool_allocator;

pool_allocator *create_pool(int count_chunk);
chunk *pool_alloc(pool_allocator *pool);
void pool_free(pool_allocator *pool, chunk *free_chank);

#endif
