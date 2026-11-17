/*
 * Q4: else-if Ladder or switch?
 * Grade classification written both ways, then compared on boundary values.
 * S: 90-100, A: 80-89, B: 70-79, C: 60-69, D: 50-59, F: 0-49, ?: invalid.
 */

#include <stdio.h>

/* switch version: marks / 10 groups the range into fixed integer cases */
char grade(int marks)
{
    if (marks < 0 || marks > 100)
        return '?';

    switch (marks / 10)
    {
        case 10:
        case 9:
            return 'S';
        case 8:
            return 'A';
        case 7:
            return 'B';
        case 6:
            return 'C';
        case 5:
            return 'D';
        default:
            return 'F';
    }
}

/* else-if ladder version: natural for ranges */
char grade_ladder(int marks)
{
    char g;

    if (marks < 0 || marks > 100)
        g = '?';
    else if (marks >= 90)
        g = 'S';
    else if (marks >= 80)
        g = 'A';
    else if (marks >= 70)
        g = 'B';
    else if (marks >= 60)
        g = 'C';
    else if (marks >= 50)
        g = 'D';
    else
        g = 'F';

    return g;
}

/* lookup-table version: O(1), 11 bytes */
char grade_table(int marks)
{
    static const char grades[11] =
        {'F','F','F','F','F','D','C','B','A','S','S'};

    if (marks < 0 || marks > 100)
        return '?';
    return grades[marks / 10];
}

int main(void)
{
    int marks[] = {100, 95, 83, 50, 49, -5};

    for (int i = 0; i < 6; i++)
    {
        printf("%d:%c ", marks[i], grade(marks[i]));
    }
    printf("\n");

    /* Boundary comparison of the three methods */
    int tests[] = {100, 90, 89, 0, -1, 101};
    printf("\nMarks  else-if  switch  table\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%5d  %7c  %6c  %5c\n", tests[i],
               grade_ladder(tests[i]), grade(tests[i]), grade_table(tests[i]));
    }

    return 0;
}
