#include <stdio.h>
#include <stdlib.h>

int main()
{
    int y;
    int x;
    for (x = -10; x < 11; ++x) {
        if (x == 0) {
            printf("x = 0, y = 0\n");
        } else if (x > 0) {
            printf("x = %d, y = %d\n", x, (2*x-10));
        } else {
            printf("x = %d, y = %d\n", x, (2*abs(x)-10));
        }
    }
    return(0);

}

