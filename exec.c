#include <stdio.h>
#include <unistd.h>

int main()
{

printf("Executing ls command using execvp() system
call.\n");
char *args[] = {"ls", "-l", NULL};
execvp(args[0], args);
printf("execvp() system call failed.\n");
return 0;
}