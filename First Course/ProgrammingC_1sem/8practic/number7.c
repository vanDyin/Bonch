//6. Сумма элементов побочной диагонали


#include <stdio.h>
#include <malloc.h>

#define ROWS 4
#define COLS 4

int main()
{

    int **array, sum = 0, count = ROWS;
    array = (int**) malloc(ROWS*sizeof(int*));

    for (int i = 0; i < ROWS; i++)
    {
        count -= 1;
        array[i] = (int*) malloc(COLS*sizeof(int));
        for (int j = 0; j < COLS; j++)
        {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &array[i][j]);
        }

        sum += array[i][count];
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

    printf("Сумма элементов побочной диагонали = %d", sum);

    return 0;
}