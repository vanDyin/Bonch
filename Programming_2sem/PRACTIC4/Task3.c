#include <stdio.h>

int recur(int n) {
    if (n == 1) return 1;       
    if (n % 2 != 0 || n == 0) return 0;  
    return recur(n / 2); 
}

int main() {
    int n;
    printf("Введите число: ");
    scanf("%d", &n);
    printf(recur(n) ? "YES\n" : "NO\n");
}