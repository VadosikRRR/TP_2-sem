/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_simple_1();
extern void test_simple_2();
extern void test_simple_3();
extern void test_simple_4();
extern void test_simple_5();
extern void test_simple_6();
extern void test_simple_7();
extern void test_simple_8();
extern void test_stress();


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
  UnityBegin("test_sequence.c");
  run_test(test_simple_1, "test_simple_1", 13);
  run_test(test_simple_2, "test_simple_2", 25);
  run_test(test_simple_3, "test_simple_3", 37);
  run_test(test_simple_4, "test_simple_4", 49);
  run_test(test_simple_5, "test_simple_5", 61);
  run_test(test_simple_6, "test_simple_6", 73);
  run_test(test_simple_7, "test_simple_7", 85);
  run_test(test_simple_8, "test_simple_8", 97);
  run_test(test_stress, "test_stress", 109);

  return UnityEnd();
}