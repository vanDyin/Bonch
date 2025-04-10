#include <stdio.h>

int main()
{
    int a, b, c;

    printf("Input number a: ");
    scanf("%d", &a);

    printf("Input number b: ");
    scanf("%d", &b);
    
    printf("Input number c: ");
    scanf("%d", &c);
    
    if (a==b && a==c && b==c) {
        printf("all numbers are same.");
    } else if (a>=b && a>=c){
        printf("%d - maximum number", a);
    } else if (b>=a && b>=c) {
        printf("%d - maximum number", b);
    } else if (c>=a && c>=b) {
        printf("%d - maximum number", c);
    } 

    return 0;
}
