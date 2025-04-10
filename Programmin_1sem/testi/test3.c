#include <stdio.h>


void main()
{
    int a, b;
    a = b = 5;
    char str[] = {'h', 'e', 'l', 'l', 'o', '\0'};

    for (int i = 0; i < 7; i++)
    {
        printf("%d\n", str[i]);
    }
    printf("%s\n", str);
}