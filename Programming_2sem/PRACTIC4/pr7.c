#include <stdio.h>


int recur(int n, int divisor) {
    if (divisor * divisor > n) {  
        return 1;        
    }
    if (n % divisor == 0) {      
        return 0;               
    }
    return recur(n, divisor + 1);  
}

int main() {
    int n;
    printf("Введите число n: ");
    scanf("%d", &n);
    printf(recur(n, 2) ? "YES\n" : "NO\n");
}