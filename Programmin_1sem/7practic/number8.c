/*
8.	В каждом столбце двумерного массива поменять местами первый отрицательный элемент и последний нулевой
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define COLS 5
#define ROWS 5

int main()
{
    int array[ROWS][COLS];

    // заполняем массив
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            array[i][j] = rand() % 20 - 10;
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


    // замена
    for (int i = 0; i < COLS; i++)
    {
        int minus_numb = 0;
        int index[2] = {0, 0};
        short flag = 0;

        for (int j = 0; j < ROWS; j++)
        {
            if (array[j][i] < 0 && !flag) {
                minus_numb = array[j][i];
                array[j][i] = 0;
                flag = 1;
            }

            if (array[j][i] == 0) {
                index[0] = j;
                index[1] = i;
            }
        }
        if (flag) {
            array[index[0]][index[1]] = minus_numb;
        }
    }



    printf("\n\n");
    // вывод массива 
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("\t%d", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}   