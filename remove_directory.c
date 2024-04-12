#include <stdio.h>
#include <unistd.h>

int main() {
    char directory[100];
    
    printf("Enter the directory path to remove: ");
    scanf("%s", directory);
    
    int status = rmdir(directory);
    
    if (status == 0) {
        printf("Directory removed successfully.\n");
    } else {
        printf("Failed to remove directory.\n");
    }
    
    return 0;
}
