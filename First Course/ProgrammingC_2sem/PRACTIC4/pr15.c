#include <stdio.h>
#include <stdlib.h>

#define NUM 40

void func(int array[NUM], int index, int *maxNumb) {
    int number;
    printf("Input el => ");
    scanf("%d", &number);

    if (number == 0) {
        return;
    }

    array[index] = number;
    index++;

    if (number > *maxNumb) {
        *maxNumb = number;
    }

    func(array, index, maxNumb);
}


void full(int array[NUM], int index) {
    if (index != NUM - 1) {
        array[index] = 0;
    } else {
        return;
    }

    full(array, index+1);
}

void func2(int array[NUM], int max, int *count, int index) {
    if (array[index] == 0) {
        return;
    }

    if (array[index] == max) {
        (*count)++;
    }

    func2(array, max, count, index+1);
}

int main() {
    int array[NUM], max = 0, count = 0;
    full(array, 0);

    func(array, 0, &max);
    func2(array, max, &count, 0);
    printf("max(%d) nums count : %d\n", max, count);
    return 0;
}