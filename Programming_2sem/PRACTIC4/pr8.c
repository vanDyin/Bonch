#include <stdio.h>

void recur(int n, int divisor) {
    if (n <= 1) return;

    if (n % divisor == 0) { 
        printf("%d ", divisor);
        recur(n / divisor, divisor);
    } else {
        recur(n, divisor + 1);
    }
}

int main() {
    int n;
    printf("Введите число n: ");
    scanf("%d", &n);

    printf("Простые делители: ");
    recur(n, 2);
}