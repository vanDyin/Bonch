#include <stdio.h>
#include <string.h>

#define NAME "number1.txt" 

int generate_file(void);
int copy_file(char *, char *);
int print_file(char *);

int main(void)
{
    char choice;
    char filename[24];
    generate_file();

    printf("Choose option:\n");
    printf("1. Print file to console.\n");
    printf("2. Copy file in a new file.\n");
    choosing:
        printf("Input -> ");
        scanf("%d", &choice);
        
        switch (choice) 
        {
            case 1:
                printf("File contain:\n");
                print_file(NAME);
                printf("\n");
                printf("completed.");
                break;
            
            case 2:
                printf("Please Enter a name of a new file with extension (up 20 characters): ");
                scanf("%s", &filename);
                copy_file(NAME, filename);
                printf("completed.");
                break;
            
            default:
                printf("Please, input 1 or 2.");
                goto choosing;
                break;
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
    }

    fclose(file);
    printf("file %s succesfully created.\n", NAME);
}


int copy_file(char filename_from[], char filename_to[])
{
    FILE *file_from = fopen(filename_from, "r");
    if (file_from == NULL) {
        printf("could not open the file");
        return 1;
    }
    

    FILE *file_to = fopen(filename_to, "w");
    char line[100];
    if (file_to == NULL) {
        printf("could not open the file");
        return 1;
    }

    while (fgets(line, sizeof(line), file_from)) {
        fputs(line, file_to);
    }

    fclose(file_from);
    fclose(file_to);
    printf("File %s succesfully copied in %s.\n", filename_from, filename_to);
}


int print_file(char filename[])
{
    FILE *file = fopen(filename, "r");
    char line[100];
    if (file == NULL) {
        printf("could not open the file");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}