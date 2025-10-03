/*
4.	Дан двумерный массив. Определить максимальный номер строки, состоящей только из элементов, кратных числу а.
*/


#include <stdio.h>
#include <conio.h>


#define ROWS 5
#define COLS 3

void fill_array( int array[ROWS][COLS]);
void print_array( int array[ROWS][COLS]);
int check_array( int array[ROWS][COLS], int a);


int main()
{
    int array[ROWS][COLS], a;

    fill_array(array);
    print_array(array);

    printf("Введите a: ");
    scanf("%d", &a);

    int max = check_array(array, a);
    if (max != -1) {
        printf("Максимальный номер строки, в которой все элементы кратны a(%d) == %d", a, max);
    } else {
        printf("В массиве нет строки, все элементы которой кратны a(%d)", a);
    }
    return 0;

}


void fill_array(int array[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("A[%d][%d] = ", i+1, j+1);
            scanf("%d", &array[i][j]);
        }
        printf("\n");
    }
}

void print_array(int array[ROWS][COLS])
{
    printf("\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("\t%d", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int check_array(int array[ROWS][COLS], int a)
{
    int max = -1;
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        int count_nums = 0;

        for (j = 0; j < COLS; j++)
        {
            if (array[i][j] % a == 0) {
                count_nums += 1;
            }
        }

        if (count_nums == COLS) {
            max = i+1;
        }
    }

    return max;
}