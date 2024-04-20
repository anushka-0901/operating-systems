#include <stdio.h>

#include <unistd.h>

#include <sys/wait.h>
int main()
{
pid_t pid;
int status;
pid = fork();
if (pid == 0) { // child process
printf("Child process is running.\n");
sleep(2);
printf("Child process is exiting.\n");
return 10;
} else if (pid > 0) { // parent process

printf("Parent process is waiting for child to
complete.\n");
wait(&status); // wait for child to complete and get
its exit status

printf("Child exit status: %d\n",
WEXITSTATUS(status));
} else { // fork failed
printf("Fork failed.\n");
return 1;
}
return 0;
}