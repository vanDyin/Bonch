#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define LEN 20


int* getMatrixSize(FILE *file) {
    int size[2];
    int result = fscanf(file,"%d %d", &size[0], &size[1]);
    getchar();

    if (result != 2) {
        printf("Error at the scan of <n> and <m>.\n");
        exit(1);
    }

    return size;
}

void freeMemory(int **matrix, int n) {
    for (int i = 0; i<n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int* createMatrix(int ***matrix, int* (func)(FILE*), FILE* file) {
    int size[2] = func(file);

    *matrix = (int**) malloc (size[0]*sizeof(int*));
    for (int i = 0; i < size[0]; i++) {
        (*matrix)[i] = (int*) malloc (size[1]*sizeof(int));
    }

    return size;
}

char* getFormat(int n) {
    char *result = (char*) malloc(n*3);
    result[0] = '\0';

    for (int i = 0; i<n-1; i++) {
        strcat(result, "%d ");
    }

    strcat(result, "%d");
    return result;
}

void editMatrix(int **matrix, int ***newMatrix, int *sizeMatrix) {
}

int main() {
    char filename[LEN] = "";
    char *buffer = (char*) malloc(LEN);
    int *size = (int*) malloc(2*sizeof(int));
    int **matrix, **newMatrix;
    FILE *file;

    printf("Enter a filename with extension -> ");
    fgets(buffer, LEN-1, stdin);
    strcpy(filename, buffer);
    free(buffer);

    file = fopen(filename, "r");
    size = createMatrix(&matrix, getMatrixSize, file);

    editMatrix(matrix, &newMatrix, size);
    


    freeMemory(matrix, size[0]);
    return 0;
}

/*
В файле хранится числовая матрица. В первой строке файла записаны два числа:
количество строк и столбцов матрицы, а затем сама матрица. Сформировать новый файл,
содержащий только те строки исходной матрицы, в которых отсутствуют отрицательные числа.
*/