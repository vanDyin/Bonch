#include <stdio.h>


void main() {
   float x,y;
   char sign='+';

   while (sign != '0') {
        printf("Sign: "); //Знак операции
        scanf("%c%*c", &sign);

        if (sign == '0') {
            break;
        }

        if (sign == '+' || sign == '-' || sign == '*' || sign == '/') {
            printf("x=");
            scanf("%f%*c", &x);
            printf("y=");
            scanf("%f%*c", &y);

            switch (sign) 
            {
                case '+':
                    printf("%.2f\n", x+y);
                    break;
                case '-':
                    printf("%.2f\n", x-y);
                    break;
                case '*':
                    printf("%.2f\n", x*y);
                    break;
                case '/':
                    if (y != 0) {
                        printf("%.2f\n", x/y);
                    } else {
                        printf("Division by zero!\n");// Деление на ноль!
                    }  
            }

        } else printf("The operation sign is specified incorrectly\n"); // Неверно указан знак операции
   }
}
