#include "count_str.h"

//Узнать размер файла, ftell, //fseek 
//Создать буффер, прочитать файл в этот буфер
//count_str, которая работает по буфферу

size_t count_str(FILE* text) {

    size_t count = 0;
    const int num = 1000;

    // int c = 0;
    // while ((c = fgetc(text)) != NULL) {
    //     if (c == '\n')
    //         count++
    // }

    // char* s = (char* ) calloc((size_t) num, sizeof(char));
    char s[num];

    while ((my_fgets(s, num , text)) != NULL) {
        count++;
    }

    // free(s);
    return count;
}

char *my_fgets(char* str, int num, FILE *stream) {
    int c = fgetc(stream);
    int count = 0;

    for (; c != '\0' && c != EOF && count < num; count++) {
        *str = c;
        c = fgetc(stream);
        *str++;
    }
    *str = '\0';

    return str - count;
}