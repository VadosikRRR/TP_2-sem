#include <stdio.h>
#include "lib/string.h"


int main() {
    string str1 = new_string("abcd123a");
    char *p = string_chr('u', &str1);
    if (!p) {
        printf("eee\n");
    }
    else {
        printf("%c\n", *p);
    }
    
    
    print_str(&str1);
    //printf("%c\n", str1.p_data[str1.length]);
    printf("%d\n", str1.length);
    string str2 = new_string_with_length("4567as", 10);
    print_str(&str2);
    printf("%d\n", str2.length);
    string str3 = cat(&str1, &str2);
    print_str(&str3);
    printf("%d\n", str3.length);
    string str4 = substring(&str1, 4, 3);
    print_str(&str4);
    string str5 = new_string("");
    string str6 = new_string("");
    printf("%d\n", string_cmp(&str5, &str6));
    array_string array_str = split('a', &str2);

    delete_string(&str1);
    delete_string(&str2);
    delete_string(&str3);
    delete_string(&str4);
    delete_string(&str5);
    delete_string(&str6);
    delete_array_string(&array_str);
    return 0;
}
