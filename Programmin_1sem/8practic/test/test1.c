// 1.Создать целочисленный динамический одномерный массив и подсчитать сумму его элементов.


#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void main( )
{  int *p;
   int sum = 0, i, n;

   printf("Enter the length of the array:\n");
   scanf("%d", &n);

   p = (int*) malloc( n*sizeof (int));   	/* выделение памяти для n элементов целого типа */

   printf("Array fnd Sum:\n");
   for (i = 0; i < n; i ++ ) 
   {
     p[i] = rand ()%10 - 5 ; 
     printf("p[%d] = %d\n", i, p[i]);
	 sum+=p[i];
   }

   printf("sum = %d\n", sum);
   free(p);    /* освобождения выделенной памяти */

   printf("Click on Enter...");
   getch();
}
