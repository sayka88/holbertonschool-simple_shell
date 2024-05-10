#include "main.h"

int run_executable(char **command)
{
    pid_t pid;
    int exit_status;

    pid = fork();
    if (pid == -1)
    {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    if (pid == 0)
    {
        if (execve(command[0], command, environ) == -1)
        {
            perror("Execution failed");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(pid, &exit_status, 0);
        return WEXITSTATUS(exit_status);
    }
    return EXIT_SUCCESS;
}

