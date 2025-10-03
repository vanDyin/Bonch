/*
7.В квадратном массиве выделим четыре четверти, 
ограниченные главной и побочной диагоналями (без учета элементов, расположенных на диагоналях).
Найти сумму элементов верхней четверти*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define SIDE 7

int main()
{
    int array[SIDE][SIDE], sum;

    // заполняем массив
    srand(time(NULL));
    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            array[i][j] = rand() % 500; // промежуток от 0 до 500 (не включая)
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

    // подсчёт
    printf("Сумма элементов верхней четверти:\n");
    for (int i = 0; i < SIDE; i++) 
    {
        for (int j = 0; j < SIDE; j++)
        {
            if (j > i && SIDE-i-1 > j) {
                printf("%d + ", array[i][j]);
                sum += array[i][j];
            }
        }
    }
    // результат
    printf("0 = %d", sum);
    return 0;
}