#include "unity.h"
#include "memory.h"
#include "pool_allocator.h"
#include "binary_tree.h"
#define MAXSIZE 1024

void setUp() {
}


void tearDown() {
}


void test_create_and_delete() {
    put("x", 10);
    clear_memory();
}


void test_put_and_get_1() {
    put("value", 10);
    TEST_ASSERT_EQUAL_INT(10, get("value"));
    clear_memory();
}


void test_put_and_get_2() {
    put("value", 10);
    TEST_ASSERT_EQUAL_INT(10, get("value"));
    put("a", 0);
    TEST_ASSERT_EQUAL_INT(0, get("a"));
    TEST_ASSERT_EQUAL_INT(10, get("value"));
    clear_memory();
}


void test_put_and_get_3() {
    put("value", 10);
    TEST_ASSERT_EQUAL_INT(10, get("value"));
    put("value", 3);
    TEST_ASSERT_EQUAL_INT(3, get("value"));
    clear_memory();
}


void test_put_and_get_4() {
    put("1", 11);
    TEST_ASSERT_EQUAL_INT(11, get("1"));
    put("2", 22);
    TEST_ASSERT_EQUAL_INT(22, get("2"));
    put("-1", -11);
    TEST_ASSERT_EQUAL_INT(-11, get("-1"));
    put("-2", -22);
    TEST_ASSERT_EQUAL_INT(-22, get("-2"));
    clear_memory();
}


void test_put_and_get_5() {
    TEST_ASSERT_EQUAL_INT(-1, get("1"));
    put("x", 3);
    TEST_ASSERT_EQUAL_INT(-1, get("3"));
    clear_memory();
}


void test_strees_put_and_get_1() {
    for (int i = 0; i < 10000; i++) {
        put("x", i);
        TEST_ASSERT_EQUAL_INT(i, get("x"));
    }
    
    clear_memory();
}


void test_putarr_and_getarr_1() {
    putarr("array", 0, 4);
    TEST_ASSERT_EQUAL_INT(4, getarr("array", 0));
    clear_memory();
}


void test_putarr_and_getarr_2() {
    putarr("array", 0, 4);
    putarr("array", 1, 3);
    TEST_ASSERT_EQUAL_INT(4, getarr("array", 0));
    TEST_ASSERT_EQUAL_INT(3, getarr("array", 1));
    clear_memory();
}


void test_putarr_and_getarr_3() {
    putarr("array", 0, 4);
    putarr("array", 1, 3);
    putarr("array", 3, 2);
    TEST_ASSERT_EQUAL_INT(4, getarr("array", 0));
    TEST_ASSERT_EQUAL_INT(3, getarr("array", 1));
    TEST_ASSERT_EQUAL_INT(0, getarr("array", 2));
    TEST_ASSERT_EQUAL_INT(2, getarr("array", 3));
    clear_memory();
}


void test_putarr_and_getarr_4() {
    putarr("array", 0, 4);
    putarr("array", 1, 3);
    putarr("array", 3, 2);
    putarr("collection", 2, 1);
    TEST_ASSERT_EQUAL_INT(4, getarr("array", 0));
    TEST_ASSERT_EQUAL_INT(3, getarr("array", 1));
    TEST_ASSERT_EQUAL_INT(0, getarr("array", 2));
    TEST_ASSERT_EQUAL_INT(2, getarr("array", 3));
    TEST_ASSERT_EQUAL_INT(0, getarr("collection", 0));
    TEST_ASSERT_EQUAL_INT(0, getarr("collection", 1));
    TEST_ASSERT_EQUAL_INT(1, getarr("collection", 2));
    clear_memory();
}


void test_putarr_and_getarr_5() {
    putarr("array", 0, 4);
    putarr("array", 1, 3);
    putarr("array", 3, 2);
    TEST_ASSERT_EQUAL_INT(4, getarr("array", 0));
    TEST_ASSERT_EQUAL_INT(3, getarr("array", 1));
    TEST_ASSERT_EQUAL_INT(0, getarr("array", 2));
    TEST_ASSERT_EQUAL_INT(2, getarr("array", 3));
    TEST_ASSERT_EQUAL_INT(-1, getarr("array", 4));
    TEST_ASSERT_EQUAL_INT(-1, getarr("array", -1));
    clear_memory();
}
/*

void test_stress_putarr_and_getarr_1() {
    for (int i = 0; i < 100; i++) {
        putarr("array", i, i);
    }
    
    for (int i = 0; i < 100; i++) {
        TEST_ASSERT_EQUAL_INT(i, getarr("array", i));
    }

    for (int i = MAXSIZE; i < 10000; i++) {
        TEST_ASSERT_EQUAL_INT(-1, getarr("array", i));
    }

    clear_memory();
}
*/
