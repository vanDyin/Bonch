#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN1 30
#define LEN2 30

typedef struct soccerCommand {
    char commandName[LEN1];
    char trainerName[LEN1];
    unsigned short pastTournamentPlace;
    unsigned short currentTournamentPlace;
} command;



void inputStructArray(command *commands, unsigned n, void (*trim)(char *, char *), char *buffer) {
    char choose = 0;
    char filename[LEN2]; 
    int count = 0;
    int currentCommand = 0; 
    char buffer2[LEN2];
    FILE *file;

    try:
        printf("Choose type of input:\n 1. From file \n 2. from console\n");
        scanf("%d", &choose);
        getchar();
        switch (choose) {
            case 1:
                goto fromFile;
            case 2:
                goto fromConsole;
            default:
                goto try;
        }

    fromConsole:
        for (int i = 0; i < n; i++) {
            printf("Enter <[%d]command Name> -> ", i+1);
            fgets(buffer, LEN1-1, stdin);
            trim(buffer, commands[i].commandName);

            printf("Enter <[%d]command Trainer Name> -> ", i+1);
            fgets(buffer, LEN1-1, stdin);
            trim(buffer, commands[i].trainerName);
            
            printf("Enter <[%d]past Tournament Place> -> ", i+1);
            scanf("%hu", &commands[i].pastTournamentPlace);
            getchar();

            printf("Enter <[%d]current Tournament Place> -> ", i+1);
            scanf("%hu", &commands[i].currentTournamentPlace);
            getchar();

            printf("\n");
        }
        return;

    
    fromFile:
        printf("Enter <filename> with extension -> ");
        fgets(buffer2, LEN2-1, stdin);
        trim(buffer2, filename);

        file = fopen(filename, "r");
        if (!file) {
            printf("Cannot open file");
            exit(1);
        }

        while (fgets(buffer, LEN2, file) != NULL) {
            count++;

            switch (count) {
                case 1:
                    trim(buffer, commands[currentCommand].commandName);
                    break;
                case 2:
                    trim(buffer, commands[currentCommand].trainerName);
                    break;
                case 3:
                    commands[currentCommand].pastTournamentPlace = (unsigned short) atoi(buffer);
                    break;
                case 4:
                    commands[currentCommand].currentTournamentPlace = (unsigned short) atoi(buffer);
                    break;
                case 5:
                    count = 0;
                    currentCommand++; 
                    break;
            }
            
        }
        fclose(file);
        return;
}

void trimNewStringAndInsert(char *str, char *str2) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }

    strcpy(str2, str); 

    return;
}

int processStructArray(command *commands, unsigned n, command **newCommands) {
    int n2 = 0;
    int number = 0;
    int *indexArray = (int *) malloc(n*sizeof(int));
    memset(indexArray, 0, sizeof(int)*n);
    
    for (int i = 0; i < n; i++) {
        if (commands[i].currentTournamentPlace <= commands[i].pastTournamentPlace) {
            indexArray[i] = 1;
            n2++;
        }
    }

    if (n2 == 0) {
        return 0;
    }

    (*newCommands) = (command *) malloc(n2*sizeof(command));
    for (int i = 0; i < n; i++) {
        if (indexArray[i] == 1) {
            memcpy(&((*newCommands)[number]), &(commands[i]), sizeof(command));
            number++;
        }
    }

    return n2;
}

void print(command *commands, unsigned n, void (*trim)(char *, char *)) {
    char numb[LEN1];
    char choose;
    char filename[LEN2];
    char buffer[LEN2];
    FILE *file;
    try:
        printf("Choose type of output:\n1. To file\n2. To console\n");
        scanf("%d", &choose);
        getchar();

        switch (choose) {
            case 1:
                goto toFile;
            case 2:
                goto toConsole;
            default:
                goto try;
        }
    
    
    toConsole:
        for (int i = 0; i < n; i++) {
            printf("Command name = %s\nTrainer name = %s\nPlace in past tournament = %d\nPlace in current tournament = %d\n\n", commands[i].commandName, commands[i].trainerName, commands[i].pastTournamentPlace, commands[i].currentTournamentPlace);
        }
        return;
    
    toFile:
        printf("Enter <filename> with extension -> ");
        fgets(buffer, LEN2-1, stdin);
        trim(buffer, filename);

        file = fopen(filename, "w");

        if (!file) {
            printf("Cannot open file");
            exit(1);
        }
        
        for (int i = 0; i < n; i++) {
            fputs(commands[i].commandName, file);
            fputs("\n", file);

            fputs(commands[i].trainerName, file);
            fputs("\n", file);
            
            sprintf(numb, "%d", commands[i].pastTournamentPlace);
            fputs(numb, file);
            fputs("\n", file);

            sprintf(numb, "%d", commands[i].currentTournamentPlace);
            fputs(numb, file);
            fputs("\n", file);
            fputs("\n", file);

        }
        fclose(file);
        return;     
}

int main() {
    unsigned n, n2;
    command *commands, *newCommands;
    char buffer[LEN1];

    printf("Enter <n> -> ");
    scanf("%u", &n);

    commands = (command *) malloc(n*sizeof(command));
    newCommands = NULL;

    inputStructArray(commands, n, trimNewStringAndInsert, buffer);
    n2 = processStructArray(commands, n, &newCommands);
    free(commands);
    print(newCommands, n2, trimNewStringAndInsert);
    free(newCommands);

    return 0;
}

