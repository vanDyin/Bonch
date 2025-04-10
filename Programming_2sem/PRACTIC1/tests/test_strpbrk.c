#include <stdio.h>
#include <string.h>


void main() 
{
    char str[] = "Cos' it's a bittersweet symphony this life...\n"
                 "Trying to make ends meet, you're a slave to the money then you die.";
    char vowels[] = "aeiouy";
    char *p = NULL;
    p = strpbrk(str, vowels);
    while (p) {   
        printf("%c ", *p);
        p++;
        p = strpbrk(p, vowels);
    }
    getch();
}

// Функция очень похожа на strcspn, только возвращает указатель на первый символ из строки str1, который есть в строке str2. 