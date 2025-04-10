#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct soccerCommand {
    char commandName[30];
    char trainerName[30];
    unsigned short pastTournamentPlace;
    unsigned short currentTournamentPlace;
} command;


int main() {
    unsigned n;
    command *commands;
    char buffer[40];


    printf("Enter <n> -> ");
    scanf("%u", &n);
    getchar();

    commands = (command *) malloc(n*sizeof(command));

    for (int i = 0; i < n; i++) {
        printf("Enter <[%d]command Name> -> ", i);
        fgets(commands[i].commandName, 29, stdin);
        
        printf("Enter <[%d]command Trainer Name -> ", i);
        fgets(commands[i].trainerName, 29, stdin);
    }

    for (int i = 0; i < n; i++) {
        printf("Command Name[%d](%c) - %s \nTrainer Name[%d](%c) - %s\n",i ,commands[i].commandName[2] ,commands[i].commandName, i, commands[i].trainerName[2], commands[i].trainerName);
    }

    free(commands);
    return 0;
}

