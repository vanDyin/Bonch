#include <stdio.h>

#define p_p printf("---------------------------------------------------------\n");

int main(void) {
    int number = 10;
    char bukva = 'a';
    char word[] = "hello world";
    short  shorti = 12;

    int *pInt = &number;
    char *pChar = &bukva;
    char *pWord = &word[0];
    short *pShort = &shorti;

    int number2 = *pInt;
    int *pNumb2 = &number2;

    p_p;
    printf("int number = %d, address = %p \n", number, (void*) pInt);
    printf("char bukva = %c, address = %p \n", bukva, (void*) pChar);
    printf("char word = %s, address = %p \n", word, (void*) pWord);
    printf("short shorti = %hd, address = %p \n", shorti, (void*) pShort);
    p_p;
    printf("int number2 = %d, addres = %p \n", number2, (void*) pNumb2);
    p_p;

    return 0;

}