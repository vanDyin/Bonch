#include <stdio.h>
#include <stdlib.h>

typedef enum status {
    before, 
    inside, 
    after
} status;


int main() {
    status status = before;
    char sym = 's';

    do {

        sym = getchar();
        switch (status) {
            
            case before:
                while (sym == ' ') {
                    sym = getchar();
                }

                if (sym == '\n') {
                    putchar(sym);
                } else  if (sym == EOF) {
                    break;
                } else {
                    putchar(sym);
                    status = inside;
                }
                break;
            

            case inside:
                if (sym == ' ') {
                    status = after;
                } else if (sym == '\n') {
                    putchar(sym);
                    status = before;
                } else {
                    putchar(sym);
                }
                break;


            case after:
                if (sym == '\n') {
                    putchar(sym);
                    status = before;
                }
                break;
        }

    } while (sym != EOF);

    return 0;
}