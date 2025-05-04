#include <stdio.h>

void recur() {
    int num;
    scanf("%d", &num);
    
    if (num == 0) {
        return;
    }
    
    if (num % 2 != 0) { 
        printf("%d\n", num);
    }
    
    recur(); 
}

int main() {
    printf("Введите числа для проверки на нечетность: ");
    recur();
    return 0;
}