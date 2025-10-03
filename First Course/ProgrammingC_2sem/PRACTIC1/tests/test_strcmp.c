/* сортировка массива строк по первым трём символам */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) 
{
    return strncmp((char*) a, (char*) b, 3);
}

void main() {
    int i;
    char words[5][79] = { 
        "Solar",
        "Obscurus",
        "Tempestus",
        "Ultima",
        "Pacificus"
    };

    for (i = 0; i < 5; i++) { 
        printf("%s\n", words[i]);
    }

    qsort(words, 5, 80, cmp);
    printf("\n");

    for (i = 0; i < 5; i++) {
        printf("%s\n", words[i]);
    }
}

/*
int strcmp (const char * str1, const char * str2);
Возвращает 0, если строки равны, больше нуля, если первая строка больше, меньше нуля, если первая строка меньше. 
Сравнение строк происходит посимвольно, сравниваются численные значения. 


Cравнение строк по первым num символам:
int strncmp (const char * str1, const char * str2, size_t num);


Для сравнения строк на определённом языке используется strcoll:
int strcoll (const char * str1, const char * str2);


void qsort ( void * first, size_t number, size_t size, int ( * comparator ) ( const void *, const void * ) );
Эта функция не возвращает никакого значения, но изменяет содержимое массива, на который указывает first. Таким образом, элементы массива занимают новые места, согласно отсортированному порядку.
Функция qsort библиотеки stdlib.h выполняет сортировку num элементов массива, на который ссылается указатель first.

*/