#include <stdio.h>
#include <string.h>

void main() 
{
    char str[] = "I'll drown my beliefs\n"
                 "To have you be in peace\n"
                 "I'll dress like your niece\n"
                 "And wash your swollen feet\n";
    
    char niece[] = "niece";
    char* p = strstr(str, niece);
    printf("%s", p);
}

// Возвращает указатель на первое вхождение строки str2 в строку str1 