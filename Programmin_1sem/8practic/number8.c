//6. Сумма элементов выше элементов главной диагонали

#include <stdio.h>
#include <malloc.h>

#define ROWS 5
#define COLS 5

int main()
{

    int **array, sum = 0;
    array = (int**) malloc(ROWS*sizeof(int*));

    for (int i = 0; i < ROWS; i++)
    {
        array[i] = (int*) malloc(COLS*sizeof(int));
        for (int j = 0; j < COLS; j++)
        {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &array[i][j]);
            if (j > i) {
                sum += array[i][j];
            }
        }

    }

    printf("\n\n");

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("\t%d", array[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    free(array);

    printf("Сумма элементов выше главной диагонали = %d", sum);

    return 0;
}