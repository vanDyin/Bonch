#include <stdio.h>
#include <stdint.h>

// Declaring global variables
int16_t a_sign, b_sign;
uint16_t a_unsign, b_unsign;

// Declaring global results
int16_t result_sign;
uint16_t result_unsign;

// Declaring global functions for .asm
extern int asm_sign(void);
extern int asm_unsign(void);

int calc_sign(int16_t a, int16_t b) {
    if (a > b) {
        return -127;
    } else if (a == b) {
        return a / b - 2;
    } else {
        return a / b + 11;
    }
}

int calc_unsign(uint16_t a, uint16_t b) {
    if (a > b) {
        return -127;
    } else if (a == b) {
        return a / b - 2;
    } else {
        return a / b + 11;
    }
}

int main() {
    printf("Введите знаковые (-32768...32767) значения a и b: \n");
    printf("1: ");
    scanf("%hd", &a_sign);
    printf("2: ");
    scanf("%hd", &b_sign);
    
    result_sign = calc_sign(a_sign, b_sign);
    printf("Результат на C: %d\n", result_sign);
    
    asm_sign();
    printf("Результат на ASM: %d\n", result_sign);

    printf("Введите беззнаковые (0...65535)значения a и b: \n");
    printf("1: ");
    scanf("%hd", &a_unsign);
    printf("2: ");
    scanf("%hd", &b_unsign);

    result_unsign = calc_unsign(a_unsign, b_unsign);
    printf("Результат на C: %u\n", result_unsign);

    asm_unsign();
    printf("Результат на ASM: %u\n", result_unsign);

    return 0;
}
