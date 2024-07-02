#ifndef __SET__
#define __SET__


typedef struct node {
    int value;
    struct node *next;
} node;

typedef struct set {
    int power;
    node *p_root; // Добавить размер структуры
} set;

// Лучше писать названия параметров
set new_set();
set designer(int count, ...);                                       // Сначала указываете количество, а затем перечисляете
int contains(int elem, set *p_set);                                 // Проверяет, существует ли элемент в множестве
void add(int elem, set *p_set);                                     // Добавляет элемент в множество
void print_set(set *p_set);                                         // Выводит всё множество
void erase(int elem, set *p_set);                                   // Удаляет элемент из множества
set combine(set *p_set1, set *p_set2);                             // Объединяет 2 множества
set intersect(set *p_set1, set *p_set2);                           // пересекает 2 множества 
set difference(set *p_minuend_set, set *p_subtrahend_set);         // Вычитает второе множество из первого
set copy_set(set *p_set);                                          // Делает копию множества
void delete_set(set *p_set);                                        // Удаляет множество
int equal(set *p_set1, set *p_set2);                                // Сравнивает 2 множества

#endif