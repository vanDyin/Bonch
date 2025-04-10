/*
Пользователь вводит данные с консоли, и они записываются в файл до тех пор, пока не будет нажата клавиша esc. 
Проверьте программу и посмотрите, как она себя ведёт в случае, если вы вводите backspace:
что выводится в файл и что выводится на консоль.
*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


#define NAME "number2.txt"


int process(void);

int main() {
    if (process()) {
        printf("Completed sucessfully.\n");
    } else {
        printf("Error.\n");
    }
    return 0;
}

int process(void) {
    FILE *file = fopen(NAME, "w");
    char c = 0;

    if (file == NULL) {
        printf("Error at the openning file.\n");
        return 0;
    }

    while (c != 27 ) {
        c = getch();
        putchar(c);
        if (c == 27) {
            break;
        }
        if (c == 13) {
            printf("\n");
        }
        fprintf(file, "%c", c);
    }
    printf("\n");
    fclose(file);
    printf("EESC WAS PRESSED\n");
    return 1;
}