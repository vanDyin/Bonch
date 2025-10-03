#include <stdio.h>


int main() 
{
    long number;
    printf("Enter number. Number must be integer <Enter>  ->  ");
    scanf("%ld", &number);

    if (number % 2 == 0) {
        printf("%ld - even number", number);
    } else {
        printf("%ld - odd number", number);
    }

    return(0);
}

