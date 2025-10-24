#include <stdio.h>
#include <stdint.h>

// Глобальные переменные для обмена с ассемблером
// Для 8 бит
int8_t a8, b8, c8;
int16_t numerator16, denominator16, result16;

// Для 16 бит 
uint16_t a16, b16, c16;
uint32_t numerator32, denominator32, result32;

extern void asm_calculate_8bit(void);
extern void asm_calculate_16bit(void);

//Функция для вычисления на си 8 бит
void c_calculate_8bit(int8_t a, int8_t b, int8_t c) {
    int16_t num, den, res;
    
    num = (4*c-a)/(3+11);
    den = (1+a-b);
    res = num / den;

    printf("Numerator is %hd\n", num);
    printf("Denominator is %hd\n", den);
    printf("Result is %hd\n\n", res);
}

//Функция для вычисления на си 16 бит
void c_calculate_16bit(uint16_t a, uint16_t b, uint16_t c) {
    uint32_t num, den, res;
    
    num = (4*c-a)/(3+11);
    den = (1+a-b);
    res = num / den;

    printf("Numerator is %d\n", num);
    printf("Denominator is %d\n", den);
    printf("Result is %d\n\n", res);
}

int main() {
    printf("\nExpression: (4*c - a/3 + 11) / (1 + a - b)\n\n");

    printf("Enter the values for 8-bit (signed char from -128 to 127):\n");
    printf("a = ");
    scanf("%hhd", &a8); //hh - signed char
    printf("b = ");
    scanf("%hhd", &b8);
    printf("c = ");
    scanf("%hhd", &c8);

    // Вычисления на Си (8-бит)
    printf("\nCalculation on C 8-bit (signed char)\n");
    calculate_c_8bit(a8, b8, c8);

    // Вычисления на Ассемблере (8-бит)
    printf("Calculation on Assembler 8-bit (signed char)\n");
    asm_calculate_8bit();
    printf("Numerator is %hd\n", numerator16);
    printf("Denominator is %hd\n", denominator16);
    printf("Result is %hd\n\n", result16);


    printf("\nEnter the values for 16-bit (unsigned short from 0 to 65535):\n");
    printf("a = ");
    scanf("%hu", &a16); //hu - так википедия написала (h - char, u - unsigned)
    printf("b = ");
    scanf("%hu", &b16);
    printf("c = ");
    scanf("%hu", &c16);

    // Вычисления на Си (16-бит)
    printf("/nCalculation on C 16-bit (unsigned short)\n");
    calculate_c_16bit(a16, b16, c16);

    // Вычисления на Ассемблере (16-бит)
    printf("Calculation on Assembler 16-bit (unsigned short)\n");
    asm_calculate_16bit();
    printf("Numerator is %u\n", numerator32);
    printf("Denominator is %u\n", denominator32);
    printf("Result is %u\n\n", result32);

    return 0;
}
