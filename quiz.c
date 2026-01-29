#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "quiz.h"

void shuffle_questions(struct Question q[], int n) {
    int i, j;
    struct Question temp;

    srand(time(NULL));

    for (i = n - 1; i > 0; i--) {
        j = rand() % (i + 1);

        temp = q[i];
        q[i] = q[j];
        q[j] = temp;
    }
}

void start_quiz() {
    struct Question q[100];
    FILE *fp = fopen(FILE_NAME, "rb");
    int i, score = 0;
    int serial_no = 0;
    int count = 0;
    char answer;

    if (!fp) {
        printf("\nFile not found!\n\n");
        return;
    }

    while (fread(&q[count], sizeof(struct Question), 1, fp)) {
        count++;
    }

    shuffle_questions(q, count);
    
    
    for (i = 0; i < count; i++) {
        printf("%d. %s\n\n", ++serial_no, q[i].question);
        printf("A. %s\n", q[i].optionA);
        printf("B. %s\n", q[i].optionB);
        printf("C. %s\n", q[i].optionC);
        printf("D. %s\n\n", q[i].optionD);
        printf("Enter your answer (A/B/C/D): ");
        scanf(" %c", &answer);
        printf("\n");

        if (answer == q[i].correct || answer == q[i].correct + 32) {
            score++;
        } else{
            printf("Wrong answer!\n");
            printf("Correct answer: %c\n\n", q[i].correct);
            score--;
        }
    }

    if (score < 0)
        score = 0;
    
    printf("Quiz finished!\n");
    printf("Your score is: %d/%d\n\n", score, count);
    fclose(fp);
}

void add_questions() {
    struct Question q;
    FILE *fp = fopen(FILE_NAME, "ab");
    char choice;

    do {
        printf("\nEnter your question: ");
        scanf(" %[^\n]", q.question);

        printf("\nEnter option A: ");
        scanf(" %[^\n]", q.optionA);

        printf("\nEnter option B: ");
        scanf(" %[^\n]", q.optionB);

        printf("\nEnter option C: ");
        scanf(" %[^\n]", q.optionC);

        printf("\nEnter option D: ");
        scanf(" %[^\n]", q.optionD);

        printf("\nEnter correct option: ");
        scanf(" %c", &q.correct);

        fwrite(&q, sizeof(struct Question), 1, fp);

        printf("\nAdd another question (y/n)? ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    fclose(fp);
}