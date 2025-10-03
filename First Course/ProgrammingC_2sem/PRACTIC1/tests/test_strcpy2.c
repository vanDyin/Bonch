#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void main () 
{
    char buffer[128];
    char *word = NULL;
    char *other = NULL;

    scanf("%127s", buffer);
    word = (char*) malloc(strlen(buffer)+1);
    
    other = strcpy(word, buffer);
    printf("%s", other);

    free(other);
}
