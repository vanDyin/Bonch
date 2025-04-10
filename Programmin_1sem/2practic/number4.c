#include <stdio.h>

int main()
{
    int numb, i;
    long sumi = 0;

    printf("Input integer <Enter>  ->  ");
    switch (scanf("%d", &numb))
    {
        case 1:
            goto count;

        case 0:
            goto error;
    }

    count:
        for (i = 1; i <= numb; i++) 
            sumi += i;
    
        printf("Sum of numbers up to %d = %ld", numb, sumi);
        return(0);
    

    error:
        printf("Please input integer.");
        return(0);
}

