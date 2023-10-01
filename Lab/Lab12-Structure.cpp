/*
    จงเขียนฟังก์ชันการตัดเกรดในแต่ละรายวิชาของนักเรียนจำนวน 3 คน โดยนักเรียนแต่ละคนจะมีข้อมูลดังต่อไปนี้
    ชื่อ, นักศักศึกษา, คะแนนในวิชาที่ 1, คะแนนในวิชาที่ 2, คะแนนในวิชาที่ 3, คะแนนในวิชาที่ 4, คะแนนในวิชาที่ 5
    แสดงได้ดังโครงสร้างข้อมูลต่อไปนี้

    struct Student {
        char Name[20] ;
        char ID[5] ;
        float ScoreSub1 ;
        float ScoreSub2 ;
        float ScoreSub3 ;
        float ScoreSub4 ;
        float ScoreSub5 ;
    } typedef S ;

    Test Case:
        Enter the details of 3 students :
        Student 1:
        Name: 
            John Doe
        ID: 
            101
        Scores in Subject 1: 
            77
        Scores in Subject 2: 
            64
        Scores in Subject 3: 
            66
        Scores in Subject 4: 
            54
        Scores in Subject 5: 
            56

        Student 2:
        Name: 
            Jane Smith
        ID: 
            102
        Scores in Subject 1: 
            43
        Scores in Subject 2: 
            70
        Scores in Subject 3: 
            76
        Scores in Subject 4: 
            77
        Scores in Subject 5: 
            80

        Student 3:
        Name: 
            Mark Johnson
        ID: 
            103
        Scores in Subject 1: 
            77
        Scores in Subject 2: 
            74
        Scores in Subject 3: 
            76
        Scores in Subject 4: 
            81
        Scores in Subject 5: 
            69

    Output:
    Student Details:
    Student 1:
    Name: John Doe
    ID: 101
    Scores: 77 64 66 54 56
    Grades: B+  C C+ D  D+
    Average Scores: 63.4

    Student 2:
    Name: Jane Smith
    ID: 102
    Scores: 43 70 76 77 80
    Grades:  F  B B+ B+  A
    Average Scores: 69.2

    Student 3:
    Name: Mark Johnson
    ID: 103
    Scores: 77 74 76 81 69
    Grades: B+  B B+  A C+
    Average Scores: 75.4jnp
*/

#include <stdio.h>

struct Student {
    char Name[20];
    char ID[5];
    float ScoreSub1;
    float ScoreSub2;
    float ScoreSub3;
    float ScoreSub4;
    float ScoreSub5;
};

typedef struct Student S;

// Function to calculate the grade based on the score
char calculateGrade(float score) {
    if (score >= 90) {
        return 'A';
    } else if (score >= 80) {
        return 'B';
    } else if (score >= 70) {
        return 'C';
    } else if (score >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

void calculateGradesAndAverage(S student) {
    printf("Name: %s\n", student.Name);
    printf("ID: %s\n", student.ID);
    printf("Scores: %.2f %.2f %.2f %.2f %.2f\n",
           student.ScoreSub1, student.ScoreSub2, student.ScoreSub3,
           student.ScoreSub4, student.ScoreSub5);

    // Calculate average score
    float average = (student.ScoreSub1 + student.ScoreSub2 +
                     student.ScoreSub3 + student.ScoreSub4 +
                     student.ScoreSub5) / 5.0;
    printf("Average Scores: %.1f\n", average);

    // Calculate and display grades for each subject
    printf("Grades: ");
    printf("%c %c %c %c %c\n",
           calculateGrade(student.ScoreSub1),
           calculateGrade(student.ScoreSub2),
           calculateGrade(student.ScoreSub3),
           calculateGrade(student.ScoreSub4),
           calculateGrade(student.ScoreSub5));
    printf("\n");
}

int main() {
    S students[3];

    printf("Enter the details of 3 students:\n");

    for (int i = 0; i < 3; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].Name);
        printf("ID: ");
        scanf("%s", students[i].ID);
        printf("Scores in Subject 1: ");
        scanf("%f", &students[i].ScoreSub1);
        printf("Scores in Subject 2: ");
        scanf("%f", &students[i].ScoreSub2);
        printf("Scores in Subject 3: ");
        scanf("%f", &students[i].ScoreSub3);
        printf("Scores in Subject 4: ");
        scanf("%f", &students[i].ScoreSub4);
        printf("Scores in Subject 5: ");
        scanf("%f", &students[i].ScoreSub5);
    }

    printf("Student Details:\n");

    for (int i = 0; i < 3; i++) {
        printf("Student %d:\n", i + 1);
        calculateGradesAndAverage(students[i]);
    }

    return 0;
}
