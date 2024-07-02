#include "unity.h"
#include "list.h"


void setUp() {
}


void tearDown() {
}

// [] -> []
void test_simple_1() {
    list list1 = new_list();
    list correct_list = new_list();
    list result_list = find_max_grow_sequence(&list1);
    TEST_ASSERT_TRUE(equal(&result_list, &correct_list));
    delete_list(&list1);
    delete_list(&result_list);
    delete_list(&correct_list);
}


// [1, 2] -> [1, 2]
void test_simple_2() {
    list list1 = designer(2, 1, 2);
    list correct_list = designer(2, 1, 2);
    list result_list = find_max_grow_sequence(&list1);
    TEST_ASSERT_TRUE(equal(&result_list, &correct_list));
    delete_list(&list1);
    delete_list(&result_list);
    delete_list(&correct_list);
}


// [3, 1, 2, 2] -> [1, 2]
void test_simple_3() {
    list list1 = designer(4, 3, 1, 2, 2);
    list correct_list = designer(2, 1, 2);
    list result_list = find_max_grow_sequence(&list1);
    TEST_ASSERT_TRUE(equal(&result_list, &correct_list));
    delete_list(&list1);
    delete_list(&result_list);
    delete_list(&correct_list);
}


// [9, 8, 7, 6, 5, 4, 3, 2, 1] -> [9]
void test_simple_4() {
    list list1 = designer(9, 9, 8, 7, 6, 5, 4, 3, 2, 1);
    list correct_list = designer(1, 9);
    list result_list = find_max_grow_sequence(&list1);
    TEST_ASSERT_TRUE(equal(&result_list, &correct_list));
    delete_list(&list1);
    delete_list(&result_list);
    delete_list(&correct_list);
}


// [1, 1, 1, 1, 1] -> [1]
void test_simple_5() {
    list list1 = designer(5, 1, 1, 1, 1, 1);
    list correct_list = designer(1, 1);
    list result_list = find_max_grow_sequence(&list1);
    TEST_ASSERT_TRUE(equal(&result_list, &correct_list));
    delete_list(&list1);
    delete_list(&result_list);
    delete_list(&correct_list);
}


// [9, -5, 0, 4, 12, 58, 3, 60, 200, 1] -> [-5, 0, 4, 12, 58]
void test_simple_6() {
    list list1 = designer(10, 9, -5, 0, 4, 12, 58, 3, 60, 200, 1);
    list correct_list = designer(5, -5, 0, 4, 12, 58);
    list result_list = find_max_grow_sequence(&list1);
    TEST_ASSERT_TRUE(equal(&result_list, &correct_list));
    delete_list(&list1);
    delete_list(&result_list);
    delete_list(&correct_list);
}


// [9, 1, 2, 3, -5, 6, 1, 2, 3, 0, 5, 1, 2, 3, -4, 7, 1, 2, 3, 4] -> [1, 2, 3, 4]
void test_simple_7() {
    list list1 = designer(20, 9, 1, 2, 3, -5, 6, 1, 2, 3, 0, 5, 1, 2, 3, -4, 7, 1, 2, 3, 4);
    list correct_list = designer(4, 1, 2, 3, 4);
    list result_list = find_max_grow_sequence(&list1);
    TEST_ASSERT_TRUE(equal(&result_list, &correct_list));
    delete_list(&list1);
    delete_list(&result_list);
    delete_list(&correct_list);
}


// [1, 2, 3, 4, -5, -4, -3, -2, -1, -10, 1, 0, 1, 2, 3, 4, 5, 5] -> [0, 1, 2, 3, 4, 5]
void test_simple_8() {
    list list1 = designer(18, 1, 2, 3, 4, -5, -4, -3, -2, -1, -10, 1, 0, 1, 2, 3, 4, 5, 5);
    list correct_list = designer(6, 0, 1, 2, 3, 4, 5);
    list result_list = find_max_grow_sequence(&list1);
    TEST_ASSERT_TRUE(equal(&result_list, &correct_list));
    delete_list(&list1);
    delete_list(&result_list);
    delete_list(&correct_list);
}


// нагрузочный тест
void test_stress() {
    list list1 = designer(1, 100000);
    list correct_list = new_list();
    for (int i = -5000; i < 10000; i++) {
        push_back(i, &list1);
        push_back(i, &correct_list);
    }

    push_back(-10000, &list1);
    list result_list = find_max_grow_sequence(&list1);
    TEST_ASSERT_TRUE(equal(&result_list, &correct_list));
    delete_list(&list1);
    delete_list(&result_list);
    delete_list(&correct_list);
}

// больше последовательностей в одном списке, несколько одинаковых в одном списке
