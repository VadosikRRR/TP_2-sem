#ifndef __BINARY_TREE__
#define __BINARY_TREE__

#include "pool_allocator.h"

typedef struct tnode {
    char *string_data;
    chunk *data;
    struct tnode *pleft;
    struct tnode *pright;
} tnode;

typedef struct binary_tree {
    tnode *proot;
} binary_tree;

binary_tree *create_binary_tree();
void add_tnode(binary_tree *tree, char *id, chunk *data);
chunk *get_data(binary_tree *tree, char *id);
void delete_node(binary_tree *tree, char *id);
void delete_subtree(tnode *node);

#endif
