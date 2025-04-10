#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>


void main() 
{
    char str[] = "on 21st of May";
    char nums[] = "0123456789";
    char number[10];

    uintptr_t i; //uintptr_t - целочисленный тип без знака, который может хранить указатель данных
    //
    // size_t - используется для индексации массива и подсчета циклов , целочисленный тип данных без знака
    size_t start = strcspn(str, nums); //Определяем, где начинаются цифры, strcspn возвращает адрес первого вхождения любой буквы из стр2 в стр1
    size_t end = strspn(&str[start], nums); // Определяем, где они заканчиваются, относительно start

    for (i = 0; i < end; i++) {
        printf("%c", str[start+i]);
    }
}

// Возвращает длину куска строки str1, начиная от начала, который состоит только из букв строки str2.