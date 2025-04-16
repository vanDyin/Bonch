#include <stdio.h>
#include <string.h>

#define MAX_LEN 128

int recur(char *string, int len, int index, int flag) {
    if (index == len/2) {
        return flag;
    }
    return recur(string, len, index+1, string[len-index-1] == string[index]);
}

int main() {
    char string[MAX_LEN];
    printf("Введите слово для проверки: ");
    scanf("%s", string);
    int len = strlen(string);
    printf("%d\n", recur(string, len, 0, 0));
}