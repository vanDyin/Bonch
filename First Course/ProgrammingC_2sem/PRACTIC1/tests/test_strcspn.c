#include <stdio.h>
#include <conio.h>
#include <string.h>
void main() 
{   char str[] = "So if you want to love me\n"
                 "Then darling don't refrain\n"
                 "Or I'll just end up walking\n"
                 "In the cold November rain\n";
    char vowels[] = "aeiouy";
    int i;
    i = 0;
    while (str[i]) 
    {   
        i = i + strcspn(&str[i], vowels);
        printf("%d ", i);
        i++;
    }
}


/*
size_t strcspn ( const char * str1, const char * str2 );
Возвращает адрес первого вхождения любой буквы из строки str2 в строке str1. 
Если ни одно включение не найдено, то возвратит длину строки.

char* strpbrk (char * str1, const char * str2)
Функция очень похожа на strcspn, только возвращает указатель на первый символ из строки str1, который есть в строке str2. 

char* strrchr (char * str, int character );
Возвращает указатель на последнее вхождение символа в строку.

size_t strspn (const char * str1, const char * str2);
Возвращает длину куска строки str1, начиная от начала, который состоит только из букв строки str2

*/