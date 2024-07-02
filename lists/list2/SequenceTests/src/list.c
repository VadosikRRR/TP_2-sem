#include "list.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

list new_list() {
    list n_list;
    node *p_root = (node *)malloc(sizeof(node));

    p_root->next = NULL;
    n_list.p_root = p_root;
    n_list.length = 0;
    return n_list;
}

list designer(int count, ...) {
    list n_list;
    node *p_root = (node *)malloc(sizeof(node));

    p_root->next = NULL;
    n_list.p_root = p_root;
    n_list.length = 0;

    va_list ap;
    va_start(ap, count);
    for (register int i = 0; i < count; i++) {  // register
        push_back(va_arg(ap, int), &n_list);
    }

    return n_list;
}

void push_front(int elem, list *p_list) {
    node *tmp = (node *)malloc(sizeof(node));
    tmp->value = elem;
    tmp->next = p_list->p_root->next;
    p_list->p_root->next = tmp;
    (p_list->length)++;
}

void push_back(int elem, list *p_list) {
    node *node_data = (node *)malloc(sizeof(node));
    node_data->value = elem;
    node_data->next = NULL;
    node *tmp = get_last_node(p_list);
    tmp->next = node_data;
    (p_list->length)++;
}

node *get_last_node(list *p_list) {
    node *tmp;
    for (tmp = p_list->p_root; tmp->next; tmp = tmp->next) {
    }
    return tmp;
}

void erase(int elem, list *p_list) {
    for (node *tmp = p_list->p_root; tmp->next; tmp = tmp->next) {
        if (tmp->next->value != elem) {
            continue;
        }

        node *tmp_for_delete = tmp->next;
        tmp->next = tmp->next->next;
        free(tmp_for_delete);
        (p_list->length)--;
        break;
    }
}

list find_max_grow_sequence(list *p_list) {
    list max_grow_sequence = new_list();
    if (!p_list->length) {
        return max_grow_sequence;
    }

    node *p_beginning_grow_sequence = NULL;
    node *p_max_beginning_grow_sequence = NULL;

    int length = 0;
    int max_length = 0;

    node *tmp = p_list->p_root;
    tmp = tmp->next;
    p_beginning_grow_sequence = tmp;
    length = 1;

    for (; tmp->next; tmp = tmp->next) {
        if (tmp->value < tmp->next->value) {
            length++;
            if (!tmp->next->next && max_length < length) {
                p_max_beginning_grow_sequence = p_beginning_grow_sequence;
                max_length = length;
            }

            continue;
        }

        if (max_length < length) {
            p_max_beginning_grow_sequence = p_beginning_grow_sequence;
            max_length = length;
        }

        p_beginning_grow_sequence = tmp->next;
        length = 1;
    }

    for (int i = 0; i < max_length;
         i++, p_max_beginning_grow_sequence = p_max_beginning_grow_sequence->next) {
        push_back(p_max_beginning_grow_sequence->value, &max_grow_sequence);
    }

    return max_grow_sequence;
}

void print_list(list *p_list) {
    printf("[");
    
    for (node *tmp = p_list->p_root->next; tmp; tmp = tmp->next) {
        printf("%d", tmp->value);
        if (tmp->next) {
            printf(", ");
        }
    }

    printf("]\n");
}

int equal(list *p_list1, list *p_list2) {
    if (p_list1->length != p_list2->length) {
        return 0;
    }

    for (node *tmp = p_list1->p_root->next; tmp; tmp = tmp->next) {
        if (!contains(tmp->value, p_list2)) {
            return 0;
        }
    }

    return 1;
}

int contains(int elem, list *p_list) {
    for (node *tmp = p_list->p_root->next; tmp; tmp = tmp->next) {
        if (tmp->value == elem) {
            return 1;
        }
    }

    return 0;
}

void delete_list(list *p_list) {
    while (p_list->p_root->next) {
        erase(p_list->p_root->next->value, p_list);
    }

    free(p_list->p_root);
}
