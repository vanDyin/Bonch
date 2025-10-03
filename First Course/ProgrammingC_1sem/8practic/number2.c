// Сумма всех элементов

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


#define ROWS 3
#define COLS 5

int main()
{

    int **dyn_array, sum = 0;
    dyn_array = (int**) malloc(ROWS*sizeof(int*));

    for (int i = 0; i < ROWS; i++)
    {
        dyn_array[i] = (int*) malloc(COLS*sizeof(int));
        for(int j = 0; j<COLS; j++)
        {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &dyn_array[i][j]);
            sum += dyn_array[i][j];
        }
    }

    free(dyn_array);
    
    printf("Сумма всех элементов массива = %d\n", sum);
    return 0;
}