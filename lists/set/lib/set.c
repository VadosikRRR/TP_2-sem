#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "set.h"

static void add_range(node *p_beginner_pointer, set *p_set); // добавит в множество набор элементов (insert_range, add_range)
static void erase_range(node *p_beginner_pointer, set *p_set);


set new_set() { // тут нет смысла в передаче адреса и соответвенно ипользовать динамическую память
    set n_set;
    node *p_root = (node *)malloc(sizeof(node));
    p_root->next = NULL;
    n_set.p_root = p_root;
    n_set.power = 0;
    return n_set;
}


set designer(int count, ...) {
    set n_set;
    node *p_root = (node *)malloc(sizeof(node));
    p_root->next = NULL;
    n_set.p_root = p_root;
    n_set.power = 0;
    va_list ap;
    va_start(ap, count);
    for (register int i = 0; i < count; i++) {
        add(va_arg(ap, int), &n_set);
    }
    
    return n_set;
}


int contains(int elem, set *p_set) { // colection (на будущее)
    for (node *tmp = p_set->p_root->next; tmp; tmp = tmp->next) {
        if (tmp->value == elem) {
            return 1;
        }
    }

    return 0;
}


void add(int elem, set *p_set) {
    if (contains(elem, p_set)) {
        return;
    }
    
    node *tmp = (node *)malloc(sizeof(node));
    tmp->value = elem;
    tmp->next = p_set->p_root->next;
    p_set->p_root->next = tmp;
    (p_set->power)++;
}


void erase(int elem, set *p_set) { // но следующий элемент, root - элемент, который не содержит элемент
    for (node *tmp = p_set->p_root; tmp->next; tmp = tmp->next) {
        if (tmp->next->value != elem) {
            continue;
        }
        
        node *tmp_for_delete = tmp->next;
        tmp->next = tmp->next->next;
        free(tmp_for_delete);
        (p_set->power)--;
        break;
    }
}


void print_set(set *p_set) { // Запятые + скобочки
    printf("{ ");
    for (node *tmp = p_set->p_root->next; tmp; tmp = tmp->next) {
        printf("%d", tmp->value);
        if (tmp->next) {
            printf(", ");
        }
        
    }
    
    printf(" }, power set is %d\n", p_set->power);
}


set combine(set *p_set1, set *p_set2) { // union занято
    set result_set = new_set();
    node *tmp = p_set1->p_root->next;
    add_range(tmp, &result_set);
    tmp = p_set2->p_root->next;
    add_range(tmp, &result_set);
    return result_set;
};


set intersect(set *p_set1, set *p_set2) {
    set result_set = new_set();
    for (node *tmp1 = p_set1->p_root->next; tmp1; tmp1 = tmp1->next) {
        for (node *tmp2 = p_set2->p_root->next; tmp2; tmp2 = tmp2->next) {
            if (tmp1->value != tmp2->value) {
                continue;
            }
            
            add(tmp1->value, &result_set);
            break;
        }
    }
    
    return result_set;
}


set difference(set *p_minuend_set, set *p_subtrahend_set) {
    set result_set = copy_set(p_minuend_set);
    node *tmp = p_subtrahend_set->p_root->next;
    erase_range(tmp, &result_set);
    return result_set;
}


set copy_set(set *p_set) { // for better
    set result_set = new_set();
    for (node *tmp = p_set->p_root->next; tmp; tmp = tmp->next) {
        add(tmp->value, &result_set);
    }
    
    return result_set;
}


int equal(set *p_set1, set *p_set2) {
    if (p_set1->power != p_set2->power) {
        return 0;
    }

    for (node *tmp = p_set1->p_root->next; tmp; tmp = tmp->next) {
        if (!contains(tmp->value, p_set2)) {
            return 0;
        } 
    }
    
    return 1;
}


void delete_set(set *p_set) {
    while(p_set->p_root->next) {
        erase(p_set->p_root->next->value, p_set); // ()()()()()()
    }

    free(p_set->p_root);
}


static void add_range(node *tmp, set *p_set) {
    while (tmp) {
        add(tmp->value, p_set);
        tmp = tmp->next;
    }
}


static void erase_range(node *tmp, set *p_set) {
    while (tmp) {
        erase(tmp->value, p_set);
        tmp = tmp->next;
    }
}
