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
    char sym = 0; // Инициализация переменной
    printf("Введите число в формате 01^x01^y0\n> ");
    while ((sym = getchar()) != '\n' && index < N-1) {
        TM->tape[index++] = sym;
    }
}

void print(Tmashine *TM) {
    // Выводим 10 символов слева и справа от текущей позиции
    int left = (TM->head - 10) > 0 ? TM->head - 10 : 0;
    int right = (TM->head + 10) < N ? TM->head + 10 : N-1;
    
    for (int i = left; i <= right; i++) {
        if (i == TM->head) printf("[%c]", TM->tape[i]);
        else printf("%c", TM->tape[i]);
    }
    printf(" (State: %d)\n", TM->status);
}

int main() {
    Tmashine TM;
    initTM(&TM);
    
    while (TM.status != 0) {
        print(&TM);
        
        // Проверка выхода за границы
        if (TM.head < 0 || TM.head >= N) {
            printf("Ошибка: выход за границы ленты!\n");
            break;
        }

        switch (TM.status) {
            case 1:
                if (TM.tape[TM.head] == '0') {
                    TM.head++;
                } else {
                    TM.status = 2;
                }
                break;
                
            case 2:
                if (TM.tape[TM.head] == '0') {
                    TM.head++;
                    TM.status = 3;
                } else {
                    TM.head++;
                }
                break;
                
            case 3:
                if (TM.tape[TM.head] == '1') {
                    TM.head--;
                    TM.status = 4;
                }
                break;
                
            case 4:
                if (TM.tape[TM.head] == '0') {
                    TM.head--;
                    TM.status = 5;
                }
                break;
                
            case 5:
                if (TM.tape[TM.head] == '0') {
                    TM.status = 13;
                } else {
                    TM.head--;
                    TM.status = 6;
                }
                break;
                
            case 6:
                if (TM.tape[TM.head] == '0') {
                    TM.tape[TM.head] = '1';
                    TM.head++;
                    TM.status = 7;
                } else {
                    TM.head--;
                }
                break;
                
            case 7:
                if (TM.tape[TM.head] == '1') {
                    TM.tape[TM.head] = '0';
                    TM.head++;
                    TM.status = 8;
                }
                break;
                
            case 8:
                if (TM.tape[TM.head] == '0') {
                    TM.head++;
                    TM.status = 9;
                } else {
                    TM.head++;
                }
                break;
                
            case 9:
                if (TM.tape[TM.head] == '0') {
                    TM.head++;
                    TM.status = 10;
                } else {
                    TM.head++;
                }
                break;
                
            case 10:
                if (TM.tape[TM.head] == '0') {
                    TM.tape[TM.head] = '1';
                    TM.head--;
                    TM.status = 11;
                } else {
                    TM.head++;
                }
                break;
                
            case 11:
                if (TM.tape[TM.head] == '0') {
                    TM.head--;
                    TM.status = 12;
                } else {
                    TM.head--;
                }
                break;
                
            case 12:
                if (TM.tape[TM.head] == '0') {
                    TM.status = 4;
                } else {
                    TM.head--;
                }
                break;
                
            case 13:
                if (TM.tape[TM.head] == '0') {
                    TM.tape[TM.head] = '1';
                    TM.head--;
                    TM.status = 14;
                }
                break;
                
            case 14:
                if (TM.tape[TM.head] == '0') {
                    TM.head++;
                    TM.status = 15;
                } else {
                    TM.head--;
                }
                break;
                
            case 15:
                if (TM.tape[TM.head] == '1') {
                    TM.tape[TM.head] = '0';
                    TM.status = 0;
                }
                break;
        }
    }

    printf("Результат: ");
    // Находим начало и конец результата
    int begin = start;
    while (begin > 0 && TM.tape[begin] == '0') begin--;
    
    int end = start;
    while (end < N-1 && TM.tape[end] == '0') end++;
    
    // Выводим результат
    for (int i = begin; i <= end; i++) {
        printf("%c", TM.tape[i]);
    }
    printf("\n");

    return 0;
}