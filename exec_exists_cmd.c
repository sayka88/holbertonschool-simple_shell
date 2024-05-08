#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void _err(char *args[])
{
    fprintf(stderr, "%s: command not found\n", args[0]);
    perror("");
    free(args[0]);
    exit(98);
}

void exec(char **args, char *input)
{
    int status;
    pid_t childPid = 0;

    struct stat st;
    if (stat(args[0], &st) == -1) {
        _err(args);
    }

    if (!S_ISREG(st.st_mode) || (st.st_mode & S_IXUSR) == 0) {
        _err(args);
    }

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
        execve(args[0], args, environ);
        perror(args[0]);
        free(args[0]);
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(&status);
        if (WIFEXITED(status))
        {
            free(args[0]);
            free(input);
            exit(WEXITSTATUS(status));
        }
    }
}

