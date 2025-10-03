#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void freeMemory(int ***matrix, int size) {
    for (int i = 0; i < size; i++) {
        free((*matrix)[i]);
    }

    free(*matrix);
}