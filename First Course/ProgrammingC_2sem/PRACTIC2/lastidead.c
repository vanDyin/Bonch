#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN1 30
#define LEN2 19

typedef struct soccerCommand {
    char commandName[LEN1];
    char trainerName[LEN1];
    unsigned short pastTournamentPlace;
    unsigned short currentTournamentPlace;
} command;



void inputStructArray(command *commands, unsigned n, void (*trim)(char *, char *), char *buffer) {
    printf("inputStructArray\n");
    char choose = 0;

    char filename[LEN2] = "";
    int count = 0;
    int currentCommand = 0; 
    char buffer2[LEN2];

    printf("Choose type of input:\n 1. From file \n 2. from console\n");
    try:
        scanf("%d", &choose);
        getchar();
        switch (choose) {
            case 1:
                goto fromFile;
            case 2:
                goto fromConsole;
            default:
                printf("Enter 1 or 2\n");
                goto try;
        }

    fromConsole:
        printf("fromconsole\n");
        for (int i = 0; i < n; i++) {
            printf("Enter <[%d]command Name> -> ", i);
            fgets(buffer, LEN1-1, stdin);
            trim(buffer, commands[i].commandName);

            printf("Enter <[%d]command Trainer Name> -> ", i);
            fgets(buffer, LEN1-1, stdin);
            trim(buffer, commands[i].trainerName);
            
            printf("Enter <[%d]past Tournament Place> -> ", i);
            scanf("%hu", &commands[i].pastTournamentPlace);
            getchar();

            printf("Enter <[%d]current Tournament Place> -> ", i);
            scanf("%hu", &commands[i].currentTournamentPlace);
            getchar();
        }
        return;

    
    fromFile:
        printf("fromfile\n");
        printf("Enter <filename> with extension -> ");
        fgets(buffer2, LEN2-1, stdin);
        trim(buffer2, filename);

        FILE *file = fopen(filename, "r");
        if (!file) {
            printf("Cannot open file");
            exit(1);
        }

        while (fgets(buffer, LEN2, file) != NULL) {
            count++;

            switch (count) {
                case 1:
                    strcpy(commands[currentCommand].commandName, buffer);
                    break;
                case 2:
                    strcpy(commands[currentCommand].trainerName, buffer);
                    break;
                case 3:
                    commands[currentCommand].pastTournamentPlace = (unsigned short) atoi(buffer);
                    break;
                case 4:
                    commands[currentCommand].currentTournamentPlace = (unsigned short) atoi(buffer);
                    break;
                case 5:
                    continue;
                case 6:
                    count = 0;
                    currentCommand++; 
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
    printf("processStructArray\n");
    int number = 0;
    for (int i = 0 ; i< n; i++) {
        if (commands[i].pastTournamentPlace <= commands[i].currentTournamentPlace) {;
            *newCommands = (command *) realloc(*newCommands, sizeof(command) * (number+1));
            if (!*newCommands) {
                printf("Error with memory!\n");
                exit(1);
            }
            memcpy(&(*newCommands[number]), &commands[i], sizeof(command)); 
            number++;
        }
    }
    return number;
}

void print(command *commands, unsigned n) {
    printf("print\n");
    for (int i = 0; i < n; i++) {
        printf("Command name = %s\nTrainer name = %s\nPlace in past tournament = %d\nPlace in current tournament %d\n\n", commands[i].commandName, commands[i].trainerName, commands[i].pastTournamentPlace, commands[i].currentTournamentPlace);
    }
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

    n2 = (unsigned) processStructArray(commands, n, &newCommands);
    free(commands);

    print(newCommands, n2);

    free(newCommands);
    return 0;
}

