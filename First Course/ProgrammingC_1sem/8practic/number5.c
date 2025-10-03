// Максимальный в каждом столбце

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


#define ROWS 3
#define COLS 5

int main()
{

    int **dyn_array, max[COLS] = {0};
    dyn_array = (int**) malloc(ROWS*sizeof(int*));

    for (int i = 0; i < ROWS; i++)
    {
        dyn_array[i] = (int*) malloc(COLS*sizeof(int));
        for(int j = 0; j<COLS; j++)
        {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &dyn_array[i][j]);
            if (max[j] < dyn_array[i][j]) {
                max[j] = dyn_array[i][j];
            }
        }
    }

    printf("\n----------------------\n\n");

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("\t%d", dyn_array[i][j]);
        }
        printf("\n");
    }

    printf("\n----------------------\n\n");

    for (int i = 0; i < COLS; i++)
    {
        printf("Максимальный элемент %d-ого столбца = %d.\n", i+1, max[i]);
    }

    free(dyn_array);

    return 0;
}