#include <stdio.h>


int main()
{
    int i = 1;

    goto condition;


    condition:
        if (i <= 5 && i >= 1) {
            printf("%d ", i);
            goto count;
        } else {
            goto exit;
        }

    count:
        i += 1;
        goto condition;
    
    exit:
        return 0;
        
}