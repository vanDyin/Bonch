/*
Подсчитать количество строк в файле. 
Будем считывать файл посимвольно, считая количество символов '\n' до тех пор, пока не встретим символ EOF. 
EOF – это спецсимвол, который указывает на то, что ввод закончен и больше нет данных для чтения.
Функция возвращает отрицательное значение в случае ошибки.
ЗАМЕЧАНИЕ: EOF имеет тип int, поэтому нужно использовать int для считывания символов. 
Кроме того, значение EOF не определено стандартом.
*/

#include <stdio.h>


#define NAME "number4.txt"

int generate_file(void);
int read_file(void);

int main(void) {
    
    // if (generate_file()) {
    if (read_file())
        printf("Completed sucessfully.\n"); 
    else 
        printf("Error with openning file.\n");
    
}


int generate_file(void) {
    FILE *file = fopen(NAME, "w");

    if (file == NULL) {
        printf("could not open the file.\n");
        return 0;
    }

    for (int i=1; i <= 17; i++) {
        fprintf(file, "%d\n", i);
    }

    fclose(file);
    printf("file %s succesfully created.\n", NAME);
    return 1;
}

int read_file(void) {
    FILE *file = fopen(NAME, "r");
    char c = 10;
    int count = 0;


    if (file == NULL) {
        printf("Error at the reading file.\n");
        return 0;
    }

    while (c != EOF) {
        if (c == '\n') 
            count += 1;

        c = fgetc(file);
    }
    fclose(file);
    printf("EOF was found.\n");
    printf("there are %d lines.\n", count);
    return 1;

}