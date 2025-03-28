//C project Code: Student Result Management System

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 4
#define SUBJECTS 3

// Structure to store student info
struct Student {
    char name[50];
    int roll;
    float marks[SUBJECTS];
    float average;
};

// Function declarations
void inputStudentData(struct Student students[], int n);
void calculateAverages(struct Student students[], int n);
void showResults(struct Student students[], int n);
void findTopAndLowest(struct Student students[], int n);

int main() {
    int n;
    struct Student students[MAX_STUDENTS];

    printf("Enter number of students (max %d): ", MAX_STUDENTS);
    scanf("%d", &n);

    inputStudentData(students, n);
    calculateAverages(students, n);
    showResults(students, n);
    findTopAndLowest(students, n);

    return 0;
}

// Function to input data
void inputStudentData(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter info for Student %d:\n", i + 1);
        printf("Name: ");
        getchar(); // to clear buffer
        gets(students[i].name);
        printf("Roll: ");
        scanf("%d", &students[i].roll);
        printf("Enter marks in %d subjects: ", SUBJECTS);
        for (int j = 0; j < SUBJECTS; j++) {
            scanf("%f", &students[i].marks[j]);
        }
    }
}

// Function to calculate average
void calculateAverages(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        float sum = 0;
        for (int j = 0; j < SUBJECTS; j++) {
            sum += students[i].marks[j];
        }
        students[i].average = sum / SUBJECTS;
    }
}

// Function to show pass/fail and average
void showResults(struct Student students[], int n) {
    printf("\n----Result Summary----\n");
    for (int i = 0; i < n; i++) {
        printf("%s (Roll: %d): ", students[i].name, students[i].roll);
        if (students[i].average >= 40)
            printf("Pass | ");
        else
            printf("Fail | ");
        printf("Average: %.2f\n", students[i].average);
    }
}

// Function to find top and lowest scorer
void findTopAndLowest(struct Student students[], int n) {
    int top = 0, low = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].average > students[top].average)
            top = i;
        if (students[i].average < students[low].average)
            low = i;
    }

    printf("\nTop Scorer: %s (%.2f)\n", students[top].name, students[top].average);
    printf("Lowest Scorer: %s (%.2f)\n", students[low].name, students[low].average);
}
