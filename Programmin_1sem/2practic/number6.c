#include <stdio.h>


int main() 
{
    int numb, count;

    for (numb = 0; numb <= 90; numb += 10) {
        printf("%3d ", numb);

        for (count = 1; count <= 9; count++) {
            if (numb + count <= (numb / 10) * 11){
                printf("%3d ", numb + count );
            }
        }   
        
        printf("\n");
    }

    return(0);
}