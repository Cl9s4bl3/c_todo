#include <stdio.h>
#include <string.h>

static void clearBuffer(){
    while(getchar() != '\n');
}

void addTask(){
    char title[18];
    char description[66];
    int priority;

    printf("\nEnter a title: ");

    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0';

    if (strlen(title) > 16) {
        printf("\nTitle is too long! Please limit to 16 characters.\n");
        clearBuffer();
        return;
    }

    printf("Enter a description: ");

    fgets(description, sizeof(description), stdin);
    description[strcspn(description, "\n")] = '\0'; 

    if (strlen(description) > 64) {
        printf("\nDescription is too long! Please limit to 64 characters.\n");
        clearBuffer();
        return;
    }

    printf("Enter the priority: ");

    if (scanf("%d", &priority) != 1){
        printf("\nInvalid number.\n");
        clearBuffer();
        return;
    }

    if (priority > 5 || priority < 1){
        printf("\nPriority needs to be between 1-5.\n");
        clearBuffer();
        return;
    }

    FILE *file = fopen("main.txt", "a");
    if (file == NULL){
        printf("File does not exist.");
        return;
    } else {
        fprintf(file, "%s:%s:%d\n", title, description, priority);
    }

    fclose(file);

    printf("\nSuccessfully added task '%s'.\n", title);
    clearBuffer();
}