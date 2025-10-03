#include <stdio.h>
#include <string.h>

#define LEN 128
#define NUM 2

typedef struct
{
    char destination[LEN];
    int number;
    char typeOfAirplane[LEN];
} AEROFLOT;

void structInput(AEROFLOT aeroflots[NUM]) {
    for (int i = 0; i < NUM; i++) {
        printf("aeroflot[%d] destination -> ", i+1);
        fgets(aeroflots[i].destination, LEN, stdin);
        aeroflots[i].destination[strcspn(aeroflots[i].destination, "\n")] = '\0';

        printf("aeroflot[%d] number -> ", i+1);
        scanf("%d", &aeroflots[i].number);
        getchar();

        printf("aeroflot[%d] airplane type -> ", i+1);
        fgets(aeroflots[i].typeOfAirplane, LEN, stdin);
        aeroflots[i].typeOfAirplane[strcspn(aeroflots[i].typeOfAirplane, "\n")] = '\0';

        printf("\n");
    }   
}

int task1(AEROFLOT aeroflots[NUM], AEROFLOT newAeroflots[NUM], char destination[LEN]) {
    int count = 0;

    for (int i = 0; i < NUM; i++) {
        if (strcmp(aeroflots[i].destination, destination) == 0) {
            newAeroflots[count] = aeroflots[i];
            count++;
        }
    }

    return count;
}

int task2(AEROFLOT aeroflots[NUM], AEROFLOT newAeroflots[NUM], char typeOfAirplane[LEN]) {
    int count = 0;

    for (int i = 0; i < NUM; i++) {
        if (strcmp(aeroflots[i].typeOfAirplane, typeOfAirplane) == 0) {
            newAeroflots[count] = aeroflots[i];
            count++;
        }
    }

    return count;
}


void printStruct(AEROFLOT aerloflots[NUM], int count, int choice) {

    switch (choice)
    {
    case 1:
        for (int i = 0; i < count; i++) {
            printf("[%d] aeroflot\n", i+1);
            printf("Airplane type: %s\n", aerloflots[i].typeOfAirplane);
            printf("number: %d\n", aerloflots[i].number);
            printf("\n");
        }
        break;
    
    case 2:
        for (int i = 0; i < count; i++) {
            printf("[%d] aeroflot\n", i+1);
            printf("destination: %s\n", aerloflots[i].destination);
            printf("number: %d\n", aerloflots[i].number);
            printf("\n");
        }
        break;

    default:
        printf("Error\n");
        break;
    }
    
}

int main() {
    AEROFLOT aeroflots[NUM], newAeroflots1[NUM], newAeroflots2[NUM];
    char typeOfAirplane[LEN], destination[LEN];


    structInput(aeroflots);


    printf("Enter your destination -> ");
    fgets(destination, LEN, stdin);
    destination[strcspn(destination, "\n")] = '\0';

    int count1 = task1(aeroflots, newAeroflots1, destination);
    if (count1 == 0) {
        printf("There are no aeroflots with that destination(%s)\n", destination);
    } else {
        printf("\nThere are aeroflots with that destination(%s):\n", destination);
        printStruct(newAeroflots1, count1, 1);
    }


    printf("Enter your Airplane type -> ");
    fgets(typeOfAirplane, LEN, stdin);
    typeOfAirplane[strcspn(typeOfAirplane, "\n")] = '\0';

    int count2 = task2(aeroflots, newAeroflots2, typeOfAirplane);
    if (count2 == 0) {
        printf("There are no aeroflots with that Airplane type(%s)\n", typeOfAirplane);
    } else {
        printf("\nThere are aeroflots with that Airplane type(%s):\n", typeOfAirplane);
        printStruct(newAeroflots2, count2, 2);
    }
    
    return 0;
}
