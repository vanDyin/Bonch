#include <stdio.h>
#include <ctype.h>

typedef enum {
    BEFORE,    // Пропуск пробелов в начале строки
    INSIDE,    // Чтение и печать первого слова
    AFTER      // Пропуск остатка строки
} State;

int main() {
    State state = BEFORE;
    int c;
    
    while ((c = getchar()) != EOF) {
        switch (state) {
            case BEFORE:
                if (c == '\n') {
                    putchar(c);  // Печать перевода строки
                } else if (!isspace(c)) {
                    putchar(c);   // Печать первой буквы слова
                    state = INSIDE;
                }
                break;
                
            case INSIDE:
                if (c == '\n') {
                    putchar(c);   // Печать перевода строки
                    state = BEFORE;
                } else if (isspace(c)) {
                    state = AFTER;
                } else {
                    putchar(c);   // Печать остальных букв слова
                }
                break;
                
            case AFTER:
                if (c == '\n') {
                    putchar(c);   // Печать перевода строки
                    state = BEFORE;
                }
                break;
        }
    }
    
    return 0;
}