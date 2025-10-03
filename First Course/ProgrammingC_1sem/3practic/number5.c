#include <stdio.h>
#include <string.h>

/*
Задание 5: Определить функцию для расчета доли (в процентах) некоторой буквы в предложении. Входные параметры – строка, символ. Возвращаемое значение – доля.
*/

double part_of_len(char *, char);

int main()
{
    char string[100], symbol;
    int count = 0;
    double part;

    printf("Input string  ->  ");
    fgets(string, sizeof(string), stdin);
    
    printf("Input symbol  ->  ");
    scanf("%c", &symbol);

    part = part_of_len(string, symbol);
    printf("symbol %c was found in %2.0f%%  of whole string.", symbol, part);
    
    return(0);
}


double part_of_len(char *string, char sym)
{
    int count, lengthFOR, length;
    double part;
    length = lengthFOR = strlen(string);
    count = 0;

    for (int i = 0; i < lengthFOR; i++) {
        if (string[i] == sym)
            count ++;
        if (string[i] == ' ' || string[i] == '\n' || string[i] == '\t' || string == '\0')
            length -= 1;
    }

    if (count == 0) {
        return(0);
    } else {
        return(((double)count / length) * 100);
    }
}