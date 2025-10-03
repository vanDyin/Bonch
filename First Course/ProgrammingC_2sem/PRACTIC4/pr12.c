#include <stdio.h>
#include <stdlib.h>

#define NUM 20

void func(int *maxNumb) {
    int number;
    
    printf("Input el => ");
    scanf("%d", &number);

    if (number == 0) {
        return;
    }

    if (number > *maxNumb) {
        *maxNumb = number;
    }

    func(maxNumb);
}

int main() {
    int numb = 0;

    func(&numb);
    printf("max numb => %d\n", numb);
    return 0;
}