#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void main() 
{
    char str[] = "Hello World!";
    char *ptr = NULL;

    printf("%s\n", str);
    ptr = (char*) memchr(str, '\0', 4000);

    if (ptr != NULL) {
        printf("first zero byte address is %p, strlen = %d", ptr, ptr - str);
    } else {
        printf("no null byte in memory block");
    }
}

/*
void* memchr (void * ptr, int value, size_t num);
Проводит поиск среди первых num байтов участка памяти, на который ссылается ptr, первого вхождения значения value, которое трактуется как unsigned char. 
Возвращает указатель на найденный элемент, либо NULL.


char* strchr (char * str, int character);
Возвращает указатель на место первого вхождения character в строку str. 
Очень похожа на функцию memchr, но работает со строками, а не с произвольным блоком памяти

*/