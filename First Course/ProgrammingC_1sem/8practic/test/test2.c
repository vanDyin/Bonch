// 2. Вычислить след матрицы, то есть произведение элементов главной диагонали матрицы с использованием двумерного динамического массива.

#include<stdlib.h>
#include<time.h>


void main ( )
{
	int **matr;
	int n, i, j, sled=1;

	printf("Enter n:\n");
    	scanf("%d", &n);
    
	matr = (int*) malloc(n*sizeof(int*));
	for(int i = 0; i < n ; i ++) 
	    matr[i] = (int*) malloc (n*sizeof(int));
    

	/* заполним матрицу случайными числами */
	srand(time(0));
	for(i = 0 ; i < n ; i ++)
	    for (j = 0 ; j < n ; j ++)
        {
            matr[i][j] = rand()%10;
	        printf("matr[%d][%d] = %d%d\n", i, j, matr[i][j]);
	    }
    
    /* Считаем след матрицы */
	for(i=0; i<n; i++)
	    sled *= matr[i][i]; 
	printf("sled = %d\n", sled);
	

	free(matr); // освобождения выделенной памяти
	printf("Click on Enter...");
    getch();
}
// Заполнение массивов (на примере одномерного) случайными числами:
int test()
{
    int a, b, n, A[2];

    //от 1 до 10
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++ )
        A[i] = rand()%10+1;


    //от -20 до 20
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++ )
        A[i] = rand() % 41-20;


    //на отрезке от a до b
    srand(time(NULL)*1000);
    for (int i=0; i<n; i++)
        A[i]=(rand()*1.0/(RAND_MAX)*(b-a)+a);
}