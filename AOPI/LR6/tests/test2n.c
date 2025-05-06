#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAPE_SIZE 1000

typedef struct {
    char tape[TAPE_SIZE];
    int head;
    int state;
} TuringMachine;

// Вспомогательная функция: вычитание 1 из десятичной цифры
char decrement(char digit) {
    return digit == '0' ? '9' : digit - 1;
}

void run(TuringMachine *TM) {
    while (1) {
        char sym = TM->tape[TM->head];

        switch (TM->state) {
            case 0: // ищем начало правого числа
                if (sym == '-') {
                    TM->head++;
                    TM->state = 1;
                } else {
                    TM->head++;
                }
                break;

            case 1: // вычитаем 1 из правого числа
                if (sym >= '1' && sym <= '9') {
                    TM->tape[TM->head] = decrement(sym);
                    TM->head--;
                    TM->state = 2;
                } else if (sym == '0') {
                    TM->tape[TM->head] = '9';
                    TM->head--;
                } else if (sym == ' ' || sym == '\0') { // правое число исчерпано
                    TM->state = 6;
                    TM->head--;
                } else {
                    TM->head++; // продолжаем идти вправо, если что-то не то
                }
                break;

            case 2: // идём к минусу
                if (sym == '-') {
                    TM->head--;
                    TM->state = 3;
                } else {
                    TM->head--;
                }
                break;

            case 3: // вычитаем 1 из левого числа
                if (sym >= '1' && sym <= '9') {
                    TM->tape[TM->head] = decrement(sym);
                    TM->head++;
                    TM->state = 4;
                } else if (sym == '0') {
                    TM->tape[TM->head] = '9';
                    TM->head--;
                } else if (sym == ' ' || sym == '\0') { // левое число исчерпано
                    TM->state = 6;
                    TM->head++;
                }
                break;

            case 4: // возвращаемся вправо к правому числу
                if (sym == '-') {
                    TM->head++;
                    TM->state = 1;
                } else {
                    TM->head++;
                }
                break;

            case 6: // чистим знак и завершаем
                if (sym == '-') {
                    TM->tape[TM->head] = ' ';
                    TM->state = 7;
                } else {
                    TM->tape[TM->head] = ' ';
                    TM->head += (TM->tape[TM->head + 1] == '-' ? 1 : -1);
                }
                break;

            case 7: // останов
                return;
        }
    }
}

int main() {
    TuringMachine TM;
    memset(TM.tape, ' ', TAPE_SIZE);
    TM.head = 500; // середина ленты
    TM.state = 0;

    // Пример: |2-1| = 1 → запишем "2-1"
    char input[] = "2-1"; // замените на любое другое, например "34-8"
    memcpy(&TM.tape[TM.head], input, strlen(input));

    run(&TM);

    // Печатаем результат
    printf("Результат на ленте: ");
    for (int i = 480; i < 520; i++) {
        if (TM.tape[i] != ' ') putchar(TM.tape[i]);
    }
    printf("\n");

    return 0;
}
