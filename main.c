#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "headers/header.h"

static void clearBuffer(){
    while(getchar() != '\n');
}

int main() {
    printf("Welcome to DoTo!\n");

    while (1) {
        char action[100];
        int action_int;
        char *endptr;

        printf("\nAvailable actions:\n1) Add task\n");

        printf("Enter an action: ");
        if (fgets(action, sizeof(action), stdin) == NULL) {
            printf("\nError reading input.\n");
            clearBuffer();
            continue;
        }

        action[strcspn(action, "\n")] = '\0';

        if (strcmp(action, "") == 0) {
            printf("\nInvalid action. Please enter a valid number.\n");
            continue;
        }

        action_int = strtol(action, &endptr, 10);

        if (*endptr != '\0') {
            printf("\nInvalid action. Please enter a valid number.\n");
            continue;
        }

        switch (action_int) {
            case 1:
                addTask();
                break;
            default:
                printf("\nInvalid action.\n");
                break;
        }
    }

    return 0;
}