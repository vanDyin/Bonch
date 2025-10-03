#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 128
#define L 5
#define N 2
#define MAX_WORDS 20

void input_array(char array[N][LEN]) {
    for (int i = 0; i < N; i++) {
        printf("input [%d]str -> ", i);
        fgets(array[i], LEN, stdin);
        array[i][strcspn(array[i], "\n")] = '\0';
    }
}

void edit_array(char array[N][LEN], void (*trim)(char*), void (*remove)(char*)) {
    for (int i = 0; i < N; i++) {
        trim(array[i]);
        remove(array[i]);
    }
}

void trim_spaces(char str[LEN]) {
    int len = strlen(str);

    if (len == 0) {
        return;
    }

    while (str[0] == ' ') {
        memmove(str, str+1, len);
        len--;
    }

    while (len > 0 && str[len-1] == ' ') {
        str[len-1] = '\0';
        len--;
    }
}

void remove_word(char str[LEN]) {
    char *word = strtok(str, " ");
    char new_str[LEN] = "";

    while (word != NULL) {
        unsigned len = strlen(word);

        if (len <= L) {
            strcat(new_str, " ");
            strcat(new_str, word);
        }

        word = strtok(NULL, " ");
    }

    strcpy(str, new_str);
}


int main() {
    char text[N][LEN];

    input_array(text);
    edit_array(text, trim_spaces, remove_word);

    for (int i = 0; i < N; i++) {
        printf("%s\n", text[i]);
    }
    return 0;
}