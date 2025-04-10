#include <stdio.h>

int main()
{
    short number;

    printf("Input number of card  ->  ");
    scanf("%hd", &number);

    switch (number)
    {
        case 14:
            printf("Ace");
            break;
        case 13:
            printf("King");
            break;
        case 12:
            printf("Queen");
            break;
        case 11:
            printf("Jack");
            break;
        default:
            printf("%d", number);
            break;
    }

    return(0);

}