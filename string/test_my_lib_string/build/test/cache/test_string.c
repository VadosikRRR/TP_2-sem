#include "src/string.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"




void setUp(void) {

}





void tearDown(void) {

}







void test_create_and_delete() {

    string str = new_string("");

    do {if ((((str.p_data)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(16))));}} while(0);

    delete_string(&str);

}







void test_length_1() {

    string str = new_string("");

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((str.length)), (

   ((void *)0)

   ), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_INT);

    delete_string(&str);

}







void test_length_2() {

    string str = new_string("123abc");

    UnityAssertEqualNumber((UNITY_INT)((6)), (UNITY_INT)((str.length)), (

   ((void *)0)

   ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_INT);

    delete_string(&str);

}







void test_length_3() {

    string str = new_string("1 2 3 4 5 6 7 8 9 0");

    UnityAssertEqualNumber((UNITY_INT)((19)), (UNITY_INT)((str.length)), (

   ((void *)0)

   ), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_INT);

    delete_string(&str);

}







void test_string_cmp_1() {

    string str1 = new_string("");

    string str2 = new_string("");

    do {if ((!string_cmp(&str1, &str2))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(49)));}} while(0);

    delete_string(&str1);

    delete_string(&str2);

}







void test_string_cmp_2() {

    string str1 = new_string("a");

    string str2 = new_string("a");

    do {if ((!string_cmp(&str1, &str2))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(59)));}} while(0);

    delete_string(&str1);

    delete_string(&str2);

}







void test_string_cmp_3() {

    string str1 = new_string("abc");

    string str2 = new_string("abc");

    do {if ((!string_cmp(&str1, &str2))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(69)));}} while(0);

    delete_string(&str1);

    delete_string(&str2);

}







void test_string_cmp_4() {

    string str1 = new_string("abc");

    string str2 = new_string("cab");

    do {if (!(!string_cmp(&str1, &str2))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(79)));}} while(0);

    delete_string(&str1);

    delete_string(&str2);

}







void test_string_cmp_5() {

    string str1 = new_string("Hello! how are you? 123 321");

    string str2 = new_string("Hello! how are you? 123 321");

    do {if ((!string_cmp(&str1, &str2))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(89)));}} while(0);

    delete_string(&str1);

    delete_string(&str2);

}







void test_string_cmp_6() {

    string str1 = new_string("Hello! how are you? 123 321+");

    string str2 = new_string("Hello! how are you? 123 321");

    do {if (!(!string_cmp(&str1, &str2))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(99)));}} while(0);

    delete_string(&str1);

    delete_string(&str2);

}







void test_string_c_cmp_1() {

    string str = new_string("");

    do {if ((!string_c_cmp(&str, ""))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(108)));}} while(0);

    delete_string(&str);

}







void test_string_c_cmp_2() {

    string str = new_string("a");

    do {if ((!string_c_cmp(&str, "a"))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(116)));}} while(0);

    delete_string(&str);

}







void test_string_c_cmp_3() {

    string str = new_string("abc");

    do {if ((!string_c_cmp(&str, "abc"))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(124)));}} while(0);

    delete_string(&str);

}







void test_string_c_cmp_4() {

    string str = new_string("abc");

    do {if (!(!string_c_cmp(&str, "cab"))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(132)));}} while(0);

    delete_string(&str);

}







void test_string_c_cmp_5() {

    string str = new_string("Hello! how are you? 123 321");

    do {if ((!string_c_cmp(&str, "Hello! how are you? 123 321"))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(140)));}} while(0);

    delete_string(&str);

}







void test_string_c_cmp_6() {

    string str = new_string("Hello! how are you? 123 321+");

    do {if (!(!string_c_cmp(&str, "Hello! how are you? 123 321"))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(148)));}} while(0);

    delete_string(&str);

}







void test_string_chr_1() {

    string str = new_string("");

    char *p_symbol = string_chr('a', &str);

    do {if ((((p_symbol)) == 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(157))));}} while(0);

    delete_string(&str);

}







void test_string_chr_2() {

    string str = new_string("a");

    string correct_str = new_string("a");

    char *p_symbol = string_chr('a', &str);

    do {if ((!string_c_cmp(&correct_str, p_symbol))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(167)));}} while(0);

    delete_string(&str);

    delete_string(&correct_str);

}







void test_string_chr_3() {

    string str = new_string("12345");

    string correct_str = new_string("345");

    char *p_symbol = string_chr('3', &str);

    do {if ((!string_c_cmp(&correct_str, p_symbol))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(178)));}} while(0);

    delete_string(&str);

    delete_string(&correct_str);

}







void test_string_chr_4() {

    string str = new_string("1233453");

    string correct_str = new_string("33453");

    char *p_symbol = string_chr('3', &str);

    do {if ((!string_c_cmp(&correct_str, p_symbol))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(189)));}} while(0);

    delete_string(&str);

    delete_string(&correct_str);

}







void test_string_rchr_1() {

    string str = new_string("");

    char *p_symbol = string_rchr('a', &str);

    do {if ((((p_symbol)) == 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(199))));}} while(0);

    delete_string(&str);

}







void test_string_rchr_2() {

    string str = new_string("a");

    string correct_str = new_string("a");

    char *p_symbol = string_rchr('a', &str);

    do {if ((!string_c_cmp(&correct_str, p_symbol))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(209)));}} while(0);

    p_symbol = 

              ((void *)0)

                  ;

    delete_string(&str);

    delete_string(&correct_str);

}







void test_string_rchr_3() {

    string str = new_string("12345");

    string correct_str = new_string("345");

    char *p_symbol = string_rchr('3', &str);

    do {if ((!string_c_cmp(&correct_str, p_symbol))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(221)));}} while(0);

    p_symbol = 

              ((void *)0)

                  ;

    delete_string(&str);

    delete_string(&correct_str);

}







void test_string_rchr_4() {

    string str = new_string("1233453");

    string correct_str = new_string("3");

    char *p_symbol = string_rchr('3', &str);

    do {if ((!string_c_cmp(&correct_str, p_symbol))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(233)));}} while(0);

    p_symbol = 

              ((void *)0)

                  ;

    delete_string(&str);

    delete_string(&correct_str);

}















void test_new_string_with_length_1() {

    string str1 = new_string_with_length("", 0);

    string str2 = new_string("");

    do {if ((!string_cmp(&str1, &str2))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(248)));}} while(0);

    delete_string(&str1);

    delete_string(&str2);

}







void test_new_string_with_length_2() {

    string str1 = new_string_with_length("abc123", 10);

    string str2 = new_string("abc123");

    do {if ((!string_cmp(&str1, &str2))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(258)));}} while(0);

    delete_string(&str1);

    delete_string(&str2);

}







void test_new_string_with_length_3() {

    string str1 = new_string_with_length("abc123", 4);

    string str2 = new_string("abc1");

    do {if ((!string_cmp(&str1, &str2))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(268)));}} while(0);

    delete_string(&str1);

    delete_string(&str2);

}







void test_cat_1() {

    string str1 = new_string("");

    string str2 = new_string("");

    string correct_str = new_string("");

    string result_str = cat(&str1, &str2);

    do {if ((!string_cmp(&result_str, &correct_str))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(280)));}} while(0);

    delete_string(&str1);

    delete_string(&str2);

    delete_string(&correct_str);

    delete_string(&result_str);

}







void test_cat_2() {

    string str1 = new_string("abc");

    string str2 = new_string("");

    string correct_str = new_string("abc");

    string result_str = cat(&str1, &str2);

    do {if ((!string_cmp(&result_str, &correct_str))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(294)));}} while(0);

    delete_string(&str1);

    delete_string(&str2);

    delete_string(&correct_str);

    delete_string(&result_str);

}







void test_cat_3() {

    string str1 = new_string("123");

    string str2 = new_string("456");

    string correct_str = new_string("123456");

    string result_str = cat(&str1, &str2);

    do {if ((!string_cmp(&result_str, &correct_str))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(308)));}} while(0);

    delete_string(&str1);

    delete_string(&str2);

    delete_string(&correct_str);

    delete_string(&result_str);

}







void test_cat_4() {

    string str1 = new_string("Hello my friend! ");

    string str2 = new_string("How are you?");

    string correct_str = new_string("Hello my friend! How are you?");

    string result_str = cat(&str1, &str2);

    do {if ((!string_cmp(&result_str, &correct_str))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(322)));}} while(0);

    delete_string(&str1);

    delete_string(&str2);

    delete_string(&correct_str);

    delete_string(&result_str);

}







void test_substring_1() {

    string str = new_string("");

    string correct_str = new_string("");

    string substr = substring(&str, 0, 0);

    do {if ((!string_cmp(&substr, &correct_str))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(335)));}} while(0);

    delete_string(&str);

    delete_string(&correct_str);

    delete_string(&substr);

}







void test_substring_2() {

    string str = new_string("abcde12345abcde");

    string correct_str = new_string("12345a");

    string substr = substring(&str, 5, 6);

    do {if ((!string_cmp(&substr, &correct_str))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(347)));}} while(0);

    delete_string(&str);

    delete_string(&correct_str);

    delete_string(&substr);

}







void test_substring_3() {

    string str = new_string("Hello world!");

    string correct_str = new_string("world!");

    string substr = substring(&str, 6, 10);

    do {if ((!string_cmp(&substr, &correct_str))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(359)));}} while(0);

    delete_string(&str);

    delete_string(&correct_str);

    delete_string(&substr);

}







void test_split_1() {

    string str = new_string("");

    array_string array_str = split('a', &str);

    do {if ((!string_cmp(array_str.p_data, &str))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(370)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((array_str.length)), (

   ((void *)0)

   ), (UNITY_UINT)(371), UNITY_DISPLAY_STYLE_INT);

    delete_string(&str);

    delete_array_string(&array_str);

}







void test_split_2() {

    string str = new_string("abc");

    array_string array_str = split('b', &str);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((array_str.length)), (

   ((void *)0)

   ), (UNITY_UINT)(381), UNITY_DISPLAY_STYLE_INT);

    do {if ((!string_c_cmp(array_str.p_data, "a"))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(382)));}} while(0);

    do {if ((!string_c_cmp(array_str.p_data + 1, "c"))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(383)));}} while(0);

    delete_string(&str);

    delete_array_string(&array_str);

}







void test_split_3() {

    string str = new_string("1233456378");

    array_string array_str = split('3', &str);

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((array_str.length)), (

   ((void *)0)

   ), (UNITY_UINT)(393), UNITY_DISPLAY_STYLE_INT);

    do {if ((!string_c_cmp(array_str.p_data, "12"))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(394)));}} while(0);

    do {if ((!string_c_cmp(array_str.p_data + 1, "456"))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(395)));}} while(0);

    do {if ((!string_c_cmp(array_str.p_data + 2, "78"))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(396)));}} while(0);

    delete_string(&str);

    delete_array_string(&array_str);

}







void test_split_4() {

    string str = new_string("1233456378");

    array_string array_str = split('b', &str);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((array_str.length)), (

   ((void *)0)

   ), (UNITY_UINT)(406), UNITY_DISPLAY_STYLE_INT);

    do {if ((!string_c_cmp(array_str.p_data, "1233456378"))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(407)));}} while(0);

    delete_string(&str);

    delete_array_string(&array_str);

}







void test_split_5() {

    string str = new_string("aaa");

    array_string array_str = split('a', &str);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((array_str.length)), (

   ((void *)0)

   ), (UNITY_UINT)(417), UNITY_DISPLAY_STYLE_INT);

    do {if ((!string_c_cmp(array_str.p_data, ""))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(418)));}} while(0);

    delete_string(&str);

    delete_array_string(&array_str);

}
