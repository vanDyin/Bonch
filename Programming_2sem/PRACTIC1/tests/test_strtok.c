#include <stdio.h>
#include <string.h>


void main() 
{
    char str[] = "After working in India during the late 1970s and 1980s, "
        "Shankar's profile in the West began to rise again in the mid-1990s "
        "as his music found its way into club DJ sets, particularly in London.";
    
    char delim[] = " \t\n,.-";
    char *p = strtok(str, delim);

    while (p != NULL) {
        printf ("%s\n",p);
        p = strtok (NULL, delim);
    }
}

/*
Разбивает строку на токены. 
В данном случае токенами считаются последовательности символов, разделённых символами, входящими в группу разделителей.
*/