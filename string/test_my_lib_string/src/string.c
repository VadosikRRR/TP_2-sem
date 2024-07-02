#include <stdlib.h>
#include <stdio.h>
#include "string.h"


string new_string(char *p_data) {
    string new_string;
    new_string.length = string_length(p_data);
    new_string.p_data = (char *)malloc((new_string.length + 1) * sizeof(char)); //malloc
    for (int i = 0; i < new_string.length + 1; i++) {
        new_string.p_data[i] = p_data[i];
    }
    
    return new_string;
}


string new_string_with_length(char *p_data, int length) {
    string new_string;
    int data_length = string_length(p_data);
    new_string.length = length > data_length ? data_length : length;
    new_string.p_data = (char *)malloc((new_string.length + 1) * sizeof(char));
    for (int i = 0; i < new_string.length; i++) {
        new_string.p_data[i] = p_data[i];
    }
    
    new_string.p_data[new_string.length] = '\0';
    return new_string;
}


int string_length(char *p_data) {
    int i = 0;
    while (p_data[i] != '\0') {
        i++;
    }

    return i;
}


string cat(string *p_str1, string *p_str2) {
    string result_string;
    result_string.length = p_str1->length + p_str2->length;
    result_string.p_data = (char *)malloc((result_string.length + 1) * sizeof(char));
    for (int i = 0; i < p_str1->length; i++) {
        result_string.p_data[i] = p_str1->p_data[i];
    }
    
    for (int i = 0; i < p_str2->length + 1; i++) {
        result_string.p_data[i + p_str1->length] = p_str2->p_data[i];
    }

    return result_string;
}


string substring(string *p_str, int index_beginning_substring, int length_substring) {
    string result_string = new_string_with_length(p_str->p_data + index_beginning_substring, length_substring);
    return result_string;
}


void print_str(string *p_str) {
    for (int i = 0; i < p_str->length; i++) {
        printf("%c", p_str->p_data[i]);
    }
    
    printf("\n");
}


char *string_chr(char symbol, string *p_str) {
    for (int i = 0; i < p_str->length; i++) {
        if (p_str->p_data[i] == symbol) {
            return p_str->p_data + i;
        }
    }
    
    return NULL;
}


char *string_rchr(char symbol, string *p_str) {
    for (int i = p_str->length - 1; i >= 0; i--) {
        if (p_str->p_data[i] == symbol) {
            return p_str->p_data + i;
        }
    }
    
    return NULL;
}


int string_cmp(string *p_str1, string *p_str2) {
    for (int i = 0; i < p_str1->length; i++) {
        if (i >= p_str2->length) {
            return 1;
        }
        
        if (p_str1->p_data[i] > p_str2->p_data[i]) {
            return 1;
        }
        else if (p_str1->p_data[i] < p_str2->p_data[i]) {
            return -1;
        }
    }

    if (p_str1->length < p_str2->length) {
        return -1;
    }

    return 0;
}


int string_c_cmp(string *p_str, char *p_data) {
    int length_array_char = string_length(p_data);
    for (int i = 0; i < p_str->length; i++) {
        if (i > length_array_char) {
            return 1;
        }
        
        if (p_str->p_data[i] > p_data[i]) {
            return 1;
        }
        else if (p_str->p_data[i] < p_data[i]) {
            return -1;
        }
    }

    if (p_str->length < length_array_char) {
        return -1;
    }

    return 0;
}


array_string split(int symbol, string *p_str) {
    // Суть такая, проходим и считаем сколько всего встретилось символов разделителей, не считая те, которые делят на пустые строки.
    // После создаём массив строк такой длины и (в конце можно добавить чисто пустую строку для понимания, что является концом)
    // Или передать переменную int по указателю и в неё записать длину, но не знаю
    // После идём до символа разделителя (подходящего), создаём подстроки и кладём в массив.
    int have_another_symbols = 0;
    for (int i = 0; i < p_str->length; i++) {
       if (p_str->p_data[i] != symbol) {
            have_another_symbols = 1;
        }
    }

    if (!have_another_symbols) {
        array_string array_str;
        array_str.length = 1;
        array_str.p_data = (string *)malloc(sizeof(string));
        array_str.p_data[0] = new_string("");
        return array_str;
    }
    
    int cnt = 0;
    for (int i = 0; i < p_str->length; i++) {
        if (p_str->p_data[i] == symbol) {
            cnt++;
            while (i < p_str->length && p_str->p_data[i + 1] == symbol) {
                i++;
            }        
        }
    }

    int index_beginning = 0;
    array_string array_str;
    array_str.length = cnt + 1;
    array_str.p_data = (string *)malloc(array_str.length * sizeof(string));
    for (int i = 0, k = 0; i < p_str->length; i++) {
        if (p_str->p_data[i] != symbol) {
            continue;
        }

        array_str.p_data[k++] = substring(p_str, index_beginning, i - index_beginning);
        while (i < p_str->length - 1 && p_str->p_data[i + 1] == symbol) {
            i++;
        }

        index_beginning = i + 1;
    }

    array_str.p_data[array_str.length - 1] = substring(p_str, index_beginning, p_str->length - index_beginning);
    return array_str;
}


void delete_string(string *p_str) {
    free(p_str->p_data);
}


void delete_array_string(array_string *array_str) {
    for (int i = 0; i < array_str->length; i++) {
        delete_string(array_str->p_data + i);
    }

    free(array_str->p_data);
}
