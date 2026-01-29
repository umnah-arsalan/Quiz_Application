#include<stdio.h>
#include<stdlib.h>
#include "quiz.h"

int main() {
    int choice;

    printf("-------QUIZ APPLICATION-------\n\n");
    printf("1. Start quiz.\n");
    printf("2. Add questions.\n");
    printf("3. Save and exit.\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        start_quiz();
    } else if (choice == 2) {
        add_questions();
    } else {
        exit(0);
    }

    return 0;
}