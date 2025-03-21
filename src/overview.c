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

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';  // Remove the newline character

        // Tokenize the line using ':' as the delimiter
        char *title = strtok(line, ":");  // The first token is the title
        char *description = strtok(NULL, ":");  // The second token is the description
        char *priority = strtok(NULL, ":");  // The third token is the priority

        // Check if all parts were successfully extracted
        if (title != NULL && description != NULL && priority != NULL) {
            // Print the formatted output
            printf("\n%s: %s\n", title, description);
            printf("Priority: %s\n", priority);
        } else {
            // Handle the case where the input format is incorrect
            printf("Invalid format in line: %s\n", line);
        }
    }

    fclose(file);
}