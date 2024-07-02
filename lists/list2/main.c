#include "list.h"

int main() {
    list list1 = new_list();
    push_back(2, &list1);
    push_back(1, &list1);
    push_back(5, &list1);
    push_back(6, &list1);
    push_back(6, &list1);
    push_back(7, &list1);
    push_back(1, &list1);
    push_back(2, &list1);
    push_back(3, &list1);
    push_back(4, &list1);
    push_back(-5, &list1);
    push_back(0, &list1);
    push_back(-7, &list1);
    print_list(&list1);
    list list2 = find_max_grow_sequence(&list1);
    print_list(&list2);
    delete_list(&list1);
    delete_list(&list2);
    return 1;
}
