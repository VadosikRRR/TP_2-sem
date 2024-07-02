#include "memory.h"
#include "pool_allocator.h"
#include "binary_tree.h"
#include <stdlib.h>
#include <stdio.h>


int MAX_SIZE = 64;
static pool_allocator *pool = NULL;
static binary_tree *tree = NULL;


void put(char *id, int value) {
    if (!pool) {
        pool = create_pool(MAX_SIZE);
        tree = create_binary_tree();
    }
    
    chunk *tmp = get_data(tree, id);
    if (tmp) {
        tmp->data = value;
        return;
    }

    chunk *p_chunk = pool_alloc(pool);
    if (!p_chunk) {
        printf("Memory is full\n");
        return;
    }
    
    p_chunk->data = value;
    p_chunk->p_next = NULL;
    add_tnode(tree, id, p_chunk);
}


void putarr(char *id, int cell, int value) {
    if (!pool) {
        pool = create_pool(MAX_SIZE);
        tree = create_binary_tree();
    }

    chunk *tmp = get_data(tree, id);
    if (tmp) {
        int i = 0;
        for (; i < cell && tmp->p_next; i++) {
            tmp = tmp->p_next;
        }

        if (i == cell) {            
            tmp->data = value;           
            return;
        }

        for (; i < cell; i++) { 
            tmp->p_next = pool_alloc(pool);
            if (!tmp->p_next) {
                printf("Memory is full\n");
                return;
            }
            tmp = tmp->p_next;
        }
        
        tmp->data = value;
        tmp->p_next = NULL;
        return;
    }
    
    chunk *p_chunk = pool_alloc(pool);
    if (!p_chunk) {
        printf("Memory is full\n");
        return;
    }

    add_tnode(tree, id, p_chunk);
    for (int i = 0; i < cell; i++) {
        p_chunk->p_next = pool_alloc(pool);
        if (!p_chunk->p_next) {
        printf("Memory is full\n");
        return;
        }

        p_chunk = p_chunk->p_next;
    }
    
    p_chunk->data = value;
    p_chunk->p_next = NULL;
}


int get(char *id) {
    if (!pool) {
        printf("memory is emply\n");
        return -1;
    }

    chunk *tmp = get_data(tree, id);
    if (!tmp) {
        printf("data has not found\n");
        return -1;
    }

    return tmp->data;
}


int getarr(char *id, int cell) {
    if (!pool) {
        printf("memory is emply\n");
        return -1;
    }

    if (cell < 0) {
        printf("Invalid index\n");
        return -1;
    }
    

    chunk *tmp = get_data(tree, id);
    if (!tmp) {
        printf("data has not found\n");
        return -1;
    }

    for (int i = 0; i < cell; i++) {
        if (!tmp->p_next) {
            printf("Going beyond the boundaries of the array\n");
            printf("The query is the %d index, the length is %d\n", cell, i + 1);
            printf("(max index is %d)\n", i);
            return -1;
        }
        
        tmp = tmp->p_next;
    }

    return tmp->data;
}


void delete(char *id) {
    chunk *tmp = get_data(tree, id);
    if (!tmp) {
        printf("Data`s not found\n");
        return;
    }

    if (tmp->p_next) {
        printf("You are trying to delete an array element.\n");
        printf("If you want to delete the last element of the array, use \"deletearr\"\n");
        printf("If you want to delete the entire array, use\"delete_all_array\"\n");
        printf("IMPORTANT: if the array has a length of 1, you can delete it using delete\n");
        return;
    }
    
    delete_node(tree, id);
    pool_free(pool, tmp);
}


void clear_memory() {
    delete_subtree(tree->proot);
    free(pool->head);
    free(pool);
    free(tree);
    pool = NULL;
    tree = NULL;
}
