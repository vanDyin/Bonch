#include <stdio.h>

void recur(int n) {
    if (n > 1) {
        recur(n - 1);
    }
    printf("%d ", n);
}


int main() {
    int n;
    printf("Введите число n: ");
    scanf("%d", &n);
    recur(n);
}