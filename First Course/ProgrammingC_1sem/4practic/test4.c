#include <stdio.h>


int main() {
    char ch;

    while (ch != 27 && ch != 'q') {
        ch = getchar();
        printf("%c", ch);
    }

    return 0;
}