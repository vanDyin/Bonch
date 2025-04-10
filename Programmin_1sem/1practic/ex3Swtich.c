#include <stdio.h>

int main()
{
    char vehicle;
    printf("a - automobile, m - motorbike, b - bicycle, p - plane, t - train\n");
    printf("Input first char of vehicle  ->  ");
    scanf("%c", &vehicle);

    switch (vehicle)
    {
        case 'a':
            printf("Max speed of automobile - 447 km/h.");
            break;
        case 'b':
            printf("Max speed of bicycle - 295 km/h.");
            break;
        case 'p':
            printf("Max speed of plane - 2681 km/h");
            break;
        case 't':
            printf("Max speed of train - 603km/h.");
            break;
        default:
            printf("Try again.");
            break;
    }

    return(0);
}