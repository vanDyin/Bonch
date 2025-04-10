/*
2.	Определить координаты (индексы) элемента, наиболее близкого к среднему значению всех элементов массива.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define SIZE 10
#define MAX_LENGTH 10

void generate_array(unsigned char array[SIZE][MAX_LENGTH]);
void print_array(unsigned char array[SIZE][MAX_LENGTH]);

int main()
{
    unsigned char array[SIZE][MAX_LENGTH];
    double middle;
    int sum=0;
    double cur_dif, min_diff = 10.0;
    unsigned char coord[2];
    unsigned char need_numb = 0; 


    generate_array(array);
    print_array(array);

    for (int k = 0; k < SIZE; k++) 
    {
        for (int l = 0; l < MAX_LENGTH; l++)
        {
            sum += array[k][l];
        }
    }
    middle = (double)(sum/(SIZE*MAX_LENGTH));

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < MAX_LENGTH; j++)
        {
            cur_dif = abs(middle-array[i][j]);
            if (cur_dif < min_diff)
            {
                need_numb = array[i][j];
                min_diff = cur_dif;
                coord[0] = i+1;
                coord[1] = j+1;
            }
        }
    }  

    printf("Самое близкое значение к среднему (%.4f) = %d (%d ряд, %d элемент)", middle, need_numb, coord[0], coord[1]);

    return 0;
}


void generate_array(unsigned char array[SIZE][MAX_LENGTH])
{
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < MAX_LENGTH; j++)
        {
            array[i][j]= rand();
        }
    }

    printf("Успешное создание масива.\n");
}

void print_array(unsigned char array[SIZE][MAX_LENGTH])
{
    printf("\n");
    printf("     1    2    3    4    5    6    7    8    9    10\n");
    printf("\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d) ", i+1);
        for (int j = 0; j < MAX_LENGTH; j++)
        {
            printf("%4d ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}