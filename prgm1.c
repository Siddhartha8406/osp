#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t child_pid;
    char ch[3];
    child_pid = fork();
    if (child_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (child_pid == 0)
    {
        printf("Child process (PID: %d) is running.\n", getpid());
        execl("/bin/date", "date", NULL);
        exit(0);
    }
    else
    {

        printf("Parent process (PID: %d) is waiting for the child to terminate.\n", getpid());

        int status;
        wait(&status);

        printf("parent resumes\n");
        if (WIFEXITED(status))
        {
            printf("\nChild process (PID: %d) terminated with status %d.\n", child_pid, WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status))
        {
            printf("\nChild process (PID: %d) terminated due to signal %d.\n", child_pid, WTERMSIG(status));
        }
        else
        {
            printf("\nChild process (PID: %d) terminated abnormally.\n", child_pid);
        }
    }
    return 0;
}