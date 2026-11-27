# Batch28_team08_studentresultandgradeanalyzer
# Student Result Management System (C)

A console-based C program that takes marks for multiple students, calculates their totals, percentages and grades, decides pass/fail, and prints an individual result sheet along with a class summary report.

## Features

- Accepts any number of students (uses a variable-length array of structs)
- Validates all input:
  - Minimum pass marks must be between 0 and 100
  - Student names may contain only letters and spaces (at least one letter required)
  - Marks for each subject must be between 0 and 100
- Calculates total (out of 500) and percentage for each student
- Assigns a grade based on percentage
- Pass/fail rule: a student fails if they score below the minimum pass marks in **any** subject
- Prints a class report: total students, passed, failed, pass percentage, class average, and the class topper

## Grading Scheme

| Percentage | Grade |
|------------|-------|
| 90 and above | A+ |
| 80 – 89.99 | A |
| 70 – 79.99 | B |
| 60 – 69.99 | C |
| 50 – 59.99 | D |
| Below 50 | E |
| Failed any subject (below minimum pass marks) | F |

## How It Works

1. The user enters the number of students and the minimum pass marks per subject.
2. For each student, the program reads and validates the name, then marks in 5 subjects.
3. The total and percentage (`total / 5.0`) are computed, and the student is flagged as failed if any subject mark is below the pass mark.
4. The grade is assigned using the scheme above (a failed student always gets `F`).
5. Results for every student are displayed, followed by the class report.

## Data Structure

```c
struct Student {
    char  name[50];
    int   marks[5];
    int   total;
    float percentage;
    char  grade[3];
    int   passed;
};
```

## Compile and Run

Requires a C compiler such as GCC.

```bash
gcc student_result.c -o student_result
./student_result
```

On Windows:

```bash
gcc student_result.c -o student_result.exe
student_result.exe
```

(Replace `student_result.c` with whatever you named your source file.)

## Sample Input / Output

**Input**

```
Enter number of students: 2
Enter minimum pass marks (0-100): 40

Enter name of student 1: Aman Sharma
Enter marks in subject 1 (0-100): 85
Enter marks in subject 2 (0-100): 90
Enter marks in subject 3 (0-100): 78
Enter marks in subject 4 (0-100): 88
Enter marks in subject 5 (0-100): 92

Enter name of student 2: Riya Verma
Enter marks in subject 1 (0-100): 35
Enter marks in subject 2 (0-100): 60
Enter marks in subject 3 (0-100): 55
Enter marks in subject 4 (0-100): 70
Enter marks in subject 5 (0-100): 65
```

**Output**

```
===== STUDENT RESULTS =====

Name: Aman Sharma
Total: 433 / 500
Percentage: 86.60%
Grade: A
Status: PASS

Name: Riya Verma
Total: 285 / 500
Percentage: 57.00%
Grade: F
Status: FAIL

===== CLASS REPORT =====
Total students: 2
Passed: 1
Failed: 1
Pass percentage: 50.00%
Class average: 359.00

Class Topper: Aman Sharma
Highest marks: 433
```

## Concepts Used

- Structures (`struct`) and arrays of structures
- Variable-length arrays (VLA)
- Loops (`for`, `do-while`) and nested loops
- Conditional statements (`if-else if` ladder)
- String functions: `strcpy`, `strlen`, `strspn`, `strpbrk`
- Input validation using loops

## Limitations

- The number of subjects is fixed at 5 (`SUBJECTS` is defined, but the `marks` array and the percentage calculation use `5` directly).
- Names are read with `scanf(" %[^\n]")` without a width limit, so names longer than 49 characters can overflow the buffer.
- Non-numeric input for numbers (e.g. typing letters for marks) is not handled.
- The number of students is not validated (it should be greater than 0).
- Ties for the topper are not reported; the first student with the highest total is shown.

## Possible Improvements

- Use `SUBJECTS` consistently instead of the hard-coded `5`
- Add width limits to `scanf` (e.g. `%49[^\n]`)
- Validate the number of students and handle invalid numeric input
- Save results to a file
- Add subject-wise names and subject-wise highest marks
