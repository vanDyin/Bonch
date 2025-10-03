#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

void main () 
{
    char buffer[128];
    char *word = NULL;

    scanf("%127s", buffer);
    word = (char*) malloc(strlen(buffer)+1);

    strcpy(word, buffer);
    printf("%s", word);
    
    free(word);
}

// strcpy - Копирует одну строку в другую, вместе с нулевым символом. Также возвращает указатель на destination