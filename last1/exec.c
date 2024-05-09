
#include "main.h"

void exec(char **args, char *input)
{
    int status;
    pid_t childPid = 0;
    int pipefd[2];
    int saved_stdout;

    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    saved_stdout = dup(STDOUT_FILENO);

    if (access(args[0], X_OK) != 0)
        _err(args);

    childPid = fork();

    if (childPid == -1)
    {
        perror("fork\n");
        free(input);
        free(args[0]);
        exit(EXIT_FAILURE);
    }
    else if (childPid == 0)
    {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        execve(args[0], args, environ);
        perror(args[0]);
        free(args[0]);
        exit(EXIT_FAILURE);
    }
    else
    {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);

        waitpid(childPid, &status, WUNTRACED);

        dup2(saved_stdout, STDOUT_FILENO);

        if (WIFEXITED(status))
        {
            free(args[0]);
            free(input);
            exit(WEXITSTATUS(status));
        }
    }
}

