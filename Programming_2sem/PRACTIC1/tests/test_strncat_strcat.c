#include <stdio.h>
#include <string.h>


void main () 
{
    char a[80];
    char b[80];

    scanf("%s", a);
    scanf("%s", b);

    strncat(a, b, strlen(b)/2);
    printf("%s", a);
    
}

/*
char* strcat (char * destination, const char * source);
Добавляет в конец destination строку source, при этом затирая первым символом нулевой. Возвращает указатель на destination.

char* strncat (char * destination, const char * source, size_t num);
Добавляет в конец строки destination количество num символов второй строки. В конец добавляется нулевой символ.
*/