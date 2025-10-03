#include <stdio.h>
#include <math.h>

int sumi_digits(int);


int main()
{
    int number;
    int sum;

    printf("Input number  ->  ");

    switch (scanf("%d", &number))
    {
        case 1:
            sum = sumi_digits(number);
            printf("Sum of digits of number is -> %d", sum);
            break;

        case 0:
            printf("Input number and try again.");
            break;
    }

    return(0);
}


int sumi_digits(int number)
{
    int sumi = 0;

    while (number >= 1) {
        sumi += number % 10;
        number /= 10;
    }

    return(sumi);
}