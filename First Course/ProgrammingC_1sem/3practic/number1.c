#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int func(int number);

int main()
{
    int number, result;
    printf("Input integer <Enter>  ->  ");
    scanf("%d", &number);

    result = func(number);

    switch (result)
    {
        case 1:
            printf("Number is prime.");
            break;

        case 0:
            printf("Number is complex.");
            break;
        
        default:
            printf("Error.");
            break;
    }
    
    return(0);

}


int func(int number)
{   
    if (number < 0){
        number = abs(number);
    } else if (number == 1){
        return(-1);
    } else if (number == 2) {
        return(1);
    }

    int start;
    int finish = ceil(sqrt(number));

    for (start = 2; start <= finish; start++) {
        if (number % start == 0) {
            return(0);
        }
    }

    return(1);
}