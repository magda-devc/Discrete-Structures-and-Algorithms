#include <stdio.h>
#include <string.h>

struct Course {
    char course_code[10];
    char course_name[50];
};

struct Grade {
    int mark;
    char the_grade;
};

struct Student {
    char registration_number[21];
    char name[51];
    int age;
    struct Course course;
    struct Grade grades;
    int marks_added;
};

void addStudent(struct Student students[], int *num_students);
void editStudent(struct Student students[], int num_students);
void addMarks(struct Student students[], int num_students);

int main() {
    struct Student students[40];
    int num_students = 0;
    int choice;

    do {
        printf("\n1. Add Student\n2. Edit Student\n3. Add Marks\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent(students, &num_students);
                break;
            case 2:
                editStudent(students, num_students);
                break;
            case 3:
                addMarks(students, num_students);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while(choice != 4);

    return 0;
}

void addStudent(struct Student students[], int *num_students) {
    if (*num_students < 40) {
        printf("Enter registration number: ");
        scanf("%20s", students[*num_students].registration_number);

        printf("Enter name: ");
        scanf("%50s", students[*num_students].name);

        printf("Enter age: ");
        scanf("%d", &students[*num_students].age);

        printf("Enter course code: ");
        scanf("%9s", students[*num_students].course.course_code);

        printf("Enter course name: ");
        scanf("%49s", students[*num_students].course.course_name);

        students[*num_students].marks_added = 0; // Initialize marks_added flag
        (*num_students)++;
        printf("Student added successfully.\n");
    } else {
        printf("Maximum limit of students reached.\n");
    }
}

void editStudent(struct Student students[], int num_students) {
    char reg_num[21];
    printf("Enter registration number of the student to edit: ");
    scanf("%20s", reg_num);

    for (int i = 0; i < num_students; ++i) {
        if (strcmp(students[i].registration_number, reg_num) == 0) {
            printf("Enter new registration number: ");
            scanf("%20s", students[i].registration_number);

            printf("Enter new name: ");
            scanf("%50s", students[i].name);

            printf("Enter new age: ");
            scanf("%d", &students[i].age);

            printf("Enter new course code: ");
            scanf("%9s", students[i].course.course_code);

            printf("Enter new course name: ");
            scanf("%49s", students[i].course.course_name);

            printf("Student details updated successfully.\n");
            return;
        }
    }

    printf("Student not found with given registration number.\n");
}

void addMarks(struct Student students[], int num_students) {
    char reg_num[21];
    printf("Enter registration number of the student: ");
    scanf("%20s", reg_num);

    for (int i = 0; i < num_students; ++i) {
        if (strcmp(students[i].registration_number, reg_num) == 0) {
            if (students[i].marks_added) {
                printf("Marks for this student are already added.\n");
            } else {
                printf("Enter mark for student %s: ", students[i].name);
                scanf("%d", &students[i].grades.mark);

                if (students[i].grades.mark > 69) {
                    students[i].grades.the_grade = 'A';
                } else if (students[i].grades.mark > 59) {
                    students[i].grades.the_grade = 'B';
                } else if (students[i].grades.mark > 49) {
                    students[i].grades.the_grade = 'C';
                } else if (students[i].grades.mark > 39) {
                    students[i].grades.the_grade = 'D';
                } else {
                    students[i].grades.the_grade = 'E';
                }

                students[i].marks_added = 1;
                printf("Grade calculated successfully.\n");
            }
            return;
        }
    }

    printf("Student not found with given registration number.\n");
}
