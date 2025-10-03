#include <stdio.h>

int main(void) {
    char a = 'a';
    int ten = 10;
    double pi = 3.14;

    char *p_a = &a;
    int *p_ten = &ten;
    double *p_pi = &pi;
    
    printf("\n");
    printf("index of char takes %lu bytes, var char takes %lu bytes\n", sizeof(p_a), sizeof(char));
    printf("index of int takes %lu bytes, var int takes %lu bytes\n", sizeof(p_ten), sizeof(int));
    printf("index of double takes %lu bytes, var double takes %lu bytes\n", sizeof(p_pi), sizeof(double));
    printf("%p", p_pi);
    printf("\n");
    
    return 0;
}