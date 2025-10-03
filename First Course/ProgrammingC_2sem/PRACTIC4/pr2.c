#include <stdio.h>

void recur(int a, int b) {
    if (a == b) {
        printf("%d", a);
    } else if (a > b) {
        printf("%d ", a);
        recur(a - 1, b);
    } else {
        printf("%d ", a);
        recur(a + 1, b);
    }
}

int main() {
    int a, b;

    printf("Введите число A: ");
    scanf("%d", &a);

    printf("Введите число B: ");
    scanf("%d", &b);

    recur(a, b);
}