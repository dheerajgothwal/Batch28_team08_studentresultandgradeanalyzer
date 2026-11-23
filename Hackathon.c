#include <stdio.h>
#include <string.h>

#define SUBJECTS 5

struct Student 
{
    char name[50];
    int marks[5];
    int total;
    float percentage;
    char grade[3];
    int passed;
};

int main() 
{
    int n, i, j, min_mark;
    int pass_count = 0, topper = 0;
    float class_total = 0;

    const char allowed[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    const char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];
    do {
        printf("Enter minimum pass marks (0-100): ");
        scanf("%d", &min_mark);
        if (min_mark < 0 || min_mark > 100) {
            printf("Invalid! Pass marks must be between 0 and 100.\n");
        }
    } while (min_mark < 0 || min_mark > 100);

    for (i = 0; i < n; i++) 
    {
        int valid_name = 0;
        do {
            printf("\nEnter name of student %d: ", i + 1);
            scanf(" %[^\n]", s[i].name);

            int only_letters_and_spaces = (strspn(s[i].name, allowed) == strlen(s[i].name));

            int has_at_least_one_letter = (strpbrk(s[i].name, letters) != NULL);

            if (only_letters_and_spaces && has_at_least_one_letter) {
                valid_name = 1;
            } else {
                printf("Invalid name! Only letters and spaces are allowed. Try again.\n");
            }
        } while (!valid_name);

        s[i].total = 0;
        s[i].passed = 1;

        for (j = 0; j < SUBJECTS; j++) 
        {
            do {
                printf("Enter marks in subject %d (0-100): ", j + 1);
                scanf("%d", &s[i].marks[j]);
                if (s[i].marks[j] < 0 || s[i].marks[j] > 100) {
                    printf("Invalid marks! Must be between 0 and 100. Try again.\n");
                }
            } while (s[i].marks[j] < 0 || s[i].marks[j] > 100);

            s[i].total += s[i].marks[j];
            if (s[i].marks[j] < min_mark)
                s[i].passed = 0;
        }
             s[i].percentage = s[i].total / 5.0;

        if (s[i].passed == 0)
            strcpy(s[i].grade, "F");
        else if (s[i].percentage >= 90)
            strcpy(s[i].grade, "A+");
        else if (s[i].percentage >= 80)
            strcpy(s[i].grade, "A");
        else if (s[i].percentage >= 70)
            strcpy(s[i].grade, "B");
        else if (s[i].percentage >= 60)
            strcpy(s[i].grade, "C");
        else if (s[i].percentage >= 50)
            strcpy(s[i].grade, "D");
        else
            strcpy(s[i].grade, "E");
    }

    printf("\n===== STUDENT RESULTS =====\n");
    for (i = 0; i < n; i++) {
        printf("\nName: %s\n", s[i].name);
        printf("Total: %d / 500\n", s[i].total);
        printf("Percentage: %.2f%%\n", s[i].percentage);
        printf("Grade: %s\n", s[i].grade);
        if (s[i].passed)
            printf("Status: PASS\n");
        else
            printf("Status: FAIL\n");
    }

    for (i = 0; i < n; i++) {
        class_total += s[i].total;
        if (s[i].passed)
            pass_count++;
        if (s[i].total > s[topper].total)
            topper = i;
    }

    printf("\n===== CLASS REPORT =====\n");
    printf("Total students: %d\n", n);
    printf("Passed: %d\n", pass_count);
    printf("Failed: %d\n", n - pass_count);
    printf("Pass percentage: %.2f%%\n", pass_count * 100.0 / n);
    printf("Class average: %.2f\n", class_total / n);
    printf("\nClass Topper: %s\n", s[topper].name);
    printf("Highest marks: %d\n", s[topper].total);

    return 0;
}
