#include <stdio.h>


int Euclid(int , int);
int min(int, int);
int max(int, int);

int main()
{
    int a, b, result;

    printf("Input integer a <Enter>  ->  ");
    scanf("%d", &a);

    printf("Input integer b <Enter>  ->  ");
    scanf("%d", &b);

    if (a == b) {
        printf("NOD - %d", a);
        return(0);
    }
    result = Euclid(a, b);

    printf("NOD - %d", result);

    return(0);    
}


int Euclid(int numb1, int numb2)
{
    int maximum, minimum;
    while (min(numb1, numb2) != 0) {
        if (numb1 > numb2) {
            numb1 = numb1 % numb2;
        } else if (numb2 > numb1) {
            numb2 = numb2 % numb1;
        }
    }

    return max(numb1, numb2);
}

int min(int numb1, int numb2)
{
    if (numb1 > numb2)
        return(numb2);
    
    if (numb2 > numb1)
        return(numb1);
    
    return(numb1);
}

int max(int numb1, int numb2)
{
    if (numb1 > numb2)
        return(numb1);
    
    if (numb2 > numb1)
        return(numb2);
    
    return(numb1);
}