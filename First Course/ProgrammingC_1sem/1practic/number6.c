#include <stdio.h>
#include <stdlib.h>


int main()
{
    int weight_user, weight_optimal, height;

    printf("Enter your height (use integer)  ->  ");
    scanf("%d", &height);
    printf("Enter your weight (use integer)  ->  ");
    scanf("%d", &weight_user);

    weight_optimal = height - 100;
    if (weight_optimal < 0) {
        printf("You probably do a mistake, try again.");
        return(0);
    }

    if (7 >= abs(weight_optimal - weight_user) >= 0) {
        printf("You have an optimal weight. (optimal weight - %d)", weight_optimal);
    } else {
        printf("Your weight is not optimal. (optimal weight - %d)", weight_optimal);
    } 

    return(0);
    
}