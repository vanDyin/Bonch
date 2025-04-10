#include <stdio.h>
#include <time.h>


#define SIZE 50

void main()
{
    clock_t start1, end1, start2, end2;
    double cpu_time_used1, cpu_time_used2;


 

    int arr[SIZE] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    int *p = arr;
    
    start1 = clock();
    // var 1
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\n", *p);
        p++;
    }

    end1 = clock();
    cpu_time_used1 = ((double)(end1-start1)) / CLOCKS_PER_SEC;
    
    
    // var 2
    start2 = clock();
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\n", arr[i]);
    }
    
    end2=clock();
    cpu_time_used2 = ((double)(end2-start2)) / CLOCKS_PER_SEC;
    

    printf("cpu_time_used1 Время выполнения: %.6f секунд\n", cpu_time_used1);
    printf("cpu_time_used2 Время выполнения: %.6f секунд\n", cpu_time_used2);



}
