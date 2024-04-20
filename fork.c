#include <stdio.h>

#include <unistd.h>

#include <sys/types.h>
int main()
{
pid_t pid;

int count = 0;
pid = fork(); // create a child process
if (pid == 0) { // child process
printf("Child process is running.\n");
} else if (pid > 0) { // parent process
printf("Parent process is running.\n");
wait(NULL); // wait for child to complete
printf("Child process has completed.\n");
} else { // fork failed
printf("Fork failed.\n");
return 1;
}
return 0;
}