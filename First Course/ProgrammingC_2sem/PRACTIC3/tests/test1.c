#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    int n = 4;
    char *result = (char*) malloc(n*3);
    result[0] = '\0';
    for (int i = 0; i<n-1; i++) {
        strcat(result, "%d ");
    }

    strcat(result, "%d");

    printf("%s, %d", result, strlen(result));
    free(result);
    return 0;
}