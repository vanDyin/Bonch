#include <stdio.h>

// Глобальные переменные для обмена с ассемблером
// Для 8 бит
signed char a8, b8, c8;
signed char numerator8, denominator8, result8;

// Для 16 бит 
unsigned short a16, b16, c16;
unsigned short numerator16, denominator16, result16;


//Функция для вычисления на си 8 бит
void c_calculate_8bit(signed char a, signed char b, signed char c) {
    signed char num, den, res; 
    
    num = (4*c-a)/(3+11);
    den = (1+a-b);
    if (den != 0) {
        res = num / den;
    } else {
        printf("Divide by 0");
    }

    printf("Numerator is %d/n", &num);
    printf("Denominator is %d/n", &num);
    printf("Result is %d/n/n", &num);
}

//Функция для вычисления на ассах 8 бит
void ass_calculate_8bit() {
    printf("Ассемблерная версия пока не реализована\n");
}

//Функция для вычисления на си 16 бит
void c_calculate_16bit(unsigned short a, unsigned short b, unsigned short c) {
    unsigned short num, den, res; 
    
    num = (4*c-a)/(3+11);
    den = (1+a-b);
    if (den != 0) {
        res = num / den;
    } else {
        printf("Divide by 0");
    }

    printf("Numerator is %d/n", &num);
    printf("Denominator is %d/n", &num);
    printf("Result is %d/n/n", &num);
}

//Функция для вычисления на ассах 16 бит
void ass_calculate_16bit() {
    printf("Ассемблерная версия пока не реализована\n");
}

int main() {
    printf("/nExpression: (4*c - a/3 + 11) / (1 + a - b)\n\n");

    printf("Enter the values for 8-bit (signed char from -128 to 127):\n");
    printf("a = ");
    scanf("%hhd", &a8); //hh - signed char, d - чтобы вывело как число
    printf("b = ");
    scanf("%hhd", &b8);
    printf("c = ");
    scanf("%hhd", &c8);

    // Вычисления на Си (8-бит)
    printf("/nCalculation on C 8-bit (signed char)/n");
    calculate_c_8bit(a8, b8, c8);

    // Вычисления на Ассах (8-бит)
    ass_calculate_8bit(a8, b8, c8);


    printf("\nEnter the values for 16-bit (unsigned short from 0 to 65535):\n");
    printf("a = ");
    scanf("%hu", &a16); //hu - так википедия написала (h - char, u - unsigned)
    printf("b = ");
    scanf("%hu", &b16);
    printf("c = ");
    scanf("%hu", &c16);

    // Вычисления на Си (16-бит)
    printf("/nCalculation on C 16-bit (unsigned short)/n");
    calculate_c_16bit(a16, b16, c16);

    // Вычисления на Ассах (16-бит)
    ass_calculate_16bit(a16, b16, c16);

    return 0;
}