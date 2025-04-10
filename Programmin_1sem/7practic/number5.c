/*
5.	Определить, есть ли в двумерном массиве столбец,
в котором равное количество положительных и отрицательных элементов
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define ROWS 4
#define COLS 3

int main()
{
    int array[ROWS][COLS];
    int count[COLS][2] = {0, 0}; // первая ячейка кол-во отрицательных / вторая ячейка кол-во положительных


    // заполняем массив
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            //printf("A[%d][%d] = ", i+1, j+1);
            //scanf("%d", &array[i][j]);

            array[i][j] = rand() % 200 - 100; // промежуток от -100 до 100
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

    printf("\n");

    // считаем кол-во +- элементов
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (array[i][j] > 0) {
                count[j][1] += 1;
            } else if (array[i][j] < 0) {
                count[j][0] += 1;
            }
        }
    }

    int k, flag = 0;

    // определяем нужные столбцы
    for (k = 0; k < COLS; k++)
    {
        if (count[k][0] == count[k][1])
        {
            flag = 1;
            goto exit;
        }
    }

    exit:
        if (flag) {
            printf("Есть, например столбец №%d.", k+1);
        } else {
            printf("В массиве нет такого столбца.");
        }
        return 0;
}
