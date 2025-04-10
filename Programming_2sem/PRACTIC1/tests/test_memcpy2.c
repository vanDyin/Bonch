#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(void* a, void* b, void* tmp, size_t size) 
{
    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);
}

int main() 
{
    float a = 300.456;
    float b = 0.645;
    float tmp;

    printf("a = %.3f\nb = %.3f\n", a, b);

    swap(&a, &b, &tmp, sizeof(float));

    printf("\na = %.3f\nb = %.3f", a, b);
}

// Функция меняет местами две переменные

