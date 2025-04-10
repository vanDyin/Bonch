/*
Задание 4. Исследуйте перемещение по массиву с помощью указателя. Объявите и инициализируйте массив на 10 элементов (используйте разные типы данных: char, short, int, float):
float array[10]={1.1, 2.2, 3.3, 4.4 ...};
float *ptr_a;

4.1 Убедитесь, что имя массива в действительности является его адресом,
т.е. напечатайте значения array, &array[0], &array; с помощью спецификатора %p.

4.2 Установите указатель на начало массива ptr_a и выполните операции,
одновременно напечатав значение указателя и то, на что он указывает (*ptr_a):
ptr_a++; 	ptr_a+4; 	ptr_a-2

4.3 Напишите цикл прохода по массиву с помощью указателя в прямом порядке с увеличением указателя на х
(х = кол-во байт в используемом типе).

4.4 Выполните проход по массиву в обратном порядке, 
предварительно установив указатель на конец массива с использованием операции декремента.
*/
#include <stdio.h>



int main(void) {
    float float_array[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};
    char char_array[10] = {'h', 'e', 'l', 'l', 'o', ' ', 'm', 'i', 'r', '!'};
    short short_array[10] = {1, 2, 3, 4 ,5, 6, 7, 8, 9, 10};
    int int_array[10]= {1, 2, 3, 4 ,5, 6, 7, 8, 9, 10};


    // TYPE FLOAT
    printf("-----------------------------------\n");
    printf("            ---Float---\n");
    float *ptr_fl = float_array;
    float *ptr_fl_0 = &float_array[0];
    printf("array:\n%p;\n\naddres:\n%p;\n\naddres[0]:\n%p;\n", float_array, ptr_fl, ptr_fl_0);


    // TYPE CHAR
    printf("-----------------------------------\n");
    printf("            ---Char---\n");
    char *ptr_ch = char_array;
    char *ptr_ch_0 = &char_array[0];
    printf("array:\n%p;\n\naddres:\n%p;\n\naddres[0]:\n%p;\n\n", char_array, ptr_ch, ptr_ch_0);


    // TYPE SHORT
    printf("-----------------------------------\n");
    printf("            ---Short---\n");
    short *ptr_sh = short_array;
    short *ptr_sh_0 = &short_array[0];
    printf("array:\n%p;\n\naddres:\n%p;\n\naddres[0]:\n%p;\n", short_array, ptr_sh, ptr_sh_0);


    // TYPE INT
    printf("-----------------------------------\n");
    printf("            ---Int---\n");
    int *ptr_int = int_array;
    int *ptr_int_0 = &int_array[0];
    printf("array:\n%p;\n\naddres:\n%p;\n\naddres[0]:\n%p;\n", int_array, ptr_int, ptr_int_0);
    

    return 0;
}
