#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void overview() {
    printf("\nOverview\n");

    FILE *file = fopen("main.txt", "r");
    if (!file) {
        printf("An error occurred.\n");
        return;
    }

    char line[100];
    int count = 1;
    printf("\n---------------------\n");
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';

        char *title = strtok(line, ":");
        char *description = strtok(NULL, ":");
        char *priority = strtok(NULL, ":");

        if (title != NULL && description != NULL && priority != NULL) {
            printf("\n%d) %s\n%s\n", count, title, description);
            printf("Priority: %s\n", priority);
        } else {
            printf("Invalid format in line: %s\n", line);
        }

        count++;
    }

    printf("\n---------------------\n");

    fclose(file);
}