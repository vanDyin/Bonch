/*
9.
Дан двумерный массив размером n х n.
Сформировать одномерный массив из элементов заданного массива,
расположенных на побочной диагонали.
*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIDE 5

int main()
{
    int array[SIDE][SIDE];
    int res_array[SIDE];
    // заполняем массив
    srand(time(NULL));
    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            array[i][j] = rand() % 500; // промежуток от 0 до 500
        }
    }

    // вывод массива 
    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            printf("\t%d", array[i][j]);
        }
        printf("\n");

    }

    printf("\n");

    // ищем поб диаг
    for (int i = SIDE-1; i >= 0; i--)
    {
        res_array[SIDE-1-i] = array[SIDE-1-i][i]; 
    }

    // вывод результат
    for (int i = 0; i < SIDE; i++)
    {
        printf("res[%d] = %d\n", i, res_array[i]);
    }

    return 0;
}