#include <stdio.h>

void recur(int n) {
    if (n < 10) {
        printf("%d ", n);
    } else {
        recur(n / 10);
        printf("%d ", n % 10);
    }
}

int main () {
    int n;
    printf("Введите число n: ");
    scanf("%d", &n);
    recur(n);
}