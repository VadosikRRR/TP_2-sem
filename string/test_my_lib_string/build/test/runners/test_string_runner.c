/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_create_and_delete();
extern void test_length_1();
extern void test_length_2();
extern void test_length_3();
extern void test_string_cmp_1();
extern void test_string_cmp_2();
extern void test_string_cmp_3();
extern void test_string_cmp_4();
extern void test_string_cmp_5();
extern void test_string_cmp_6();
extern void test_string_c_cmp_1();
extern void test_string_c_cmp_2();
extern void test_string_c_cmp_3();
extern void test_string_c_cmp_4();
extern void test_string_c_cmp_5();
extern void test_string_c_cmp_6();
extern void test_string_chr_1();
extern void test_string_chr_2();
extern void test_string_chr_3();
extern void test_string_chr_4();
extern void test_string_rchr_1();
extern void test_string_rchr_2();
extern void test_string_rchr_3();
extern void test_string_rchr_4();
extern void test_new_string_with_length_1();
extern void test_new_string_with_length_2();
extern void test_new_string_with_length_3();
extern void test_cat_1();
extern void test_cat_2();
extern void test_cat_3();
extern void test_cat_4();
extern void test_substring_1();
extern void test_substring_2();
extern void test_substring_3();
extern void test_split_1();
extern void test_split_2();
extern void test_split_3();
extern void test_split_4();
extern void test_split_5();


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
}
static void CMock_Verify(void)
{
}
static void CMock_Destroy(void)
{
}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}

/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, UNITY_LINE_TYPE line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {
        setUp();
        func();
    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_string.c");
  run_test(test_create_and_delete, "test_create_and_delete", 14);
  run_test(test_length_1, "test_length_1", 22);
  run_test(test_length_2, "test_length_2", 30);
  run_test(test_length_3, "test_length_3", 38);
  run_test(test_string_cmp_1, "test_string_cmp_1", 46);
  run_test(test_string_cmp_2, "test_string_cmp_2", 56);
  run_test(test_string_cmp_3, "test_string_cmp_3", 66);
  run_test(test_string_cmp_4, "test_string_cmp_4", 76);
  run_test(test_string_cmp_5, "test_string_cmp_5", 86);
  run_test(test_string_cmp_6, "test_string_cmp_6", 96);
  run_test(test_string_c_cmp_1, "test_string_c_cmp_1", 106);
  run_test(test_string_c_cmp_2, "test_string_c_cmp_2", 114);
  run_test(test_string_c_cmp_3, "test_string_c_cmp_3", 122);
  run_test(test_string_c_cmp_4, "test_string_c_cmp_4", 130);
  run_test(test_string_c_cmp_5, "test_string_c_cmp_5", 138);
  run_test(test_string_c_cmp_6, "test_string_c_cmp_6", 146);
  run_test(test_string_chr_1, "test_string_chr_1", 154);
  run_test(test_string_chr_2, "test_string_chr_2", 163);
  run_test(test_string_chr_3, "test_string_chr_3", 174);
  run_test(test_string_chr_4, "test_string_chr_4", 185);
  run_test(test_string_rchr_1, "test_string_rchr_1", 196);
  run_test(test_string_rchr_2, "test_string_rchr_2", 205);
  run_test(test_string_rchr_3, "test_string_rchr_3", 217);
  run_test(test_string_rchr_4, "test_string_rchr_4", 229);
  run_test(test_new_string_with_length_1, "test_new_string_with_length_1", 245);
  run_test(test_new_string_with_length_2, "test_new_string_with_length_2", 255);
  run_test(test_new_string_with_length_3, "test_new_string_with_length_3", 265);
  run_test(test_cat_1, "test_cat_1", 275);
  run_test(test_cat_2, "test_cat_2", 289);
  run_test(test_cat_3, "test_cat_3", 303);
  run_test(test_cat_4, "test_cat_4", 317);
  run_test(test_substring_1, "test_substring_1", 331);
  run_test(test_substring_2, "test_substring_2", 343);
  run_test(test_substring_3, "test_substring_3", 355);
  run_test(test_split_1, "test_split_1", 367);
  run_test(test_split_2, "test_split_2", 378);
  run_test(test_split_3, "test_split_3", 390);
  run_test(test_split_4, "test_split_4", 403);
  run_test(test_split_5, "test_split_5", 414);

  return UnityEnd();
}
