#include <stdio.h>

int main()
{
    int date;

    printf("In what year was Saint-Petersburg founded?");\
    printf("Enter number and press Enter <Enter>  ->  ");
    scanf("%d", &date);

    if (date == 1703) {
        printf("You are right!");
    } else {
        printf("You are wrong, Saint-Petersburg was founded in 1703.");
    }

    return(0);
}
