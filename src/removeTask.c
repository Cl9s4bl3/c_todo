#include <stdio.h>
#include <string.h>


static void clearBuffer(){
    while(getchar() != '\n');
}

void removeLatest(){

    char confirmation[4];

    printf("Are you sure (yes/no)? ");
    scanf("%4s", confirmation);

    if (strcmp(confirmation, "yes") != 0){
        printf("\nExiting...\n");
        clearBuffer();
        return;
    }

    FILE *read_file = fopen("main.txt", "r");
    if (!read_file){
        printf("An error occurred.");
        return;
    }

    FILE *temp_file = fopen("temp.txt", "w");
    if (!temp_file){
        printf("An error occurred.");
        return;
    }

    char lines[1000][100];
    int count = 0;

    while (fgets(lines[count], 100, read_file)){
        count++;
    }
    fclose(read_file);

    if (count == 0){
        remove("temp.txt");
        printf("\nNo tasks have been added\n");
        clearBuffer();
        return;
    }

    for (int i = 0; i < count - 1; i++){
        fputs(lines[i], temp_file);
    }

    fclose(temp_file);

    remove("main.txt");
    rename("temp.txt", "main.txt");

    printf("\nSuccessfully deleted lastest task\n");

    clearBuffer();

}