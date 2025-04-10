#include <stdio.h>

int condition(int);

int main() 
{
    int numb, count;

    for (numb = 0; numb <= 90; numb += 10) {
        printf("%3d ", numb);

        for (count = 1; count <= 9; count++) {
            if (condition(numb + count)) {
                printf("%3d ", numb + count );
            }
        }
        printf("\n");
    }

    return(0);
}

int condition(int x)
{
    return(!((x % 10 == 5) || (x % 10 == 8)));
}
