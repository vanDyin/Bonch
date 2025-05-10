#include <stdio.h>

int main() {
    enum states { before, inside, after } state;
    int c;
    state = before;

    while ((c = getchar()) != EOF) {
        switch (state) {
            case before:
                if (c == '\n') {
                    putchar('\n');
                } else if (c == ' ' || c == '\t') {
                
                } else {
                    putchar(c);
                    state = inside;
                }
                break;

            case inside:
                if (c == ' ' || c == '\t') {
                    state = after;
                } else if (c == '\n') {
                    putchar('\n');
                    state = before;
                } else {
                    putchar(c);
                }
                break;

            case after:
                if (c == '\n') {
                    putchar('\n');
                    state = before;
                }
                
                break;
        }
    }

    return 0;
}
