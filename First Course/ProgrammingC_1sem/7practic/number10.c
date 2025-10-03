/*
10.	Дан двумерный массив. Найти номера двух соседних столбцов,
сумма элементов в которых минимальна
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 5

int main()
{
    int array[ROWS][COLS], sum[COLS];

    // заполняем массив
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            sum[j] = 0;
            array[i][j] = rand() % 500; // промежуток от 0 до 500
        }
    }

    // вывод массива 
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("\t%d", array[i][j]);
        }
        printf("\n");
    }

    // считаем сумму столбцов
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            sum[j] += array[i][j];
        }
    }

    printf("\n");
    // вывод суммы 
    for (int i = 0; i < COLS; i++)
    {
        printf("\t%d", sum[i]);
    }
    printf("\n");


    int min = UINT_MAX, index = 0;
    // ищем столбцы
    for (int i = 0; i < COLS - 1; i++)
    {
        if (sum[i] + sum[i+1] < min) {
            min = sum[i] + sum[i+1];
            index = i;
        }
    }

    printf("Смежные столбцы с минимальными суммами элементов - это %d и %d (суммы %d и %d)", index+1, index+2, sum[index], sum[index+1]);

    return 0;

}