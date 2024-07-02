#include "src/binary_tree.h"
#include "src/pool_allocator.h"
#include "src/memory.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"




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

    UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((get("value"))), (

   ((void *)0)

   ), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_INT);

    clear_memory();

}





void test_put_and_get_2() {

    put("value", 10);

    UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((get("value"))), (

   ((void *)0)

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_INT);

    put("a", 0);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((get("a"))), (

   ((void *)0)

   ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((get("value"))), (

   ((void *)0)

   ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_INT);

    clear_memory();

}





void test_put_and_get_3() {

    put("value", 10);

    UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((get("value"))), (

   ((void *)0)

   ), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_INT);

    put("value", 3);

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((get("value"))), (

   ((void *)0)

   ), (UNITY_UINT)(42), UNITY_DISPLAY_STYLE_INT);

    clear_memory();

}





void test_put_and_get_4() {

    put("1", 11);

    UnityAssertEqualNumber((UNITY_INT)((11)), (UNITY_INT)((get("1"))), (

   ((void *)0)

   ), (UNITY_UINT)(49), UNITY_DISPLAY_STYLE_INT);

    put("2", 22);

    UnityAssertEqualNumber((UNITY_INT)((22)), (UNITY_INT)((get("2"))), (

   ((void *)0)

   ), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_INT);

    put("-1", -11);

    UnityAssertEqualNumber((UNITY_INT)((-11)), (UNITY_INT)((get("-1"))), (

   ((void *)0)

   ), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_INT);

    put("-2", -22);

    UnityAssertEqualNumber((UNITY_INT)((-22)), (UNITY_INT)((get("-2"))), (

   ((void *)0)

   ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_INT);

    clear_memory();

}





void test_put_and_get_5() {

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((get("1"))), (

   ((void *)0)

   ), (UNITY_UINT)(61), UNITY_DISPLAY_STYLE_INT);

    put("x", 3);

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((get("3"))), (

   ((void *)0)

   ), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_INT);

    clear_memory();

}





void test_strees_put_and_get_1() {

    for (int i = 0; i < 10000; i++) {

        put("x", i);

        UnityAssertEqualNumber((UNITY_INT)((i)), (UNITY_INT)((get("x"))), (

       ((void *)0)

       ), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_INT);

    }



    clear_memory();

}





void test_putarr_and_getarr_1() {

    putarr("array", 0, 4);

    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((getarr("array", 0))), (

   ((void *)0)

   ), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_INT);

    clear_memory();

}





void test_putarr_and_getarr_2() {

    putarr("array", 0, 4);

    putarr("array", 1, 3);

    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((getarr("array", 0))), (

   ((void *)0)

   ), (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((getarr("array", 1))), (

   ((void *)0)

   ), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_INT);

    clear_memory();

}





void test_putarr_and_getarr_3() {

    putarr("array", 0, 4);

    putarr("array", 1, 3);

    putarr("array", 3, 2);

    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((getarr("array", 0))), (

   ((void *)0)

   ), (UNITY_UINT)(98), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((getarr("array", 1))), (

   ((void *)0)

   ), (UNITY_UINT)(99), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((getarr("array", 2))), (

   ((void *)0)

   ), (UNITY_UINT)(100), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((getarr("array", 3))), (

   ((void *)0)

   ), (UNITY_UINT)(101), UNITY_DISPLAY_STYLE_INT);

    clear_memory();

}





void test_putarr_and_getarr_4() {

    putarr("array", 0, 4);

    putarr("array", 1, 3);

    putarr("array", 3, 2);

    putarr("collection", 2, 1);

    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((getarr("array", 0))), (

   ((void *)0)

   ), (UNITY_UINT)(111), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((getarr("array", 1))), (

   ((void *)0)

   ), (UNITY_UINT)(112), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((getarr("array", 2))), (

   ((void *)0)

   ), (UNITY_UINT)(113), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((getarr("array", 3))), (

   ((void *)0)

   ), (UNITY_UINT)(114), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((getarr("collection", 0))), (

   ((void *)0)

   ), (UNITY_UINT)(115), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((getarr("collection", 1))), (

   ((void *)0)

   ), (UNITY_UINT)(116), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((getarr("collection", 2))), (

   ((void *)0)

   ), (UNITY_UINT)(117), UNITY_DISPLAY_STYLE_INT);

    clear_memory();

}





void test_putarr_and_getarr_5() {

    putarr("array", 0, 4);

    putarr("array", 1, 3);

    putarr("array", 3, 2);

    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((getarr("array", 0))), (

   ((void *)0)

   ), (UNITY_UINT)(126), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((getarr("array", 1))), (

   ((void *)0)

   ), (UNITY_UINT)(127), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((getarr("array", 2))), (

   ((void *)0)

   ), (UNITY_UINT)(128), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((getarr("array", 3))), (

   ((void *)0)

   ), (UNITY_UINT)(129), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((getarr("array", 4))), (

   ((void *)0)

   ), (UNITY_UINT)(130), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((getarr("array", -1))), (

   ((void *)0)

   ), (UNITY_UINT)(131), UNITY_DISPLAY_STYLE_INT);

    clear_memory();

}
