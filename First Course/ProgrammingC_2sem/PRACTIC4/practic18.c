#include <stdio.h>


int func(int n, int *numb, int (*length)(int), int (*power)(int, int)) {
    int current = power(10, length(n)-1);

    if (n == 0) {
        return 0;
    }

    *numb += current * (n % 10);
    
    func((int) n/10, numb, length, power);
}

int length(int num) {
    if (num == 0)  {
        return 1;
    }
    
    int len = 0;
    while (num != 0) {
        num /= 10;
        len++;
    }
    return len;
}

int power(int a, int b) {
    if (b == 0) {
        return 1;
    }

    return a * power(a, b - 1);
}


int main() {
    int n, numb = 0;

    printf("Enter <n> -> ");
    scanf("%d", &n);

    func(n, &numb, length, power);
    printf("%d", numb);
    return 0;
}