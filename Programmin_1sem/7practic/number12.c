/*12.	
Определить, является ли квадратный массив магическим квадратом, 
то есть массивом, в котором суммы элементов во всех строках, 
столбцах и на обеих диагоналях одинаковы
*/


#include <stdio.h>


#define SIDE 3

void check(int array[SIDE][SIDE]);


int main()
{
    int array[SIDE][SIDE] = {
        {2, 2, 2},
        {2, 2, 2},
        {2, 2, 2}
    };
    
    int array2[SIDE][SIDE] = {
        {2, 3, 2},
        {2, 3, 2},
        {3, 2, 2}
    };

    int array3[SIDE][SIDE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    printf("           ---array1---\n");
    check(array);
    printf("\n\n");

    printf("           ---array2---\n");
    check(array2);
    printf("\n\n");

    printf("           ---array3---\n");
    check(array3);

    return 0;
}


void check(int array[SIDE][SIDE])
{
    int sum_el[SIDE+SIDE+2] = {0};
    // 0 -> SIDE-1 - Суммы строк (c 0 до SIDE-1)
    // SIDE -> SIDE+SIDE-1 - суммы столбцов (с 0 до SIDE-1)
    // SIDE+SIDE -> SIDE+SIDE+1 - суммы диагоналей (главная, побочная)


    // считаем сумму 
    int k = SIDE;
    for (int i = 0; i < SIDE; i++) 
    {
        k -= 1;
        for (int j = 0; j < SIDE; j++)
        {
            sum_el[i] += array[i][j]; // строка
            sum_el[SIDE+j] += array[i][j]; // столбец
        }
        sum_el[SIDE+SIDE] += array[i][i]; // главная диагональ
        sum_el[SIDE+SIDE+1] += array[i][k]; // побочная диаггональ
    }


    // вывод
    for (int i = 0; i < SIDE+SIDE+2; i++)
    {
        if (i < SIDE) {
            printf("Сумма эл-ов %d-ой строки = %d\n", i+1, sum_el[i]);
        } else if (i < SIDE + SIDE) {
            printf("Сумма эл-ов %d-го столбца = %d\n", i+1-SIDE, sum_el[i]);
        } else if (i == SIDE + SIDE) {
            printf("Сумма эл-ов главной диагонали = %d\n", sum_el[i]);
        } else {
            printf("Сумма эл-ов побочной диагонали = %d\n", sum_el[i]);
        }
    }

    // проверка 
    int count = 1;
    for (int i = 0; i < SIDE+SIDE+1; i++)
    {
        if (sum_el[i] == sum_el[i+1]) {
            count += 1;
        }
    }

    if (count == SIDE+SIDE+2) {
        printf("Массив является магическим квадратом.\n");
    } else {
        printf("Массив не является магическим квадратом.\n");
    }
}