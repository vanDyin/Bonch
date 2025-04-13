#include <stdio.h>
#include <stdlib.h>

#define NUM 20

void print(int count, int array[NUM], int index) {
    if (count == NUM - 1) {
        return;
    }
    int number;
    printf("Input [%d]el => ", count+1);
    scanf("%d", &number);

    if (number == 0) {
        return;
    }

    if (count % 2 == 0) {
        array[index] = number;
        index++;
    }

    print(count+1, array, index);
}

void printArray(int array[NUM], int index) {
    if (array[index] != 0) {
        printf("%d\n", array[index]);
    } else {
        return;
    }
    printArray(array, index+1);
}

void full(int array[NUM], int index) {
    if (index != NUM - 1) {
        array[index] = 0;
    } else {
        return;
    }

    full(array, index+1);
}

int main() {
    int array[NUM];
    full(array, 0);

    print(0, array, 0);
    printArray(array, 0);

    return 0;
}