#include <stdio.h>

void test();
void test2();

static int b = 10;

void main()
{

    test();
    test();
    test();
    test2();
}


void test2()
{
    printf("static b - %d\n", b);
}


void test()
{
    static int a = 5;
    printf("a - %d\n", a);
    printf("b - %d\n", b);
    a+=1;
}