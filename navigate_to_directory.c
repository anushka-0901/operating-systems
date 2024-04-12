#include <stdio.h>
#include <unistd.h>

int main() {
    char directory[100];
    printf("Enter the directory path: ");
    scanf("%s", directory);

    if (chdir(directory) == 0) {
        printf("Directory changed successfully.\n");
    } else {
        printf("Failed to change directory.\n");
    }
    
    return 0;
}
