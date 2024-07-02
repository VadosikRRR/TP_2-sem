#include "include/binary_tree.h"

#include <stdlib.h>

// strcmp
static int compare(char *str1, char *str2) {
    int i = 0;
    for (; str1[i] != '\0'; i++) {
        if (str2[i] == '\0') {
            return 1;
        }
        
        if (str1[i] > str2[i]) {
            return 1;
        }
        else if(str1[i] < str2[i]) {
            return -1;
        }
    }

    if (str2[i] != '\0') {
        return -1;
    }
    
    return 0;
}


binary_tree *create_binary_tree() {
    binary_tree *n_tree = (binary_tree *)malloc(sizeof(binary_tree));
    n_tree->proot = NULL;
    return n_tree;
}


static void add_data(tnode *node, char *id, chunk *data) { // конструктор
    node->data = data;
    node->string_data = id;
    node->pright = NULL;
    node->pleft = NULL;
}


static tnode* choose_node(tnode *node, char *id) { // Переименовать
    int result = compare(id, node->string_data);
    if (result == 1) {
        return node->pright;
    }

    if(result == -1) {
        return node->pleft;
    }

    return NULL;
}


void add_tnode(binary_tree *tree, char *id, chunk *data) {
    if (!tree->proot) {
        tree->proot = (tnode *)malloc(sizeof(tnode));
        add_data(tree->proot, id, data);
        return;
    }
    
    tnode *tmp = tree->proot;
    while (tmp) {
        int result = compare(id, tmp->string_data);
        if (!result) {
            return;
        }
        if (result == 1) {
            if (!tmp->pright) {
                break;
            }

            tmp = tmp->pright;
        }
        else {
            if (!tmp->pleft) {
                break;
            }

            tmp = tmp->pleft;
        } 
    }

    if (!tmp) {
        return;
    }

    if (compare(id, tmp->string_data) == 1) { // if-else (Когда вещи связные, либо тело очень большее)
        tmp->pright = (tnode *)malloc(sizeof(tnode));
        add_data(tmp->pright, id, data);
        return;
    }

    tmp->pleft = (tnode *)malloc(sizeof(tnode));
    add_data(tmp->pleft, id, data);
}


chunk *get_data(binary_tree *tree, char *id) { // поиск нужной ноды по id в отдельную функцию
    tnode *tmp = tree->proot;
    while (tmp && compare(id, tmp->string_data)) {
        tmp = choose_node(tmp, id);
    }
    
    if (!tmp) {
        return NULL;
    }
    
    return tmp->data;
}


void delete_subtree(tnode *node) {
    if (!node) {
        return;
    }
    
    delete_subtree(node->pright);
    delete_subtree(node->pleft);
    free(node);
    node = NULL;
}

/*
void delete_node(binary_tree *tree, char *id) {
    tnode *tmp = tree->proot;
    tnode *tmp_parrent = tree->proot;
    while (tmp && compare(id, tmp->string_data)) {
        tmp_parrent = tmp;
        tmp = choose_node(tmp, id);
    }
    
    if (!tmp) {
        return;
    }

    if (tmp == tmp_parrent) {
        tnode *tmp_3 = tmp->pright;
        if (!tmp_3) {
            tree->proot = tmp->pleft;
            free(tmp);
            return;
        }

        tree->proot = tmp_3;
        while(tmp_3->pleft) {
            tmp_3 = tmp_3->pleft;
        }

        tmp_3->pleft = tmp->pleft;
        free(tmp);
        return;
    }
    

    if (!tmp->pright && !tmp->pleft) {
        if (compare(id, tmp_parrent->string_data) == 1) {
            tmp_parrent->pright = NULL;
        }
        else {
            tmp->pleft = NULL;
        }

        free(tmp);
        return;
    }
    
    tnode *tmp_3 = tmp->pright;
    if (!tmp_3) {
        if (compare(id, tmp_parrent->string_data) == 1) {
            tmp_parrent->pright = tmp->pleft;
        }
        else {
            tmp_parrent->pleft = tmp->pleft;
        }
        
        free(tmp);
        return;
    }
    
    while (tmp_3->pleft) {
        tmp_3 = tmp_3->pleft;
    }
    
    tmp_3->pleft = tmp->pleft;
    free(tmp);
}

*/

static void add_tree(tnode *node, binary_tree *tree) {
    if(!node) {
        return;
    }

    add_tnode(tree, node->string_data, node->data);
    add_tree(node->pright, tree);
    add_tree(node->pleft, tree);
}

void delete_node(binary_tree *tree, char *id) {
    tnode *tmp = tree->proot;
    tnode *tmp_parrent = tree->proot;
    while (tmp && compare(id, tmp->string_data)) {
        tmp_parrent = tmp;
        tmp = choose_node(tmp, id);
    }
    
    if (!tmp) {
        return;
    }

    if (tmp == tree->proot) {
        if (!tmp->pright) {
            tree->proot = tree->proot->pleft;
            free(tmp_parrent);
            return;
        }

        tmp = tmp->pright;
        while(tmp) {
            tmp = tmp->pleft;
        }

        tmp = tree->proot->pleft;
        tree->proot = tree->proot->pright;
        free(tmp_parrent);
    }
    

    if (compare(id, tmp_parrent->string_data) == 1) {
        tmp_parrent->pright = NULL;
    }
    else {
        tmp_parrent->pleft = NULL;
    }
    
    add_tree(tmp->pright, tree);
    add_tree(tmp->pleft, tree);
    delete_subtree(tmp);
}
