#ifndef __STRING__
#define __STRING__

typedef struct string {
    char *p_data;
    int length;
} string;

typedef struct array_string {
    int length;
    string *p_data;
} array_string;

int string_length(char *p_data); //?
string new_string(char *p_data); //
string new_string_with_length(char *p_data, int length);
string cat(string *p_str1, string *p_str2); //
string substring(string *p_str, int index_beginning_substring, int length_substring); //
void print_str(string *p_str);
char *string_chr(char symbol, string *p_str); // Возащает указатель на строку, в которой указатель указывает на содержание исходной строки
char *string_rchr(char symbol, string *p_str);// Возащает указатель на строку, в которой указатель указывает на содержание исходной строки
int string_cmp(string *p_str1, string *p_str2); //
int string_c_cmp(string *p_str, char *p_data); //
array_string split(int symbol, string *p_str);
void delete_string(string *p_str);
void delete_array_string(array_string *array_str);

#endif
