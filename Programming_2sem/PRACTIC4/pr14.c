#include <stdio.h>
#include <stdlib.h>

#define NUM 20

void func(int *maxNumb, int *previousNumb) {
    int number;
    
    printf("Input el => ");
    scanf("%d", &number);

    if (number == 0) {
        return;
    }

    if (number > *maxNumb) {
        *previousNumb = *maxNumb;
        *maxNumb = number;
    }

    if (number > *previousNumb && number < *maxNumb) {
        *previousNumb = number;
    }

    func(maxNumb, previousNumb);
}

int main() {
    int numb = 0;
    int numb2 = 0;
    func(&numb, &numb2);

    printf("max numb => %d\nsecond max numb => %d", numb, numb2);
    return 0;
}