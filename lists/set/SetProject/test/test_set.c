#include "unity.h"
#include "set.h"

static void add_range(int start, int finish, set *p_set);


void setUp() {
}


void tearDown() {
}


// Создать, проверить, что указывает не на NULL и удалить.
void test_create_and_delete() {
    set collection = new_set();
    TEST_ASSERT_NOT_NULL(&collection);
    delete_set(&collection);
}


// Поиск в пустом множестве.
void test_find_elem_in_emply_set() {
    set collection = new_set();
    TEST_ASSERT_EQUAL_INT(0, collection.power);
    TEST_ASSERT_FALSE(contains(1, &collection));
    delete_set(&collection);
}


// {} -> { 1 }
void test_add_1() {
    set collection = new_set();
    TEST_ASSERT_FALSE(contains(1, &collection));
    add(1, &collection);
    TEST_ASSERT_TRUE(contains(1, &collection));
    TEST_ASSERT_EQUAL_INT(1, collection.power);
    delete_set(&collection);
}


// {} -> { 1 }, { 1, -2 }
void test_add_2() {
    set collection = new_set();
    TEST_ASSERT_FALSE(contains(-2, &collection));
    add(1, &collection);
    TEST_ASSERT_FALSE(contains(-2, &collection));
    add(-2, &collection);
    TEST_ASSERT_EQUAL_INT(2, collection.power);
    TEST_ASSERT_TRUE(contains(-2, &collection));
    delete_set(&collection);
}


// {} -> { 1215434 }
void test_add_3() {
    set collection = new_set();
    TEST_ASSERT_FALSE(contains(1215434, &collection));
    add(1215434, &collection);
    TEST_ASSERT_EQUAL_INT(1, collection.power);
    TEST_ASSERT_TRUE(contains(1215434, &collection));
    delete_set(&collection);
}


// {} -> { 1215434 } -> { 1215434, -432634 }
void test_add_4() { // Проверит противоположный тест
    set collection = new_set();
    TEST_ASSERT_FALSE(contains(-432634, &collection));
    add(1215434, &collection);
    TEST_ASSERT_FALSE(contains(-432634, &collection));
    add(-432634, &collection);
    TEST_ASSERT_TRUE(contains(-432634, &collection));
    TEST_ASSERT_TRUE(contains(1215434, &collection));
    delete_set(&collection);
}


// {} -> { -432634 } -> { -432634, 1215434 }
void test_add_5() { 
    set collection = new_set();
    TEST_ASSERT_FALSE(contains(1215434, &collection));
    add(-432634, &collection);
    TEST_ASSERT_FALSE(contains(1215434, &collection));
    add(1215434, &collection);
    TEST_ASSERT_TRUE(contains(-432634, &collection));
    TEST_ASSERT_TRUE(contains(1215434, &collection));
    delete_set(&collection);
}


// тест при подставлении нуля в конструктор
void test_designer_1() {
    set collection = designer(0);
    TEST_ASSERT_EQUAL_INT(0, collection.power);
    delete_set(&collection);
}


// [1, -2] -> { 1, -2 }
void test_designer_2() {
    set collection = designer(2, 1, -2);
    TEST_ASSERT_EQUAL_INT(2, collection.power);
    TEST_ASSERT_TRUE(contains(1, &collection));
    TEST_ASSERT_TRUE(contains(-2, &collection));
    delete_set(&collection);
}


// [1, -2, 100420, -353242, 2321, 51254, 32131] -> { 1, -2, 100420, -353242, 2321, 51254, 32131 }
void test_designer_3() {
    set collection = designer(7, 1, -2, 100420, -353242, 2321, 51254, 32131);
    TEST_ASSERT_EQUAL_INT(7, collection.power);
    TEST_ASSERT_TRUE(contains(1, &collection));
    TEST_ASSERT_TRUE(contains(-2, &collection));
    TEST_ASSERT_TRUE(contains(100420, &collection));
    TEST_ASSERT_TRUE(contains(-353242, &collection));
    TEST_ASSERT_TRUE(contains(2321, &collection));
    TEST_ASSERT_TRUE(contains(51254, &collection));
    TEST_ASSERT_TRUE(contains(32131, &collection));
    delete_set(&collection);
}


// [1, -1, 1, -1, 1, -1, 1, -1] -> { 1, -1 }
void test_designer_4() {
    set collection = designer(8, 1, -1, 1, -1, 1, -1, 1, -1);
    TEST_ASSERT_EQUAL_INT(2, collection.power);
    TEST_ASSERT_TRUE(contains(1, &collection));
    TEST_ASSERT_TRUE(contains(-1, &collection));
    delete_set(&collection);
}


// тест erase на пустом множестве
void test_erase_on_emply_set() {
    set collection = new_set();
    TEST_ASSERT_FALSE(contains(0, &collection));
    erase(0, &collection);
    TEST_ASSERT_EQUAL_INT(0, collection.power);
    TEST_ASSERT_FALSE(contains(0, &collection)); //??
    delete_set(&collection);
}


// { 0 } -> {}
void test_erase_1() {
    set collection = designer(1, 0);
    erase(0, &collection);
    TEST_ASSERT_EQUAL_INT(0, collection.power);
    TEST_ASSERT_FALSE(contains(0, &collection));
    delete_set(&collection);
}


// { 0, 1 } -> { 0 }
void test_erase_2() {
    set collection = designer(1, 0, 1);
    erase(1, &collection);
    TEST_ASSERT_TRUE(contains(0, &collection));
    TEST_ASSERT_FALSE(contains(1, &collection));
    TEST_ASSERT_EQUAL_INT(1, collection.power);
    delete_set(&collection);
}


// { 1 } -> {} -> { 1 } -> {}
void test_erase_3() {
    set collection = designer(1, 1);
    erase(1, &collection);
    add(1, &collection);
    TEST_ASSERT_TRUE(contains(1, &collection));
    TEST_ASSERT_EQUAL_INT(1, collection.power);
    erase(1, &collection);
    TEST_ASSERT_EQUAL_INT(0, collection.power);
    TEST_ASSERT_FALSE(contains(1, &collection));
    delete_set(&collection);
}


// { 1 } -> { 1 }
void test_erase_4() {
    set collection = designer(1, 1);
    erase(2, &collection);
    erase(3, &collection);
    TEST_ASSERT_TRUE(contains(1, &collection));
    TEST_ASSERT_EQUAL_INT(1, collection.power);
    delete_set(&collection);
}


// Нагрузочный тест на функцию add и erase
void test_stress_add_and_erase() {
    set collection = new_set();
    add_range(-10000, 9999, &collection);
    
    TEST_ASSERT_EQUAL_INT(20000, collection.power);
    TEST_ASSERT_FALSE(contains(20000, &collection));
    add(20000, &collection);
    TEST_ASSERT_EQUAL_INT(20001, collection.power);
    TEST_ASSERT_TRUE(contains(20000, &collection));

    for (int i = -10000; i < 10000; i++) {
        erase(i, &collection);
    }

    TEST_ASSERT_EQUAL_INT(1, collection.power);
    TEST_ASSERT_TRUE(contains(20000, &collection));
    erase(20000, &collection);
    TEST_ASSERT_EQUAL_INT(0, collection.power);
    TEST_ASSERT_FALSE(contains(20000, &collection));

    add(20000, &collection);
    TEST_ASSERT_EQUAL_INT(1, collection.power);
    TEST_ASSERT_TRUE(contains(20000, &collection));

    delete_set(&collection);
}


// нагрузочный тест на мощность множества
void test_stress_power() {
    set collection = new_set();
    for (int i = -10000; i < 10000; i++) {
        add(i, &collection);
        TEST_ASSERT_EQUAL_INT(10001 + i, collection.power);
    }
    
    for (int i = 9999; i >= -10000; i--) {
        erase(i, &collection);
        TEST_ASSERT_EQUAL_INT(10000 + i, collection.power);
    }
    
    delete_set(&collection);
}


// {} == {}
void test_equal_1() {
    set set1 = new_set();
    set set2 = new_set();
    TEST_ASSERT_TRUE(equal(&set1, &set2));
    delete_set(&set1);
    delete_set(&set2);
}


// {} != { 1 }
void test_equal_2() {
    set set1 = new_set();
    set set2 = designer(1, 1);
    TEST_ASSERT_FALSE(equal(&set1, &set2));
    delete_set(&set1);
    delete_set(&set2);
}


// { 1, 2, 3 } == { 3, 2, 1}
void test_equal_3() {
    set set1 = designer(3, 1, 2, 3);
    set set2 = designer(3, 3, 2, 1);
    TEST_ASSERT_TRUE(equal(&set1, &set2));
    delete_set(&set1);
    delete_set(&set2);
}


// { 10000, -20000, 30000 } == { -20000, 10000, 30000 } 
void test_equal_4() {
    set set1 = designer(3, 10000, -20000, 30000);
    set set2 = designer(3, -20000, 10000, 30000);
    TEST_ASSERT_TRUE(equal(&set1, &set2));
    delete_set(&set1);
    delete_set(&set2);
}


// { 10000, -20000, 30001 } != { -20000, 10000, 30000 } 
void test_equal_5() {
    set set1 = designer(3, 10000, -20000, 30001);
    set set2 = designer(3, -20000, 10000, 30000);
    TEST_ASSERT_FALSE(equal(&set1, &set2));
    delete_set(&set1);
    delete_set(&set2);
}


// нагрузочный тест для equal
void test_stress_equal() {
    set set1 = new_set();
    set set2 = new_set();
    set set3 = new_set();
    
    for (int i = -10000; i < 10000; i++) {
        add(i, &set1);
        add(i, &set2);
        add(i, &set3);
    }

    erase(0, &set3);
    TEST_ASSERT_FALSE(equal(&set1, &set3));
    TEST_ASSERT_TRUE(equal(&set1, &set2));
    
    delete_set(&set1);
    delete_set(&set2);
    delete_set(&set3);
}


// {} \ {} == {}
void test_difference_1() {
    set set1 = new_set();
    set set2 = new_set();
    set correct_set = new_set();
    set result_set = difference(&set1, &set2);
    TEST_ASSERT_TRUE(equal(&result_set, &correct_set));
    delete_set(&set1);
    delete_set(&set2);
    delete_set(&result_set);
    delete_set(&correct_set);
}


// {} \ { 1 } == {}
void test_difference_2() { // Проверки нет, вообще тсранный тест
    set set1 = new_set();
    set set2 = designer(1, 1);
    set correct_set = new_set();
    set result_set = difference(&set1, &set2);
    TEST_ASSERT_TRUE(equal(&result_set, &correct_set));
    delete_set(&set1);
    delete_set(&set2);
    delete_set(&result_set);
    delete_set(&correct_set);
}


// { 1 } \ {} == { 1 }
void test_difference_3() {
    set set1 = designer(1, 1);
    set set2 = new_set();
    set correct_set = designer(1, 1);
    set result_set = difference(&set1, &set2);
    TEST_ASSERT_TRUE(equal(&result_set, &correct_set));
    delete_set(&set1);
    delete_set(&set2);
    delete_set(&result_set);
    delete_set(&correct_set);
}


// { 1, 2 } \ { 1, 3 } == { 2 }
void test_difference_4() {
    set set1 = designer(2, 1, 2);
    set set2 = designer(2, 1, 3);
    set correct_set = designer(1, 2);
    set result_set = difference(&set1, &set2);
    TEST_ASSERT_TRUE(equal(&result_set, &correct_set));
    delete_set(&set1);
    delete_set(&set2);
    delete_set(&result_set);
    delete_set(&correct_set);
}


// { -2, -5, 6, 7 } \ { 8, -10, 6, -5, 0} == { -2, 7 }
void test_difference_5() {
    set set1 = designer(4, -2, -5, 6, 7);
    set set2 = designer(5, 8, -10, 6, -5, 0);
    set correct_set = designer(2, -2, 7);
    set result_set = difference(&set1, &set2);
    TEST_ASSERT_TRUE(equal(&result_set, &correct_set));
    delete_set(&set1);
    delete_set(&set2);
    delete_set(&result_set);
    delete_set(&correct_set);
}


// { -2, -5, 6, 7 } \ { 8, -10, 6, -5, 0} == { -2, 7 }, смотрим, чтобы страые множества не изменились
void test_difference_6() {
    set set1 = designer(4, -2, -5, 6, 7);
    set set11 = designer(4, -2, -5, 6, 7);
    set set2 = designer(5, 8, -10, 6, -5, 0);
    set set22 = designer(5, 8, -10, 6, -5, 0);
    set result_set = difference(&set1, &set2);
    TEST_ASSERT_TRUE(equal(&set1, &set11));
    TEST_ASSERT_TRUE(equal(&set2, &set22));
    delete_set(&set1);
    delete_set(&set11);
    delete_set(&set2);
    delete_set(&set22);
    delete_set(&result_set);
}


// нагрузочный тест для difference
void test_stress_difference() {
    set set1 = new_set();
    set set2 = new_set();
    set correct_set = designer(1, 20000);
    add_range(-10000, 9999, &set1);
    add_range(-10000, 9999, &set2);

    
    add(20000, &set1);
    set result_set = difference(&set1, &set2);
    TEST_ASSERT_TRUE(equal(&correct_set, &result_set));
    delete_set(&set1);
    delete_set(&set2);
    delete_set(&correct_set);
    delete_set(&result_set);
}


// copy({}) == {}
void test_copy_1() {
    set set1 = new_set();
    set set2 = copy_set(&set1);
    TEST_ASSERT_TRUE(equal(&set1, &set2));
    delete_set(&set1);
    delete_set(&set2);
}


// copy({ 1 }) == { 1 }
void test_copy_2() {
    set set1 = designer(1, 1);
    set set2 = copy_set(&set1);
    TEST_ASSERT_TRUE(equal(&set1, &set2));
    delete_set(&set1);
    delete_set(&set2);
}


// copy({ 1, 6, -2, 29, 0 }) == { 1, 6, -2, 29, 0 }
void test_copy_3() {
    set set1 = designer(5, 1, 6, -2, 29, 0);
    set set2 = copy_set(&set1);
    TEST_ASSERT_TRUE(equal(&set1, &set2));
    delete_set(&set1);
    delete_set(&set2);
}


// тест copy_set на изменение старого множества (не влияет на новое)
void test_copy_4() {
    set set1 = designer(5, 1, 6, -2, 29, 0);
    set set2 = copy_set(&set1);
    add(100, &set1);
    TEST_ASSERT_FALSE(equal(&set1, &set2));
    delete_set(&set1);
    delete_set(&set2);
}


// тест copy_set на изменение нового множества (не влияет на старое)
void test_copy_5() {
    set set1 = designer(5, 1, 6, -2, 29, 0);
    set set2 = copy_set(&set1);
    add(100, &set2);
    TEST_ASSERT_FALSE(equal(&set1, &set2));
    delete_set(&set1);
    delete_set(&set2);
}


// нагрузочный тест для copy_set
void test_stress_copy() {
    set set1 = new_set();
    for (int i = -10000; i < 10000; i++) {
        add(i, &set1);
    }
    
    set set2 = copy_set(&set1);
    TEST_ASSERT_TRUE(equal(&set1, &set2));
    delete_set(&set1);
    delete_set(&set2);
}


// {} U {} == {}
void test_combine_1() {
    set set1 = new_set();
    set set2 = new_set();
    set correct_set = new_set();
    set result_set = combine(&set1, &set2);
    TEST_ASSERT_TRUE(equal(&correct_set, &result_set));
    delete_set(&set1);
    delete_set(&set2);
    delete_set(&correct_set);
    delete_set(&result_set);
}


// { 1 } U { 2 } == { 1, 2 }
void test_combine_2() {
    set set1 = designer(1, 1);
    set set2 = designer(1, 2);
    set correct_set = designer(2, 1, 2);
    set result_set = combine(&set1, &set2);
    TEST_ASSERT_TRUE(equal(&correct_set, &result_set));
    delete_set(&set1);
    delete_set(&set2);
    delete_set(&correct_set);
    delete_set(&result_set);
}


// { 1, 2 } U { 1, 3 } == { 1, 2, 3 }
void test_combine_3() {
    set set1 = designer(2, 1, 2);
    set set2 = designer(2, 1, 3);
    set correct_set = designer(3, 1, 2, 3);
    set result_set = combine(&set1, &set2);
    TEST_ASSERT_TRUE(equal(&correct_set, &result_set));
    delete_set(&set1);
    delete_set(&set2);
    delete_set(&correct_set);
    delete_set(&result_set);
}


// { 1, 2 } U {} == { 1, 2 }
void test_combine_4() {
    set set1 = designer(2, 1, 2);
    set set2 = new_set();
    set correct_set = designer(2, 1, 2);
    set result_set = combine(&set1, &set2);
    TEST_ASSERT_TRUE(equal(&correct_set, &result_set));
    delete_set(&set1);
    delete_set(&set2);
    delete_set(&correct_set);
    delete_set(&result_set);
}


// { 1, 5, -9, 3 } U { 5, 0, 25, -30} == { 1, 5, -9, 3, 0, 25, -30}
void test_combine_5() {
    set set1 = designer(4, 1, 5, -9, 3);
    set set2 = designer(4, 5, 0, 25, -30);
    set correct_set = designer(7, 1, 5, -9, 3, 0, 25, -30);
    set result_set = combine(&set1, &set2);
    TEST_ASSERT_TRUE(equal(&correct_set, &result_set));
    delete_set(&set1);
    delete_set(&set2);
    delete_set(&correct_set);
    delete_set(&result_set);
}


// объеденённые множества при объединении не изменяются
void test_combine_6() {
    set set1 = designer(4, 1, 5, -9, 3);
    set set11 = designer(4, 1, 5, -9, 3);
    set set2 = designer(4, 5, 0, 25, -30);
    set set22 = designer(4, 5, 0, 25, -30);
    set result_set = combine(&set1, &set2);
    TEST_ASSERT_TRUE(equal(&set11, &set1));
    TEST_ASSERT_TRUE(equal(&set22, &set2));
    delete_set(&set1);
    delete_set(&set11);
    delete_set(&set2);
    delete_set(&set22);
    delete_set(&result_set);
}


// нагрузочный тест combine
void test_stress_combine() {
    set set1 = new_set();
    set set2 = new_set();
    set correct_set = new_set();
    set result_set;
    add_range(-10000, 5000, &set1);
    add_range(-5000, 10000, &set2);
    add_range(-10000, 10000, &correct_set);
    result_set = combine(&set1, &set2);
    TEST_ASSERT_TRUE(equal(&correct_set, &result_set));
    delete_set(&set1);
    delete_set(&set2);
    delete_set(&correct_set);
    delete_set(&result_set);
}


// {} intersect {} == {}
void test_intersect_1() {
    set set1 = new_set();
    set set2 = new_set();
    set correct_set = new_set();
    set result_set = intersect(&set1, &set2);
    TEST_ASSERT_TRUE(equal(&result_set, &correct_set));
    delete_set(&set1);
    delete_set(&set2);
    delete_set(&correct_set);
    delete_set(&result_set);
}


// { 1 } intersect { 2 } == {}
void test_intersect_2() {
    set set1 = designer(1, 1);
    set set2 = designer(1, 2);
    set correct_set = new_set();
    set result_set = intersect(&set1, &set2);
    TEST_ASSERT_TRUE(equal(&result_set, &correct_set));
    delete_set(&set1);
    delete_set(&set2);
    delete_set(&correct_set);
    delete_set(&result_set);
}


// { 1, 2 } intersect { 1, 3 } == { 1 }
void test_intersect_3() {
    set set1 = designer(2, 1, 2);
    set set2 = designer(2, 1, 3);
    set correct_set = designer(1, 1);
    set result_set = intersect(&set1, &set2);
    TEST_ASSERT_TRUE(equal(&result_set, &correct_set));
    delete_set(&set1);
    delete_set(&set2);
    delete_set(&correct_set);
    delete_set(&result_set);
}


// { 1, 5, 9, -8, -9 } intersect { 5, -9, 24, -2, 0 } == { 5, -9 }
void test_intersect_4() {
    set set1 = designer(5, 1, 5, 9, -8, -9);
    set set2 = designer(5, 5, -9, 24, -2, 0);
    set correct_set = designer(2, 5, -9);
    set result_set = intersect(&set1, &set2);
    TEST_ASSERT_TRUE(equal(&result_set, &correct_set));
    delete_set(&set1);
    delete_set(&set2);
    delete_set(&correct_set);
    delete_set(&result_set);
}


// пересечание не изменяет старые множества
void test_intersect_5() {
    set set1 = designer(5, 1, 5, 9, -8, -9);
    set set11 = designer(5, 1, 5, 9, -8, -9);
    set set2 = designer(5, 5, -9, 24, -2, 0);
    set set22 = designer(5, 5, -9, 24, -2, 0);
    set result_set = intersect(&set1, &set2);
    TEST_ASSERT_TRUE(equal(&set1, &set11));
    TEST_ASSERT_TRUE(equal(&set2, &set22));
    delete_set(&set1);
    delete_set(&set11);
    delete_set(&set2);
    delete_set(&set22);
    delete_set(&result_set);
}


// нагрузочный тест на intersect
void test_stress_intersect() {
    set set1 = new_set();
    add_range(-10000, 5000, &set1);
    set set2 = new_set();
    add_range(-5000, 10000, &set2);
    set correct_set = new_set();
    add_range(-5000, 5000, &correct_set);
    set result_set = intersect(&set1, &set2);
    TEST_ASSERT_TRUE(equal(&result_set, &correct_set));
    delete_set(&set1);
    delete_set(&set2);
    delete_set(&correct_set);
    delete_set(&result_set);
}


// тесты с большим количеством
// нагрузочный тест
// метод, который принимает n элементов
// конструктор
// метод сравнения


void add_range(int start, int finish, set *p_set) {
    for (int i = start; i <= finish; i++) {
        add(i, p_set);
    }
}
