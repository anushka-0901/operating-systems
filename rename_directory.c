#include <stdio.h>
#include <stdlib.h>

int main() {
    char oldName[100], newName[100];
    
    printf("Enter the current name of the directory: ");
    scanf("%s", oldName);
    
    printf("Enter the new name for the directory: ");
    scanf("%s", newName);
    
    // Construct the command to rename the directory using the mv command
    char command[200];
    sprintf(command, "mv %s %s", oldName, newName);
    
    // Execute the command using system()
    int status = system(command);
    
    if (status == -1) {
        printf("Failed to rename the directory.\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Directory renamed successfully!\n");
    return 0;
}
