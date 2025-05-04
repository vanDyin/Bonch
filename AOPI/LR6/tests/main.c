#include <stdio.h>
#include <stdlib.h>


#define N 1000
#define LEN 128

typedef enum State {
    before,
    inside,
    end
} pos;

typedef struct mashine {
    int position;
    pos state;
    int count;
} Tmashine;



int formArray(char *array, char *message) {
    char numb;
    int length = 0;

    printf(message);

    while (numb != '\n') {
        numb = getchar();

        if (numb == '\n') {
            break;
        }

        array[length] = numb;
        length++;
    }

    return length;
}


void printArray(char *array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", array[i]);
    }
}


int main() {
    Tmashine mashine = {0, before, 0};
    int length;
    char array[LEN], message[] = "Введите последовательность в виде (01101110110): \n> ";

    length = formArray(array, message);
    
    while (mashine.state != end) {
        switch (mashine.state) {
            
            case before:
                if (array[mashine.position] == '1') {
                    mashine.state = inside;
                    printf("go to inside\n");
                } else {
                    mashine.position++;
                }
                break;
            
            case inside:
                if (array[mashine.position] == '1') {
                    array[length+mashine.count] = '1';
                    mashine.position++;
                } else {
                    array[length+mashine.count] = '0';
                    mashine.state = end;
                    printf("go to end\n");

                }
                break;

            case end:
                array[length+mashine.count+1] = '\0'; 
                exit(0);
                break;
        }
    }

    printf(array);
    return 0;
    
}