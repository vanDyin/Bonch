#include <stdio.h>

int recur(int n) {
    if (n < 10) {   
        return n;
    }
    return (n % 10) + recur(n / 10); 
}

int main () {
    int n;
    printf("Введите число n: ");
    scanf("%d", &n);
    printf("%d\n", recur(n));
}