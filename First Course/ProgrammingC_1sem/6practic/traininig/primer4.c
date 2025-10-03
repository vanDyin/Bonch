/*Функция вывода символов
Для вывода символов может использоваться функция
 char putchar(char);
Пример: Посчитать количество введенных символов во введенной строке.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
    char s[80], sym;
    int count, i;
    printf("Введите строку : ");
    fgets(s, 79, stdin);
    printf("Введите символ : ");
    sym = getchar();
    count = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == sym)
        count++;
    }
    printf("В строке\n");
    puts(s);      // Вывод строки
    printf("символ ");
    putchar(sym); // Вывод символа
    printf(" встречается %d раз", count);
    getchar();
    return 0;
}	





 

