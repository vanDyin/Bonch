#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <wchar.h>

#define OGR printf("--------------------\n")

int main() 
{     
    int shop;
    float proc = 0.00;
    OGR;
    printf("Price of your shopping\n");
    printf("Enter your shops price and press enter <Enter>  ->  ");
    scanf("%d", &shop);

    if (shop > 1000) {
        proc = 0.05;
    } else if (shop > 500){
        proc = 0.03;
    }
    printf("Your sale is %1.f%\n", proc*100);
    float shop_sale = shop * (1-proc); 
    printf("Price with sale: %.2f\n", shop_sale);
    OGR;
    return(0);
}

