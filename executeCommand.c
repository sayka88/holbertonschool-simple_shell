#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>

extern char **environ;

/**
 * executeCommand - Executes a command on a Unix or Linux system.
 * @command: The input string.
 */
int executeCommand(char *command)
{
char *executablePath;
    char *token;
    char *args[20];
    int argIndex = 0;
    char fullPath[PATH_MAX];

    pid_t pid;
    args[0] = NULL;
    for (token = strtok(command, " \n"); token != NULL;
         token = strtok(NULL, " \n"))
    {
        args[argIndex] = token;
        argIndex++;
    }
    args[argIndex] = NULL;

    if (args[0] == NULL)
    {
        fprintf(stderr, "Command is not specified\n");
        return 127;
    }

    if (strcmp(args[0], "exit") == 0)
    {
        printf("Exiting shell...\n");
        exit(EXIT_SUCCESS);
    }

    char *executablePath = findExecutable(args[0], fullPath);
    if (!executablePath)
    {
        fprintf(stderr, "%s: command not found\n", args[0]);
        return 127;
    }

    pid = fork();
    if (pid == -1)
    {
        perror("Error when creating a child process");
        return 1;
    }
    else if (pid == 0)
    {
        if (execve(executablePath, args, environ) == -1)
        {
            fprintf(stderr, "%s: command not found\n", args[0]);
            exit(127);
        }
    }
    else
    {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
        {
            int exit_status = WEXITSTATUS(status);
            if (exit_status != 0)
            {
                fprintf(stderr, "Command failed with status %d\n", exit_status);
                return exit_status;
            }
        }
        else if (WIFSIGNALED(status))
        {
            fprintf(stderr, "Command terminated by signal %d\n", WTERMSIG(status));
            return EXIT_FAILURE;
        }
    }
    return 0;
}

