#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int func(int);
int printout(int, int);


int main()
{
    int a, b;
    int res1, res2;

    printf("Input number a  ->  ");
    scanf("%d", &a);
    
    printf("Input number b  ->  ");
    scanf("%d", &b);

    res1 = func(a);
    res2 = func(b);

    printout(res1, a);
    printout(res2, b);
    
    return(0);
}


int func(int number)
{
    float number2 = sqrt(number);
    return((number2 * number2) == number);
}

int printout(int number, int x)
{
    if (number==1) {
        printf("%d - perfect square.\n", x);
    } else {
        printf("%d - not perfect square.\n", x);
    }

    return(0);
}