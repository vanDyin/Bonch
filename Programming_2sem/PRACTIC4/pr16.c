#include <stdio.h>

int count(int *zero, int *ones) {
    int num;
    printf("Input el => ");
    scanf("%d", &num);
    
    if (num == 0) {
        (*zero)++;
    } else {
        *zero = 0;
    }

    if (*zero >= 2) {
        return 0;
    }


    if (num == 1) {
        (*ones)++;
    }
    
    return count(zero, ones);
}

int main() {
    int zeros = 0, ones = 0;
    count(&zeros, &ones);
    
    printf("ones count: %d\n", ones);
    return 0;
}