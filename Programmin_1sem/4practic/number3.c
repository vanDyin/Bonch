#include <stdio.h>

#define NAME "number3.txt"

int generate_file(void);
void check_file(void);

int main()
{
    if (generate_file()) {
        check_file();
    }

    return 0;
}


int generate_file(void) {
    FILE *file = fopen(NAME, "w");

    if (file == NULL) {
        printf("could not open the file");
        return 1;
    }

    for (int i=1; i <= 9; i++) {
        fprintf(file, "%d ", i*111);
        fprintf(file, "%d ", (i+1)*11);
        fprintf(file, "%d ", i-1);
        fprintf(file, "%d ", i);
    }

    fclose(file);
    printf("file %s succesfully created.\n", NAME);
}

void check_file(void) {

    FILE *file = fopen(NAME, "r");
    int number = 0, max=0;
    
    while ((fscanf(file, "%d", &number)) == 1) {
        if (number>max) {
            max=number;
        }
    }

    fclose(file);
    printf("Max - %d\n", max);
}