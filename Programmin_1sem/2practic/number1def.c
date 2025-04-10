#include <stdio.h>


int numbers(int);

int main()
{
    int i = 0;
    numbers(i);
    return(0);
}


int numbers(int x)
{
    x++;
    
    if (x >= 1 && x <= 5)
        printf("%d ", x);
    else if (x > 5) 
        return(0);
    
    return(numbers(x));
}