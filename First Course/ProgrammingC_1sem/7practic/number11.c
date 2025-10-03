/*
11.	Для каждой строки двумерного массива выяснить количество элементов,
последняя цифра которых равна а*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 5

int main()
{
    int array[ROWS][COLS], count_el[ROWS], a;

    // заполняем массив
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            array[i][j] = rand() % 500; // промежуток от 0 до 500
        }
        count_el[i] = 0;
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

    // запрос a
    printf("Введите a -> ");
    scanf("%d", &a);

    // Проверка строк массива
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (array[i][j] % a == 0) {
                printf("\t+%d", array[i][j]);
                count_el[i] += 1;
            } else {
                printf("\t%d", array[i][j]);
            }
        }
        printf("\t\t%d", count_el[i]);
        printf("\n");
    }

    return 0;
}