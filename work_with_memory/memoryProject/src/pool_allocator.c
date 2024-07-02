#include "pool_allocator.h"

#include <stdlib.h>
#include <stdio.h>


pool_allocator *create_pool(int count_chunk) {
    pool_allocator *n_pool = (pool_allocator *)malloc(sizeof(pool_allocator));
    n_pool->head = (chunk *)malloc(count_chunk * sizeof(chunk));
    n_pool->first_free_chunk = n_pool->head;
    n_pool->last_chunk = n_pool->head + count_chunk - 1;

    for (int i = 0; i < count_chunk - 1; i++) {
        n_pool->head[i].p_next = n_pool->head + i + 1;
        n_pool->head[i].data = 0;
    }
    
    n_pool->head[count_chunk - 1].p_next = NULL;
    return n_pool;
}


chunk *pool_alloc(pool_allocator *pool) {
    if (!pool->first_free_chunk) {
        printf("Out of memory. Please clear the memory\n");
        return NULL;
    }
    
    chunk *tmp = pool->first_free_chunk->p_next;
    pool->first_free_chunk->p_next = tmp->p_next;
    return tmp;
}


void pool_free(pool_allocator *pool, chunk *free_chank) {
    free_chank->p_next = pool->first_free_chunk->p_next;
    free_chank->data = 0;
    pool->first_free_chunk = free_chank;
}
