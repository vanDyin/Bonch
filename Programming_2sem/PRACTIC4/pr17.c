#include <stdio.h>



void generate(int countZero, int countOne, int isLastZero, int *count) {
    if (countZero == 0 && countOne == 0) {
        (*count)++;
        return;
    }

    if (countOne > 0) {
        generate(countZero, countOne-1, 0, count);
    }

    if (countZero > 0 && !isLastZero) {
        generate(countZero-1, countOne, 1, count);
    }
}



int main() {
    int a, b;
    printf("a and b => ");
    scanf("%d %d", &a, &b);
    
    int count = 0;
    generate(a, b, 0, &count);
    
    printf("count: %d\n", count);
    return 0;
}