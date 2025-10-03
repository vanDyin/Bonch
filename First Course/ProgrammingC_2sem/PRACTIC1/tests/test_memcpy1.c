#include <stdio.h>
#include <string.h>

#define SIZE 10

int main() 
{
    int a[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    unsigned index;
    int i;

    for (i = 0; i < SIZE; i++) {
        printf("%d ", a[i]);
    }

    printf("\nEnter index [0 .. 9] -> ");
    scanf("%u", &index);

    index = index < SIZE ? index : SIZE-1;

    memcpy(&a[index], &a[index+1], sizeof(int) * (SIZE - index - 1));

    for (i = 0; i < SIZE; i++) {
        printf("%d ", a[i]);
    }

}

// удалим элемент из массива и сдвинем остаток массива влево

