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

    printf("%s\n", TM.tape);

    return 0;
}