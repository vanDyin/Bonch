#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 128

void getMatrix(int ***matrix, FILE *file, int size[2]) {

    if (fscanf(file,"%d %d", &size[0], &size[1]) != 2) { 
        printf("Error at the scan of <n> and <m>.\n");
        exit(1);
    }

    *matrix = (int**) malloc(size[0]*sizeof(int*)); 
    if (*matrix == NULL) {
        printf("Memory allocation failed(**array)\n");
        exit(1);
    }

    for (int i = 0; i < size[0]; i++) {
        (*matrix)[i] = (int*) malloc(size[1]*sizeof(int)); 

        if ((*matrix)[i] == NULL) {
            printf("Memory allocation failed(*array)\n");
            exit(1);
        }

        for (int j = 0; j < size[1]; j++) {
            if (fscanf(file, "%d ", &(*matrix)[i][j]) != 1) {
                printf("Error reading matrix element at [%d][%d]\n", i, j);
                exit(1);
            }
        }
    }
}


void createNewFile(int **matrix, int n, int m) {
    FILE *file;
    char filename[LEN];

    printf("Enter a new filename with extension -> ");
    fgets(filename, LEN-1, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    file = fopen(filename, "w");

    for (int i = 0; i < n; i++) {
        char flag = 0;

        for (int j = 0; j < m; j++) {
            if (matrix[i][j] < 0) {
                flag = 1;
                break;
            }
        }

        if (!flag) {
            for (int j = 0; j < m; j++) {
                fprintf(file, "%d ", matrix[i][j]);
            }
            fprintf(file, "\n");
        }
    }


    fclose(file);

}


void freeMemory(int ***matrix, int size) {
    for (int i = 0; i < size; i++) {
        free((*matrix)[i]);
    }

    free(*matrix);
}


int main() {
    int **matrix = NULL, size[2];
    FILE *file;
    char filename[LEN];

    printf("Enter a filename with extension -> ");
    fgets(filename, LEN-1, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    file = fopen(filename, "r");
    getMatrix(&matrix, file, size);
    fclose(file);
    
    createNewFile(matrix, size[0], size[1]);

    freeMemory(&matrix, size[0]);
    return 0;
}
