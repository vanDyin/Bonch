#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void main () 
{
    char word[] = "Aloha, Hawaii";
    char aloha[20];
    char hawaii[20];

    printf("%s", word);
    strncpy(aloha, word, 5);
    aloha[5] = 0;

    strncpy(hawaii, &word[7], 7);
    hawaii[7] = 0;

    printf("\n%s, %s", aloha, hawaii);
}

// strncpy - Копирует только num первых букв строки. 0 в конец не добавляется автоматически
