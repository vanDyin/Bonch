#include <stdio.h>

#define part printf("----------------------------------------------------\n");

void test1(void);
void test2(void);
void test3(void);
void test4(void);
void test5(void);


int main(void) {
    part;
    test1();
    part;
    test2();
    part;
    test3();
    part;
    test4();
    part;
    test5();
    part;
    return 0;
}

void test1(void) {
    printf("      ---test int---\n");
    int *pa, x=5;
    pa = &x;

    printf("По адресу %p хранится *ptr=%d\n",pa,*pa);
    pa++;
    printf("По адресу %p хранится *ptr=%d\n",pa,*pa);
    pa--;
    printf("По адресу %p хранится *ptr=%d\n",pa,*pa);
}

void test2(void) {
    printf("      ---test double---\n");
    double *pa, x=5.0;
    pa = &x;
    printf("По адресу %p хранится *ptr=%f\n",pa,*pa);
    pa++;
    printf("По адресу %p хранится *ptr=%f\n",pa,*pa);
    pa--;
    printf("По адресу %p хранится *ptr=%f\n",pa,*pa);
}

void test3(void) {
    printf("      ---test char---\n");
    char *pa, x=5;
    pa = &x;
    printf("По адресу %p хранится *ptr=%c\n",pa,*pa);
    pa++;
    printf("По адресу %p хранится *ptr=%c\n",pa,*pa);
    pa--;
    printf("По адресу %p хранится *ptr=%c\n",pa,*pa);
}

void test4(void) {
    printf("      ---test long double---\n");
    long double *pa, x=5.0;
    pa = &x;
    printf("По адресу %p хранится *ptr=%Lf\n",pa,*pa);
    pa++;
    printf("По адресу %p хранится *ptr=%Lf\n",pa,*pa);
    pa--;
    printf("По адресу %p хранится *ptr=%Lf\n",pa,*pa);
}

void test5(void) {
    printf("      ---test short unsigned int---\n");
    short unsigned int *pa, x=5;
    pa = &x;
    printf("По адресу %p хранится *ptr=%hu\n",pa,*pa);
    pa++;
    printf("По адресу %p хранится *ptr=%hu\n",pa,*pa);
    pa--;
    printf("По адресу %p хранится *ptr=%hu\n",pa,*pa);
}