#include "lib/set.h"


int main() {
    set set1 = designer(4, 1, 2, 3, 4);
    set set2 = new_set();
    add(4, &set2);
    add(5, &set2);
    add(6, &set2);
    print_set(&set1);
    print_set(&set2);
    delete_set(&set1);
    delete_set(&set2);
    return 0;
}
