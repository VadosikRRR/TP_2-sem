#ifndef __LIST__
#define __LIST__

typedef struct node {
    int value;
    struct node *next;
} node;

typedef struct list {
    int length;
    struct node *p_root;
} list;

list new_list();
list designer(int count, ...);
void push_front(int elem, list *p_list);  // push_front
void push_back(int elem, list *p_list);   // push_back
list find_max_grow_sequence(list *p_list);
void print_list(list *p_list);
int contains(int elem, list *p_list);
int equal(list *p_list1, list *p_list2);  // только для результатов.
void erase(int elem, list *p_list);
void delete_list(list *p_list);
node *get_last_node(list *p_list);

#endif
