#include <conio.h>
#include <stdio.h>

#define I1 7
#define I2 7
void main() 
{
    int M[I1][I2];
    unsigned i, j;
    for (i = 0; i < I1; i++) 
	    for (j = 0; j < I2; j++) 
            M[i][j] = i * j;
    do {
        printf("Enter indexes:\n");
        printf("Exit: enter indexes > 7 \n");
        scanf("%d", &i);
        scanf("%d", &j);
        if (i <= I1 && j <= I2) 
           	printf("M[%d][%d] == %d\n", i, j, M[i][j]);
		  else break;
       } while (1);
    for (i = 0; i < I1; i++) 
	{
        for (j = 0; j < I2; j++) 
		    printf("\t%d", M[i][j]);
        printf("\n");
    }   printf("For exit enter any key...\n");
    getch();
}
