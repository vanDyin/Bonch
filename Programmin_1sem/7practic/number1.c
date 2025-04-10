/*1.	Дан двумерный массив. Найти минимальную сумму элементов строки */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define SIZE 10
#define MAX_LENGTH 10

void generate_array(int array[SIZE][MAX_LENGTH]);
void print_array(int array[SIZE][MAX_LENGTH], int lens[SIZE]);



int main()
{
    int array[SIZE][MAX_LENGTH];
    int lens[SIZE];
    short index, choice = 100;
    int min_sum = 10000;
    int cur_sum;
    generate_array(array);
    


    for (int i = 0; i < SIZE; i++) 
    {
        cur_sum = 0;
        
        for (int j = 0; j < MAX_LENGTH; j++)
        {
            cur_sum += array[i][j];
        }

        lens[i] = cur_sum;
        if (cur_sum < min_sum)
        {
            min_sum = cur_sum;
            index = i+1;
        }   
    }
    
    print_array(array, lens);

    printf("Минимальная сумма элементов строки = %d ( %d строка ).\n", min_sum, index);
    return 0;


}


void generate_array(int array[SIZE][MAX_LENGTH])
{
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < MAX_LENGTH; j++)
        {
            array[i][j]= rand() % 500 - 200;
        }
    }

    printf("Успешное создание масива.\n");
}


void print_array(int array[SIZE][MAX_LENGTH], int lens[SIZE])
{
    printf("\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d) ", i+1);
        for (int j = 0; j < MAX_LENGTH; j++)
        {
            printf("%4d ", array[i][j]);
        }
        printf(" = %5d", lens[i]);
        printf("\n");
    }
    printf("\n");
}


