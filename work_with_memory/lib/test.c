#include "include/memory.h"
#include <stdio.h>


int main() {
    put("x", 11);
    printf("realno?\n");
    printf("%d\n", get("x"));
    put("1", -5);
    printf("realno?\n");
    printf("%d\n", get("1"));
    put("data", 7);
    printf("realno?\n");
    printf("%d\n", get("x"));
    printf("%d\n", get("data"));
    printf("%d\n", get("1"));
    printf("%d\n", get("data"));
    putarr("array", 0, 5);
    printf("%d\n", getarr("array", 0));
    putarr("array", 1, 6);
    printf("%d\n", getarr("array", 1));
    printf("%d\n", getarr("array", 2));
    printf("%d\n", getarr("array", -5));
    printf("\n\n\n\n\n\n\n\n");
    putarr("array2", 2, 13);
    printf("%d\n", getarr("array2", 0));
    printf("%d\n", getarr("array2", 1));
    printf("%d\n", getarr("array2", 2));
    printf("%d\n", getarr("ar", 2));
    printf("\n\n\n\n");
    put("x", 55);
    printf("%d\n", get("x")); //?
    putarr("array", 0, -127);
    printf("%d\n", getarr("array", 0)); //?
    clear_memory();
    printf("eee\n");
    /////////////////////////////////////////////
    put("x", 8);
    delete("x");
    printf("%d\n", get("x"));
    put("1", 1);
    put("2", 2);
    put("3", 3);
    put("-1", -1);
    put("-2", -2);
    delete("2");
    printf("%d\n", get("1"));
    printf("%d\n", get("2"));
    printf("%d\n", get("3"));
    printf("%d\n", get("-1"));
    printf("%d\n", get("-2"));
    putarr("array", 0, 1);
    printf("%d\n", getarr("array", 0));
    putarr("array", 1, 2);
    printf("%d\n", getarr("array", 0));
    delete("array");
    printf("%d\n", getarr("array", 0));
    printf("%d\n", getarr("array", 1));
    putarr("array", 4, 4);
    printf("%d\n", getarr("array", 3));
    clear_memory();
    return 0;
}