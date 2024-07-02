#include "unity.h"
#include "string.h"


void setUp(void) {
}


void tearDown(void) {
}


// Создать, проверить, что указывает не на NULL и удалить.
void test_create_and_delete() {
    string str = new_string("");
    TEST_ASSERT_NOT_NULL(str.p_data);
    delete_string(&str);
}


// "".length == 0
void test_length_1() {
    string str = new_string("");
    TEST_ASSERT_EQUAL_INT(0, str.length);
    delete_string(&str);
}


// "123abc".length == 6
void test_length_2() {
    string str = new_string("123abc");
    TEST_ASSERT_EQUAL_INT(6, str.length);
    delete_string(&str);
}


// "1 2 3 4 5 6 7 8 9 0".length == 19
void test_length_3() {
    string str = new_string("1 2 3 4 5 6 7 8 9 0");
    TEST_ASSERT_EQUAL_INT(19, str.length);
    delete_string(&str);
}


// "" == ""
void test_string_cmp_1() {
    string str1 = new_string("");
    string str2 = new_string("");
    TEST_ASSERT_TRUE(!string_cmp(&str1, &str2));
    delete_string(&str1);
    delete_string(&str2);
}


// "a" == "a"
void test_string_cmp_2() {
    string str1 = new_string("a");
    string str2 = new_string("a");
    TEST_ASSERT_TRUE(!string_cmp(&str1, &str2));
    delete_string(&str1);
    delete_string(&str2);
}


// "abc" == "abc"
void test_string_cmp_3() {
    string str1 = new_string("abc");
    string str2 = new_string("abc");
    TEST_ASSERT_TRUE(!string_cmp(&str1, &str2));
    delete_string(&str1);
    delete_string(&str2);
}


// "abc" == "cab"
void test_string_cmp_4() {
    string str1 = new_string("abc");
    string str2 = new_string("cab");
    TEST_ASSERT_FALSE(!string_cmp(&str1, &str2));
    delete_string(&str1);
    delete_string(&str2);
}


// "Hello! how are you? 123 321" == "Hello! how are you? 123 321"
void test_string_cmp_5() {
    string str1 = new_string("Hello! how are you? 123 321");
    string str2 = new_string("Hello! how are you? 123 321");
    TEST_ASSERT_TRUE(!string_cmp(&str1, &str2));
    delete_string(&str1);
    delete_string(&str2);
}


// "Hello! how are you? 123 321+" == "Hello! how are you? 123 321"
void test_string_cmp_6() {
    string str1 = new_string("Hello! how are you? 123 321+");
    string str2 = new_string("Hello! how are you? 123 321");
    TEST_ASSERT_FALSE(!string_cmp(&str1, &str2));
    delete_string(&str1);
    delete_string(&str2);
}


// "" == ""
void test_string_c_cmp_1() {
    string str = new_string("");
    TEST_ASSERT_TRUE(!string_c_cmp(&str, ""));
    delete_string(&str);
}


// "a" == "a"
void test_string_c_cmp_2() {
    string str = new_string("a");
    TEST_ASSERT_TRUE(!string_c_cmp(&str, "a"));
    delete_string(&str);
}


// "abc" == "abc"
void test_string_c_cmp_3() {
    string str = new_string("abc");
    TEST_ASSERT_TRUE(!string_c_cmp(&str, "abc"));
    delete_string(&str);
}


// "abc" == "cab"
void test_string_c_cmp_4() {
    string str = new_string("abc");
    TEST_ASSERT_FALSE(!string_c_cmp(&str, "cab"));
    delete_string(&str);
}


// "Hello! how are you? 123 321" == "Hello! how are you? 123 321"
void test_string_c_cmp_5() {
    string str = new_string("Hello! how are you? 123 321");
    TEST_ASSERT_TRUE(!string_c_cmp(&str, "Hello! how are you? 123 321"));
    delete_string(&str);
}


// "Hello! how are you? 123 321+" == "Hello! how are you? 123 321"
void test_string_c_cmp_6() {
    string str = new_string("Hello! how are you? 123 321+");
    TEST_ASSERT_FALSE(!string_c_cmp(&str, "Hello! how are you? 123 321"));
    delete_string(&str);
}


// "" find 'a' => ""
void test_string_chr_1() {
    string str = new_string("");
    char *p_symbol = string_chr('a', &str);
    TEST_ASSERT_NULL(p_symbol);
    delete_string(&str);
}


// "a" find 'a' => "a"
void test_string_chr_2() {
    string str = new_string("a");
    string correct_str = new_string("a");
    char *p_symbol = string_chr('a', &str);
    TEST_ASSERT_TRUE(!string_c_cmp(&correct_str, p_symbol));
    delete_string(&str);
    delete_string(&correct_str);
}


// "12345" find '3' => "345"
void test_string_chr_3() {
    string str = new_string("12345");
    string correct_str = new_string("345");
    char *p_symbol = string_chr('3', &str);
    TEST_ASSERT_TRUE(!string_c_cmp(&correct_str, p_symbol));
    delete_string(&str);
    delete_string(&correct_str);
}


// "1233453" find '3' => "33453"
void test_string_chr_4() {
    string str = new_string("1233453");
    string correct_str = new_string("33453");
    char *p_symbol = string_chr('3', &str);
    TEST_ASSERT_TRUE(!string_c_cmp(&correct_str, p_symbol));
    delete_string(&str);
    delete_string(&correct_str);
}


// "" find 'a' => ""
void test_string_rchr_1() {
    string str = new_string("");
    char *p_symbol = string_rchr('a', &str);
    TEST_ASSERT_NULL(p_symbol);
    delete_string(&str);
}


// "a" find 'a' => "a"
void test_string_rchr_2() {
    string str = new_string("a");
    string correct_str = new_string("a");
    char *p_symbol = string_rchr('a', &str);
    TEST_ASSERT_TRUE(!string_c_cmp(&correct_str, p_symbol));
    p_symbol = NULL;
    delete_string(&str);
    delete_string(&correct_str);
}


// "12345" find '3' => "345"
void test_string_rchr_3() {
    string str = new_string("12345");
    string correct_str = new_string("345");
    char *p_symbol = string_rchr('3', &str);
    TEST_ASSERT_TRUE(!string_c_cmp(&correct_str, p_symbol));
    p_symbol = NULL;
    delete_string(&str);
    delete_string(&correct_str);
}


// "1233453" find '3' => "3"
void test_string_rchr_4() {
    string str = new_string("1233453");
    string correct_str = new_string("3");
    char *p_symbol = string_rchr('3', &str);
    TEST_ASSERT_TRUE(!string_c_cmp(&correct_str, p_symbol));
    p_symbol = NULL;
    delete_string(&str);
    delete_string(&correct_str);
}


// Унивирсальный конструктор, принимает массив символов и длину строки,
// Но если не хватает в строке такого количетсва символов, 
//то он просто создаст строку из символов

// "", 0 -> ""
void test_new_string_with_length_1() {
    string str1 = new_string_with_length("", 0);
    string str2 = new_string("");
    TEST_ASSERT_TRUE(!string_cmp(&str1, &str2));
    delete_string(&str1);
    delete_string(&str2);
}


// "abc123", 10 -> "abc123"
void test_new_string_with_length_2() {
    string str1 = new_string_with_length("abc123", 10);
    string str2 = new_string("abc123");
    TEST_ASSERT_TRUE(!string_cmp(&str1, &str2));
    delete_string(&str1);
    delete_string(&str2);
}


// "abc123", 4 -> "abc1"
void test_new_string_with_length_3() {
    string str1 = new_string_with_length("abc123", 4);
    string str2 = new_string("abc1");
    TEST_ASSERT_TRUE(!string_cmp(&str1, &str2));
    delete_string(&str1);
    delete_string(&str2);
}


// "" + "" == ""
void test_cat_1() {
    string str1 = new_string("");
    string str2 = new_string("");
    string correct_str = new_string("");
    string result_str = cat(&str1, &str2);
    TEST_ASSERT_TRUE(!string_cmp(&result_str, &correct_str));
    delete_string(&str1);
    delete_string(&str2);
    delete_string(&correct_str);
    delete_string(&result_str);
}


// "abc" + "" == "abc"
void test_cat_2() {
    string str1 = new_string("abc");
    string str2 = new_string("");
    string correct_str = new_string("abc");
    string result_str = cat(&str1, &str2);
    TEST_ASSERT_TRUE(!string_cmp(&result_str, &correct_str));
    delete_string(&str1);
    delete_string(&str2);
    delete_string(&correct_str);
    delete_string(&result_str);
}


// "123" + "456" == "123456"
void test_cat_3() {
    string str1 = new_string("123");
    string str2 = new_string("456");
    string correct_str = new_string("123456");
    string result_str = cat(&str1, &str2);
    TEST_ASSERT_TRUE(!string_cmp(&result_str, &correct_str));
    delete_string(&str1);
    delete_string(&str2);
    delete_string(&correct_str);
    delete_string(&result_str);
}


// "Hello my friend! " + "How are you?" == "Hello my friend! How are you?"
void test_cat_4() {
    string str1 = new_string("Hello my friend! ");
    string str2 = new_string("How are you?");
    string correct_str = new_string("Hello my friend! How are you?");
    string result_str = cat(&str1, &str2);
    TEST_ASSERT_TRUE(!string_cmp(&result_str, &correct_str));
    delete_string(&str1);
    delete_string(&str2);
    delete_string(&correct_str);
    delete_string(&result_str);
}


// "", 0, 0 -> ""
void test_substring_1() {
    string str = new_string("");
    string correct_str = new_string("");
    string substr = substring(&str, 0, 0);
    TEST_ASSERT_TRUE(!string_cmp(&substr, &correct_str));
    delete_string(&str);
    delete_string(&correct_str);
    delete_string(&substr);
}


// "abcde12345abcde", 5, 6 -> "12345a"
void test_substring_2() {
    string str = new_string("abcde12345abcde");
    string correct_str = new_string("12345a");
    string substr = substring(&str, 5, 6);
    TEST_ASSERT_TRUE(!string_cmp(&substr, &correct_str));
    delete_string(&str);
    delete_string(&correct_str);
    delete_string(&substr);
}


// "Hello world!", 6, 10 -> "world!"
void test_substring_3() {
    string str = new_string("Hello world!");
    string correct_str = new_string("world!");
    string substr = substring(&str, 6, 10);
    TEST_ASSERT_TRUE(!string_cmp(&substr, &correct_str));
    delete_string(&str);
    delete_string(&correct_str);
    delete_string(&substr);
}


// "", 'a' -> [""]
void test_split_1() {
    string str = new_string("");
    array_string array_str = split('a', &str);
    TEST_ASSERT_TRUE(!string_cmp(array_str.p_data, &str));
    TEST_ASSERT_EQUAL_INT(1, array_str.length);
    delete_string(&str);
    delete_array_string(&array_str);
}


// "abc", 'b' -> ["a", "c"]
void test_split_2() {
    string str = new_string("abc");
    array_string array_str = split('b', &str);
    TEST_ASSERT_EQUAL_INT(2, array_str.length);
    TEST_ASSERT_TRUE(!string_c_cmp(array_str.p_data, "a"));
    TEST_ASSERT_TRUE(!string_c_cmp(array_str.p_data + 1, "c"));
    delete_string(&str);
    delete_array_string(&array_str);
}


// "1233456378", '3' -> ["12", "456", "78"]
void test_split_3() {
    string str = new_string("1233456378");
    array_string array_str = split('3', &str);
    TEST_ASSERT_EQUAL_INT(3, array_str.length);
    TEST_ASSERT_TRUE(!string_c_cmp(array_str.p_data, "12"));
    TEST_ASSERT_TRUE(!string_c_cmp(array_str.p_data + 1, "456"));
    TEST_ASSERT_TRUE(!string_c_cmp(array_str.p_data + 2, "78"));
    delete_string(&str);
    delete_array_string(&array_str);
}


// "1233456378", 'b' -> ["1233456378"]
void test_split_4() {
    string str = new_string("1233456378");
    array_string array_str = split('b', &str);
    TEST_ASSERT_EQUAL_INT(1, array_str.length);
    TEST_ASSERT_TRUE(!string_c_cmp(array_str.p_data, "1233456378"));
    delete_string(&str);
    delete_array_string(&array_str);
}


// "aaa", 'a' -> [""]
void test_split_5() {
    string str = new_string("aaa");
    array_string array_str = split('a', &str);
    TEST_ASSERT_EQUAL_INT(1, array_str.length);
    TEST_ASSERT_TRUE(!string_c_cmp(array_str.p_data, ""));
    delete_string(&str);
    delete_array_string(&array_str);
}

/*
int main(void) {
UNITY_BEGIN();
RUN_TEST(test_create_and_delete);
RUN_TEST(test_length_1);
RUN_TEST(test_length_2);
RUN_TEST(test_length_3);
RUN_TEST(test_string_cmp_1);
RUN_TEST(test_string_cmp_2);
RUN_TEST(test_string_cmp_3);
RUN_TEST(test_string_cmp_4);
RUN_TEST(test_string_cmp_5);
RUN_TEST(test_string_cmp_6);
RUN_TEST(test_string_c_cmp_1);
RUN_TEST(test_string_c_cmp_2);
RUN_TEST(test_string_c_cmp_3);
RUN_TEST(test_string_c_cmp_4);
RUN_TEST(test_string_c_cmp_5);
RUN_TEST(test_string_c_cmp_6);
RUN_TEST(test_cat_1);
RUN_TEST(test_cat_2);
RUN_TEST(test_cat_3);
RUN_TEST(test_cat_4);
RUN_TEST(test_new_string_with_length_1);
RUN_TEST(test_new_string_with_length_2);
RUN_TEST(test_new_string_with_length_3);
RUN_TEST(test_substring_1);
RUN_TEST(test_substring_2);
RUN_TEST(test_substring_3);
RUN_TEST(test_split_1);
RUN_TEST(test_split_2);
RUN_TEST(test_split_3);
RUN_TEST(test_split_4);
RUN_TEST(test_split_5);
return UNITY_END();
}
*/
