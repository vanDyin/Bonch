#include <stdio.h>
#include <stdlib.h>


#define LEN 128

int formArray(int *array, char *message) {
    int numb, length;
    printf(message);

    while (numb != '\n') {
        numb = getchar();

        if (numb == '\n') {
            break;
        }

        array[length] = numb - '0';
        length++;
    }

    return length;
}

int main() {
    int array[LEN], length;
    char message = "Введите последовательность в виде (0110111011): \n> ";

    length = formArray(array, message);
    

    while (1) {

    }





    return 0;

}