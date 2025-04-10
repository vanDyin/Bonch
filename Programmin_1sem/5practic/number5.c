#include <stdio.h>

void printp(void *, int);

void main (void){

    int i=0x12345678;
    double d = 0.142312331;
    short s = 12;

    double *prt_d = &d;
    int *prt_i = &i;
    short *prt_s = &s;
    printf("-------------------------\n");

    printf("int\n");
    printp(prt_i, sizeof(i));

    printf("double\n");
    printp(prt_d, sizeof(d));

    printf("short\n");
    printp(prt_s, sizeof(s));


    /*
    unsigned char *a1, *a2, *a3, *a4;
    unsigned char *a;
    a=(unsigned char*) prt;
    a1=a+3;
    a2=a+2;
    a3=a+1;
    a4=a; 

    printf("%.2x\n%.2x\n%.2x\n%.2x\n", *a1, *a2, *a3, *a4);
    */
}

void printp(void *ptr, int size_all) {
    printf("-------------------------\n");
    unsigned char *c_ptr = (unsigned char* ) ptr;
    for (int i = 0; i < size_all; i++) {
        printf("%d байт - %.2x\n", i+1,c_ptr[i]);
    }
    printf("-------------------------\n");
}