#include <stdio.h>
#include <stdlib.h>


float multi(float a, float b) {
    return a * b;
}

float division(float a, float b) {
    if (b == 0) {
        printf("Division by zero\n");
        exit(1);
    }

    return a / b;
}

float add(float a, float b) {
    return a + b;
}

float minus(float a, float b) {
    return a - b;
}




int main() {
    float (*operations[4])(float, float) = {
        add, 
        minus, 
        multi, 
        division
    };
    char operationsName[4][30] = {
        "Сложение",
        "Вычитание",
        "Произведение",
        "Деление"
    };
    char signs[4] = {
        '+',
        '-',
        '*',
        '/'
    };

    int choice;
    float x, y;

    while (1) {
        printf("\n");
        printf("Операции:\n");
        printf("1.Сложение\n2.Вычитанние\n3.Произведение\n4.Деление\n5.Выход\n");
        printf("Введите операцию: ");
        scanf("%d", &choice);
        choice--;

        if (choice == 4) {
            return 0;
        } else if (choice <= -1 || choice >= 5) {
            continue;
        }


        printf("Введите x и y через пробел: ");
        scanf("%f %f%*c", &x, &y);

        printf("%s: %.2f %c %.2f = %.2f\n\n", operationsName[choice], x, signs[choice], y, operations[choice](x, y));
        getchar();
    }
    
    return 0;
}