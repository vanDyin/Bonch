#include <stdio.h>
#include <string.h>

#define LEN 128
#define NUM_STUDENTS 3


typedef struct stud {
    char name[LEN];
    char group[LEN];
    int grades[5];  
} student;


void structInput(student students[NUM_STUDENTS]) {
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Student[%d] name -> ", i+1);
        fgets(students[i].name, LEN, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        printf("Student[%d] group -> ", i+1);
        fgets(students[i].group, LEN, stdin);
        students[i].group[strcspn(students[i].group, "\n")] = '\0';

        printf("Student[%d] progress (x x x x x) -> ", i+1);
        for (int j = 0; j < 5; j++) {
            scanf("%d", &students[i].grades[j]);
        }

        while (getchar() != '\n');
        printf("\n");
    }   
}

int task1(student students[NUM_STUDENTS], student newStudents[NUM_STUDENTS]) {
    int count = 0;
    for (int i = 0; i < NUM_STUDENTS; i++) {
        float sum = 0;
        
        for (int j = 0; j < 5; j++) {
            sum += students[i].grades[j];
        }
        
        float middle = sum / 5;
        
        if (middle > 4.0) {
            newStudents[count] = students[i];
            count++;
        }
    }

    return count;  
}

int task2(student students[NUM_STUDENTS], student newStudents[NUM_STUDENTS]) {
    int count = 0;

    for (int i = 0; i < NUM_STUDENTS; i++) {
        char flag = 0;

        for (int j = 0; j < 5; j++) {
            if (students[i].grades[j] < 4) {
                flag = 1;
                break;
            }
        }

        if (!flag) {
            newStudents[count] = students[i];
            count++;
        }

    }

    return count;
}

int task3(student students[NUM_STUDENTS], student newStudents[NUM_STUDENTS]) {
    int count = 0;

    for (int i = 0; i < NUM_STUDENTS; i++) {

        for (int j = 0; j < 5; j++) {
            if (students[i].grades[j] == 2) {
                newStudents[count]=students[i];
                count++;
                break;
            }
        }
    }

    return count;
}

void printStruct(student students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("[%d] student\n", i+1);
        printf("Name: %s\n", students[i].name);
        printf("Group: %s\n", students[i].group);
        printf("\n");
    }
}

int main() {
    student STUDENTS[NUM_STUDENTS];
    student NEWSTUDENTS[NUM_STUDENTS];
    student NEWSTUDENTS2[NUM_STUDENTS];
    student NEWSTUDENTS3[NUM_STUDENTS];


    structInput(STUDENTS);

    int count1 = task1(STUDENTS, NEWSTUDENTS);
    if (count1 == 0) {
        printf("There are no students with average grade > 4.0\n");
    } else {
        printf("\nStudents with average grade > 4.0:\n");
        printStruct(NEWSTUDENTS, count1);
    }

    int count2 = task2(STUDENTS, NEWSTUDENTS2);
    if (count2 == 0) {
        printf("There are no students, who only have 4 and 5\n");
    } else {
        printf("\nStudents, who have only 4 and 5:\n");
        printStruct(NEWSTUDENTS2, count2);
    }

    int count3 = task3(STUDENTS, NEWSTUDENTS3);
    if (count3 == 0) {
        printf("There are no students, who have 2\n");
    } else {
        printf("\nStudents, who have 2:\n");
        printStruct(NEWSTUDENTS3, count3);
    }

    return 0;
}