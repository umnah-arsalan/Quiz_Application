#ifndef QUIZ_H
#define QUIZ_H

#define FILE_NAME "questions.dat"

struct Question {
    char question[200];
    char optionA[100];
    char optionB[100];
    char optionC[100];
    char optionD[100];
    char correct;
};

void shuffle_questions(struct Question q[], int n);
void start_quiz(void);
void add_questions(void);

#endif