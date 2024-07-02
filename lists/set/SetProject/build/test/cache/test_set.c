#include "src/set.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


static void add_range(int start, int finish, set *p_set);





void setUp() {

}





void tearDown() {

}







void test_create_and_delete() {

    set collection = new_set();

    do {if ((((&collection)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(18))));}} while(0);

    delete_set(&collection);

}







void test_find_elem_in_emply_set() {

    set collection = new_set();

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((collection.power)), (

   ((void *)0)

   ), (UNITY_UINT)(26), UNITY_DISPLAY_STYLE_INT);

    do {if (!(contains(1, &collection))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(27)));}} while(0);

    delete_set(&collection);

}







void test_add_1() {

    set collection = new_set();

    do {if (!(contains(1, &collection))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(35)));}} while(0);

    add(1, &collection);

    do {if ((contains(1, &collection))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(37)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((collection.power)), (

   ((void *)0)

   ), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_INT);

    delete_set(&collection);

}







void test_add_2() {

    set collection = new_set();

    do {if (!(contains(-2, &collection))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(46)));}} while(0);

    add(1, &collection);

    do {if (!(contains(-2, &collection))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(48)));}} while(0);

    add(-2, &collection);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((collection.power)), (

   ((void *)0)

   ), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_INT);

    do {if ((contains(-2, &collection))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(51)));}} while(0);

    delete_set(&collection);

}







void test_add_3() {

    set collection = new_set();

    do {if (!(contains(1215434, &collection))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(59)));}} while(0);

    add(1215434, &collection);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((collection.power)), (

   ((void *)0)

   ), (UNITY_UINT)(61), UNITY_DISPLAY_STYLE_INT);

    do {if ((contains(1215434, &collection))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(62)));}} while(0);

    delete_set(&collection);

}







void test_add_4() {

    set collection = new_set();

    do {if (!(contains(-432634, &collection))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(70)));}} while(0);

    add(1215434, &collection);

    do {if (!(contains(-432634, &collection))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(72)));}} while(0);

    add(-432634, &collection);

    do {if ((contains(-432634, &collection))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(74)));}} while(0);

    do {if ((contains(1215434, &collection))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(75)));}} while(0);

    delete_set(&collection);

}







void test_add_5() {

    set collection = new_set();

    do {if (!(contains(1215434, &collection))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(83)));}} while(0);

    add(-432634, &collection);

    do {if (!(contains(1215434, &collection))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(85)));}} while(0);

    add(1215434, &collection);

    do {if ((contains(-432634, &collection))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(87)));}} while(0);

    do {if ((contains(1215434, &collection))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(88)));}} while(0);

    delete_set(&collection);

}







void test_designer_1() {

    set collection = designer(0);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((collection.power)), (

   ((void *)0)

   ), (UNITY_UINT)(96), UNITY_DISPLAY_STYLE_INT);

    delete_set(&collection);

}







void test_designer_2() {

    set collection = designer(2, 1, -2);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((collection.power)), (

   ((void *)0)

   ), (UNITY_UINT)(104), UNITY_DISPLAY_STYLE_INT);

    do {if ((contains(1, &collection))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(105)));}} while(0);

    do {if ((contains(-2, &collection))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(106)));}} while(0);

    delete_set(&collection);

}







void test_designer_3() {

    set collection = designer(7, 1, -2, 100420, -353242, 2321, 51254, 32131);

    UnityAssertEqualNumber((UNITY_INT)((7)), (UNITY_INT)((collection.power)), (

   ((void *)0)

   ), (UNITY_UINT)(114), UNITY_DISPLAY_STYLE_INT);

    do {if ((contains(1, &collection))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(115)));}} while(0);

    do {if ((contains(-2, &collection))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(116)));}} while(0);

    do {if ((contains(100420, &collection))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(117)));}} while(0);

    do {if ((contains(-353242, &collection))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(118)));}} while(0);

    do {if ((contains(2321, &collection))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(119)));}} while(0);

    do {if ((contains(51254, &collection))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(120)));}} while(0);

    do {if ((contains(32131, &collection))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(121)));}} while(0);

    delete_set(&collection);

}







void test_designer_4() {

    set collection = designer(8, 1, -1, 1, -1, 1, -1, 1, -1);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((collection.power)), (

   ((void *)0)

   ), (UNITY_UINT)(129), UNITY_DISPLAY_STYLE_INT);

    do {if ((contains(1, &collection))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(130)));}} while(0);

    do {if ((contains(-1, &collection))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(131)));}} while(0);

    delete_set(&collection);

}







void test_erase_on_emply_set() {

    set collection = new_set();

    do {if (!(contains(0, &collection))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(139)));}} while(0);

    erase(0, &collection);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((collection.power)), (

   ((void *)0)

   ), (UNITY_UINT)(141), UNITY_DISPLAY_STYLE_INT);

    do {if (!(contains(0, &collection))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(142)));}} while(0);

    delete_set(&collection);

}







void test_erase_1() {

    set collection = designer(1, 0);

    erase(0, &collection);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((collection.power)), (

   ((void *)0)

   ), (UNITY_UINT)(151), UNITY_DISPLAY_STYLE_INT);

    do {if (!(contains(0, &collection))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(152)));}} while(0);

    delete_set(&collection);

}







void test_erase_2() {

    set collection = designer(1, 0, 1);

    erase(1, &collection);

    do {if ((contains(0, &collection))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(161)));}} while(0);

    do {if (!(contains(1, &collection))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(162)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((collection.power)), (

   ((void *)0)

   ), (UNITY_UINT)(163), UNITY_DISPLAY_STYLE_INT);

    delete_set(&collection);

}







void test_erase_3() {

    set collection = designer(1, 1);

    erase(1, &collection);

    add(1, &collection);

    do {if ((contains(1, &collection))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(173)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((collection.power)), (

   ((void *)0)

   ), (UNITY_UINT)(174), UNITY_DISPLAY_STYLE_INT);

    erase(1, &collection);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((collection.power)), (

   ((void *)0)

   ), (UNITY_UINT)(176), UNITY_DISPLAY_STYLE_INT);

    do {if (!(contains(1, &collection))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(177)));}} while(0);

    delete_set(&collection);

}







void test_erase_4() {

    set collection = designer(1, 1);

    erase(2, &collection);

    erase(3, &collection);

    do {if ((contains(1, &collection))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(187)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((collection.power)), (

   ((void *)0)

   ), (UNITY_UINT)(188), UNITY_DISPLAY_STYLE_INT);

    delete_set(&collection);

}







void test_stress_add_and_erase() {

    set collection = new_set();

    add_range(-10000, 9999, &collection);



    UnityAssertEqualNumber((UNITY_INT)((20000)), (UNITY_INT)((collection.power)), (

   ((void *)0)

   ), (UNITY_UINT)(198), UNITY_DISPLAY_STYLE_INT);

    do {if (!(contains(20000, &collection))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(199)));}} while(0);

    add(20000, &collection);

    UnityAssertEqualNumber((UNITY_INT)((20001)), (UNITY_INT)((collection.power)), (

   ((void *)0)

   ), (UNITY_UINT)(201), UNITY_DISPLAY_STYLE_INT);

    do {if ((contains(20000, &collection))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(202)));}} while(0);



    for (int i = -10000; i < 10000; i++) {

        erase(i, &collection);

    }



    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((collection.power)), (

   ((void *)0)

   ), (UNITY_UINT)(208), UNITY_DISPLAY_STYLE_INT);

    do {if ((contains(20000, &collection))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(209)));}} while(0);

    erase(20000, &collection);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((collection.power)), (

   ((void *)0)

   ), (UNITY_UINT)(211), UNITY_DISPLAY_STYLE_INT);

    do {if (!(contains(20000, &collection))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(212)));}} while(0);



    add(20000, &collection);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((collection.power)), (

   ((void *)0)

   ), (UNITY_UINT)(215), UNITY_DISPLAY_STYLE_INT);

    do {if ((contains(20000, &collection))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(216)));}} while(0);



    delete_set(&collection);

}







void test_stress_power() {

    set collection = new_set();

    for (int i = -10000; i < 10000; i++) {

        add(i, &collection);

        UnityAssertEqualNumber((UNITY_INT)((10001 + i)), (UNITY_INT)((collection.power)), (

       ((void *)0)

       ), (UNITY_UINT)(227), UNITY_DISPLAY_STYLE_INT);

    }



    for (int i = 9999; i >= -10000; i--) {

        erase(i, &collection);

        UnityAssertEqualNumber((UNITY_INT)((10000 + i)), (UNITY_INT)((collection.power)), (

       ((void *)0)

       ), (UNITY_UINT)(232), UNITY_DISPLAY_STYLE_INT);

    }



    delete_set(&collection);

}







void test_equal_1() {

    set set1 = new_set();

    set set2 = new_set();

    do {if ((equal(&set1, &set2))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(243)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

}







void test_equal_2() {

    set set1 = new_set();

    set set2 = designer(1, 1);

    do {if (!(equal(&set1, &set2))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(253)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

}







void test_equal_3() {

    set set1 = designer(3, 1, 2, 3);

    set set2 = designer(3, 3, 2, 1);

    do {if ((equal(&set1, &set2))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(263)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

}







void test_equal_4() {

    set set1 = designer(3, 10000, -20000, 30000);

    set set2 = designer(3, -20000, 10000, 30000);

    do {if ((equal(&set1, &set2))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(273)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

}







void test_equal_5() {

    set set1 = designer(3, 10000, -20000, 30001);

    set set2 = designer(3, -20000, 10000, 30000);

    do {if (!(equal(&set1, &set2))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(283)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

}







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

    do {if (!(equal(&set1, &set3))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(302)));}} while(0);

    do {if ((equal(&set1, &set2))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(303)));}} while(0);



    delete_set(&set1);

    delete_set(&set2);

    delete_set(&set3);

}







void test_difference_1() {

    set set1 = new_set();

    set set2 = new_set();

    set correct_set = new_set();

    set result_set = difference(&set1, &set2);

    do {if ((equal(&result_set, &correct_set))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(317)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

    delete_set(&result_set);

    delete_set(&correct_set);

}







void test_difference_2() {

    set set1 = new_set();

    set set2 = designer(1, 1);

    set correct_set = new_set();

    set result_set = difference(&set1, &set2);

    do {if ((equal(&result_set, &correct_set))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(331)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

    delete_set(&result_set);

    delete_set(&correct_set);

}







void test_difference_3() {

    set set1 = designer(1, 1);

    set set2 = new_set();

    set correct_set = designer(1, 1);

    set result_set = difference(&set1, &set2);

    do {if ((equal(&result_set, &correct_set))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(345)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

    delete_set(&result_set);

    delete_set(&correct_set);

}







void test_difference_4() {

    set set1 = designer(2, 1, 2);

    set set2 = designer(2, 1, 3);

    set correct_set = designer(1, 2);

    set result_set = difference(&set1, &set2);

    do {if ((equal(&result_set, &correct_set))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(359)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

    delete_set(&result_set);

    delete_set(&correct_set);

}







void test_difference_5() {

    set set1 = designer(4, -2, -5, 6, 7);

    set set2 = designer(5, 8, -10, 6, -5, 0);

    set correct_set = designer(2, -2, 7);

    set result_set = difference(&set1, &set2);

    do {if ((equal(&result_set, &correct_set))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(373)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

    delete_set(&result_set);

    delete_set(&correct_set);

}







void test_difference_6() {

    set set1 = designer(4, -2, -5, 6, 7);

    set set11 = designer(4, -2, -5, 6, 7);

    set set2 = designer(5, 8, -10, 6, -5, 0);

    set set22 = designer(5, 8, -10, 6, -5, 0);

    set result_set = difference(&set1, &set2);

    do {if ((equal(&set1, &set11))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(388)));}} while(0);

    do {if ((equal(&set2, &set22))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(389)));}} while(0);

    delete_set(&set1);

    delete_set(&set11);

    delete_set(&set2);

    delete_set(&set22);

    delete_set(&result_set);

}







void test_stress_difference() {

    set set1 = new_set();

    set set2 = new_set();

    set correct_set = designer(1, 20000);

    add_range(-10000, 9999, &set1);

    add_range(-10000, 9999, &set2);





    add(20000, &set1);

    set result_set = difference(&set1, &set2);

    do {if ((equal(&correct_set, &result_set))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(409)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

    delete_set(&correct_set);

    delete_set(&result_set);

}







void test_copy_1() {

    set set1 = new_set();

    set set2 = copy_set(&set1);

    do {if ((equal(&set1, &set2))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(421)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

}







void test_copy_2() {

    set set1 = designer(1, 1);

    set set2 = copy_set(&set1);

    do {if ((equal(&set1, &set2))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(431)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

}







void test_copy_3() {

    set set1 = designer(5, 1, 6, -2, 29, 0);

    set set2 = copy_set(&set1);

    do {if ((equal(&set1, &set2))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(441)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

}







void test_copy_4() {

    set set1 = designer(5, 1, 6, -2, 29, 0);

    set set2 = copy_set(&set1);

    add(100, &set1);

    do {if (!(equal(&set1, &set2))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(452)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

}







void test_copy_5() {

    set set1 = designer(5, 1, 6, -2, 29, 0);

    set set2 = copy_set(&set1);

    add(100, &set2);

    do {if (!(equal(&set1, &set2))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(463)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

}







void test_stress_copy() {

    set set1 = new_set();

    for (int i = -10000; i < 10000; i++) {

        add(i, &set1);

    }



    set set2 = copy_set(&set1);

    do {if ((equal(&set1, &set2))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(477)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

}







void test_combine_1() {

    set set1 = new_set();

    set set2 = new_set();

    set correct_set = new_set();

    set result_set = combine(&set1, &set2);

    do {if ((equal(&correct_set, &result_set))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(489)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

    delete_set(&correct_set);

    delete_set(&result_set);

}







void test_combine_2() {

    set set1 = designer(1, 1);

    set set2 = designer(1, 2);

    set correct_set = designer(2, 1, 2);

    set result_set = combine(&set1, &set2);

    do {if ((equal(&correct_set, &result_set))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(503)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

    delete_set(&correct_set);

    delete_set(&result_set);

}







void test_combine_3() {

    set set1 = designer(2, 1, 2);

    set set2 = designer(2, 1, 3);

    set correct_set = designer(3, 1, 2, 3);

    set result_set = combine(&set1, &set2);

    do {if ((equal(&correct_set, &result_set))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(517)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

    delete_set(&correct_set);

    delete_set(&result_set);

}







void test_combine_4() {

    set set1 = designer(2, 1, 2);

    set set2 = new_set();

    set correct_set = designer(2, 1, 2);

    set result_set = combine(&set1, &set2);

    do {if ((equal(&correct_set, &result_set))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(531)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

    delete_set(&correct_set);

    delete_set(&result_set);

}







void test_combine_5() {

    set set1 = designer(4, 1, 5, -9, 3);

    set set2 = designer(4, 5, 0, 25, -30);

    set correct_set = designer(7, 1, 5, -9, 3, 0, 25, -30);

    set result_set = combine(&set1, &set2);

    do {if ((equal(&correct_set, &result_set))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(545)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

    delete_set(&correct_set);

    delete_set(&result_set);

}







void test_combine_6() {

    set set1 = designer(4, 1, 5, -9, 3);

    set set11 = designer(4, 1, 5, -9, 3);

    set set2 = designer(4, 5, 0, 25, -30);

    set set22 = designer(4, 5, 0, 25, -30);

    set result_set = combine(&set1, &set2);

    do {if ((equal(&set11, &set1))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(560)));}} while(0);

    do {if ((equal(&set22, &set2))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(561)));}} while(0);

    delete_set(&set1);

    delete_set(&set11);

    delete_set(&set2);

    delete_set(&set22);

    delete_set(&result_set);

}







void test_stress_combine() {

    set set1 = new_set();

    set set2 = new_set();

    set correct_set = new_set();

    set result_set;

    add_range(-10000, 5000, &set1);

    add_range(-5000, 10000, &set2);

    add_range(-10000, 10000, &correct_set);

    result_set = combine(&set1, &set2);

    do {if ((equal(&correct_set, &result_set))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(580)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

    delete_set(&correct_set);

    delete_set(&result_set);

}







void test_intersect_1() {

    set set1 = new_set();

    set set2 = new_set();

    set correct_set = new_set();

    set result_set = intersect(&set1, &set2);

    do {if ((equal(&result_set, &correct_set))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(594)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

    delete_set(&correct_set);

    delete_set(&result_set);

}







void test_intersect_2() {

    set set1 = designer(1, 1);

    set set2 = designer(1, 2);

    set correct_set = new_set();

    set result_set = intersect(&set1, &set2);

    do {if ((equal(&result_set, &correct_set))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(608)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

    delete_set(&correct_set);

    delete_set(&result_set);

}







void test_intersect_3() {

    set set1 = designer(2, 1, 2);

    set set2 = designer(2, 1, 3);

    set correct_set = designer(1, 1);

    set result_set = intersect(&set1, &set2);

    do {if ((equal(&result_set, &correct_set))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(622)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

    delete_set(&correct_set);

    delete_set(&result_set);

}







void test_intersect_4() {

    set set1 = designer(5, 1, 5, 9, -8, -9);

    set set2 = designer(5, 5, -9, 24, -2, 0);

    set correct_set = designer(2, 5, -9);

    set result_set = intersect(&set1, &set2);

    do {if ((equal(&result_set, &correct_set))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(636)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

    delete_set(&correct_set);

    delete_set(&result_set);

}







void test_intersect_5() {

    set set1 = designer(5, 1, 5, 9, -8, -9);

    set set11 = designer(5, 1, 5, 9, -8, -9);

    set set2 = designer(5, 5, -9, 24, -2, 0);

    set set22 = designer(5, 5, -9, 24, -2, 0);

    set result_set = intersect(&set1, &set2);

    do {if ((equal(&set1, &set11))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(651)));}} while(0);

    do {if ((equal(&set2, &set22))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(652)));}} while(0);

    delete_set(&set1);

    delete_set(&set11);

    delete_set(&set2);

    delete_set(&set22);

    delete_set(&result_set);

}







void test_stress_intersect() {

    set set1 = new_set();

    add_range(-10000, 5000, &set1);

    set set2 = new_set();

    add_range(-5000, 10000, &set2);

    set correct_set = new_set();

    add_range(-5000, 5000, &correct_set);

    set result_set = intersect(&set1, &set2);

    do {if ((equal(&result_set, &correct_set))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(670)));}} while(0);

    delete_set(&set1);

    delete_set(&set2);

    delete_set(&correct_set);

    delete_set(&result_set);

}

void add_range(int start, int finish, set *p_set) {

    for (int i = start; i <= finish; i++) {

        add(i, p_set);

    }

}
