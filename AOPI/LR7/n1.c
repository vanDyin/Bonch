#include <stdio.h>
#include <string.h>


#define N 1000
#define start 500

typedef struct str {
    char tape[N];
    int head;
    int status;
} Tmashine;


void initTM(Tmashine *TM) {
    memset(TM->tape, '0', N);
    TM->head = start;
    TM->status = 1;

    int index = start;
    char sym = 0;
    printf("Введите число в формате 01^x01^y0\n> ");
    while (sym != '\n') {
        sym = getchar();
        if (sym == '\n') {
            break;
        }
        TM->tape[index] = sym;
        index++;
    }

    // printf("%s\n", TM->tape);

}
// 0000110111000000

void print(char *array) {
    for (int i = 10; i >= 0; i--) {
        printf("%c", array[start-i]);
    }

    for (int i = 1; i < 11; i++) {
        printf("%c", array[start+i]);
    }

    printf("\n");
}
int main() {
    Tmashine TM;
    initTM(&TM);
    
    while (TM.status != 0) {

        switch (TM.status) {
            case 1: // находим первую единицу первого массива единиц
                if (TM.tape[TM.head] == '0') {
                    TM.head++;
                    TM.status = 2;
                }
                print(TM.tape); printf("case: %d\n", TM.status);

                break;
            case 2: // ищем ноль между двумя массивами единиц
                if (TM.tape[TM.head] == '0') {
                    TM.head++;
                    TM.status = 3;
                } else {
                    TM.head++;
                }
                print(TM.tape); printf("case: %d\n", TM.status);

                break;
            case 3: // становимся на первую единицу второго массива
                if (TM.tape[TM.head] == '1') {
                    TM.head--;
                    TM.status = 4;
                }
                print(TM.tape); printf("case: %d\n", TM.status);

                break;
            case 4: // переход к последней единице первого массива
                if (TM.tape[TM.head] == '0') {
                    TM.head--;
                    TM.status = 5;
                }
                print(TM.tape); printf("case: %d\n", TM.status);

                break;
            case 5: // 
                if (TM.tape[TM.head] == '0') {
                    TM.status = 13;
                } else {
                    TM.head--;
                    TM.status = 6;
                }
                print(TM.tape); printf("case: %d\n", TM.status);

                break;
            case 6:
                if (TM.tape[TM.head] == '0') {
                    TM.status = 7;
                    TM.head++;
                    TM.tape[TM.head] = '1';
                } else {
                    TM.head--;
                }
                print(TM.tape); printf("case: %d\n", TM.status);

                break;
            case 7:
                if (TM.tape[TM.head] == '1') {
                    TM.status = 8;
                    TM.head++;
                    TM.tape[TM.head] = '0';
                }
                print(TM.tape); printf("case: %d\n", TM.status);

                break;
            case 8:
                if (TM.tape[TM.head] == '0') {
                    TM.status = 9;
                    TM.head++;
                } else {
                    TM.head++;
                }
                print(TM.tape); printf("case: %d\n", TM.status);

                break;
            case 9:
                if (TM.tape[TM.head] == '0') {
                    TM.status = 10;
                    TM.head++;
                } else {
                    TM.head++;
                }
                print(TM.tape); printf("case: %d\n", TM.status);

                break;
            case 10:
                if (TM.tape[TM.head] == '0') {
                    TM.status = 11;
                    TM.head--;
                    TM.tape[TM.head] = '1';
                } else {
                    TM.head++;
                }
                print(TM.tape); printf("case: %d\n", TM.status);

                break;
            case 11:
                if (TM.tape[TM.head] == '0') {
                    TM.status = 12;
                    TM.head--;
                } else {
                    TM.head--;
                }
                print(TM.tape); printf("case: %d\n", TM.status);

                break;
            case 12:
                if (TM.tape[TM.head] == '0') {
                    TM.status = 4;
                } else {
                    TM.head--;
                }
                print(TM.tape); printf("case: %d\n", TM.status);

                break;
            case 13:
                if (TM.tape[TM.head] == '0') {
                    TM.status = 14;
                    TM.head--;
                    TM.tape[TM.head] = '1';
                }
                print(TM.tape); printf("case: %d\n", TM.status);

                break;
            case 14:
                if (TM.tape[TM.head] == '0') {
                    TM.status = 15;
                    TM.head++;
                } else {
                    TM.head--;
                }
                print(TM.tape); printf("case: %d\n", TM.status);

                break;
            case 15:
                if (TM.tape[TM.head] == '1') {
                    TM.status = 0;
                    TM.tape[TM.head] = '0';
                }
                print(TM.tape); printf("case: %d\n", TM.status);

                break;
            case 0:
                goto exit;

        }
    }

    exit:
        printf("%s\n", TM.tape);

    return 0;
}