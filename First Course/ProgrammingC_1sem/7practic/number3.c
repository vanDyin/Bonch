/*
3.	Определить, имеются ли в двумерном массиве одинаковые элементы (количество).
*/

#include <stdio.h>
#include <conio.h>


#define ROWS 2
#define COLS 4

void fill_array( int array[ROWS][COLS]);
void print_array( int array[ROWS][COLS]);
void sort_array( int* array, int size);
int check_array( int* array, int size);
int test(int* array, int size, int numb);
int test_ar(int* array, int size, int numb);



int main()
{
    int array[ROWS][COLS];
    fill_array(array);
    print_array(array);
    sort_array(&array[0][0], ROWS*COLS);
    print_array(array);
    int count = check_array(&array[0][0], ROWS*COLS);
    printf("Кол-во повторов: %d", count);

    return 0;
}


void fill_array( int array[ROWS][COLS])
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

void print_array( int array[ROWS][COLS])
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

void sort_array( int* array, int size)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (*(array + j) > *(array + j + 1))
            {
                 int tmp = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = tmp;
            }
        }
    }
}


int check_array( int* array, int size)
{
    int count = 0, place = 0;
    int nums[ROWS*COLS] = {0};


    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if ( *(array+i) == *(array+j)) {
                if (!test_ar(nums, size, *(array+i))) {
                    count += test(array, size, *(array+i));
                    nums[place] = *(array+i);
                    place += 1;
                }
            }
        }
    }

    return count;
}


// 3 3 1 -3 3 1 5 -1


int test(int* array, int size, int numb)
{
    int count = 0;
    for (int i = 0; i < size; i ++)
    {
        if (*(array+i) == numb) {
            count += 1;
        }
    }

    return count;
}

int test_ar(int* array, int size, int numb)
{
    int flag = 0;
    for (int i = 0; i < size; i ++)
    {
        if (*(array+i) == numb) {
            flag = 1;
            break;
        }
    }

    return flag;
}
