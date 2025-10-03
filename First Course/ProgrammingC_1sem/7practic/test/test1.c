/*
Пример:
Пользователь вводит 10 слов. 
Вывести слово с максимальной длиной. 
Программа внешне совершенно простая, единственная проблема - считывание и вывод слова. 
Так как слова хранятся в двумерном массиве, то указатель на words[i][0] – это начало нового слова. 
Также не забываем об ограничении на длину при вводе.
*/

#include <conio.h>
#include <stdio.h>
 
#define SIZE 10
#define MAX_LENGTH 128
 
void main() {
    char words[SIZE][MAX_LENGTH];  //Массив хранит 10 слов максимум по 128 символов
    unsigned i, j, n, maxLength; 
    unsigned char counter[SIZE]; //Так как длина слова ограничена 127 символами, то типа char хватит

    printf("Enter the number of words (indexes <= 10) :\n");
    scanf("%d", &n);
	
 
    for (i = 0; i <= n; i++) {
        fgets(&words[i][0], MAX_LENGTH - 1, stdin); //Считываем слова. words[i][0] - это символ, нам нужен 
        j = 0;                                      //адрес, начиная с которого можно писать в массив
        
        //Считаем длину слова
        while (words[i][j]) {
            j++;
        }
        counter[i] = j;
    }
 
    //Ищем слово с максимальной длиной
    maxLength = counter[0];
    j = 0;
    for (i = 1; i <= n; i++) {
        if (counter[i] > maxLength) {
            maxLength = counter[i];
            j = i;
        }
    }

    printf("Max word:\n");
	printf("%s", &words[j][0]); //Выводим слово на печать. При выводе строки необходимо передавать указатель
    getch();
}	
