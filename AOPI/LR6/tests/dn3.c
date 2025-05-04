#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAPE_SIZE 1000

typedef struct {
    int state;
    int head;
    char tape[TAPE_SIZE];
} TuringMachine;

void initialize_tape(TuringMachine *tm, const char *input) {
    memset(tm->tape, '0', TAPE_SIZE);
    strncpy(tm->tape + 1, input, strlen(input));
    tm->head = 0;
    tm->state = 1;
}

void print_tape(const TuringMachine *tm, int range) {
    printf("State: q%d | Tape: ", tm->state);
    for (int i = tm->head - range; i <= tm->head + range; i++) {
        if (i == tm->head) {
            printf("[%c]", tm->tape[i]);
        } else {
            printf("%c", tm->tape[i]);
        }
    }
    printf("\n");
}

void run_turing_machine(TuringMachine *tm) {
    while (tm->state != 0) {
        char current = tm->tape[tm->head];
        
        // Для отладки (можно уменьшить частоту вывода)
        static int step = 0;
        if (step++ % 10 == 0) {
            print_tape(tm, 15);
        }

        switch (tm->state) {
            case 1: // Начальное состояние
                if (current == '0') {
                    tm->state = 2;
                    tm->head++;
                }
                break;
                
            case 2: // Проход по x1
                if (current == '1') {
                    tm->head++;
                } else if (current == '0') {
                    tm->state = 3;
                    tm->head++;
                }
                break;
                
            case 3: // Проход по x2
                if (current == '1') {
                    tm->state = 4;
                    tm->head--;
                }
                break;
                
            case 4: // Возврат к разделителю
                if (current == '0') {
                    tm->state = 5;
                    tm->head--;
                }
                break;
                
            case 5: // Проверка завершения первого этапа
                if (current == '0') {
                    tm->state = 13;
                } else if (current == '1') {
                    tm->state = 6;
                    tm->head--;
                }
                break;
                
            case 6: // Движение влево по x1
                if (current == '1') {
                    tm->head--;
                } else if (current == '0') {
                    tm->state = 7;
                    tm->tape[tm->head] = '1';
                    tm->head++;
                }
                break;
                
            case 7: // Замена первой 1 на 0
                if (current == '1') {
                    tm->state = 8;
                    tm->tape[tm->head] = '0';
                    tm->head++;
                }
                break;
                
            case 8: // Проход через x1 и x2 вправо
                if (current == '1') {
                    tm->head++;
                } else if (current == '0') {
                    tm->state = 9;
                    tm->head++;
                }
                break;
                
            case 9: // Проход через x2
                if (current == '1') {
                    tm->head++;
                } else if (current == '0') {
                    tm->state = 10;
                    tm->head++;
                }
                break;
                
            case 10: // Проход через x3
                if (current == '1') {
                    tm->head++;
                } else if (current == '0') {
                    tm->state = 11;
                    tm->tape[tm->head] = '1';
                    tm->head--;
                }
                break;
                
            case 11: // Возврат через x3
                if (current == '1') {
                    tm->head--;
                } else if (current == '0') {
                    tm->state = 12;
                    tm->head--;
                }
                break;
                
            case 12: // Возврат через x2
                if (current == '1') {
                    tm->head--;
                } else if (current == '0') {
                    tm->state = 4;
                }
                break;
                
            case 13: // Второй этап - корректировка
                if (current == '0') {
                    tm->state = 14;
                    tm->tape[tm->head] = '1';
                    tm->head--;
                }
                break;
                
            case 14: // Возврат влево
                if (current == '1') {
                    tm->head--;
                } else if (current == '0') {
                    tm->state = 15;
                    tm->head++;
                }
                break;
                
            case 15: // Финальная корректировка
                if (current == '1') {
                    tm->state = 0;
                    tm->tape[tm->head] = '0';
                }
                break;
        }
    }
}

int main() {
    TuringMachine tm;
    
    // Пример входных данных: x1=3, x2=2
    const char *input = "11101100"; // 0|111|0|11|00...
    
    initialize_tape(&tm, input);
    printf("Initial tape: %s\n", tm.tape);
    
    run_turing_machine(&tm);
    
    printf("Final tape: %s\n", tm.tape);
    return 0;
}