#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <wchar.h>

int main() 
{   
    setlocale(LC_ALL, "");    
    
   
    double shop;
    int proc = 0;

    printf("Вычисление стоимости покупки c учётом скидки\n");
    printf("Введите сумму покупки и нажмите <Enter>  ->  ");
    scanf("%d", shop);
    
    if (shop > 1000) {
        proc = 5;
    } else if (shop > 500) {
        proc = 3;
    }

    printf("Вам предоставляется скидка  %d%\n", proc);
    printf("Сумма c учётом скидки: %.2lf\n", shop * ((1 - proc) / 100));

    return(0);
}

