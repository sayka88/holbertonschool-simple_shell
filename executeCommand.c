#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * executeCommand - Executes a command on a Unix or Linux system.
 * @command: The input string.
 */
void executeCommand(char *command)
{
    char *token;
    char *args[20];
    int argIndex = 0;
    char fullPath[20];

    pid_t pid;
    args[0] = NULL;
    for (token = strtok(command, " "); token != NULL;
            token = strtok(NULL, " "))
    {
        args[argIndex] = token;
        argIndex++;
    }
    args[argIndex] = NULL;

    if (args[0] == NULL)
    {
        printf("Command is not specified\n");
        return;
    }

    if (strcmp(args[0], "exit") == 0)
    {
        printf("Exiting shell...\n");
        exit(EXIT_SUCCESS);
    }

    pid = fork();
    if (pid == -1)
    {
        perror("Error when creating a child process");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        if (args[0] && !strchr(args[0], '/'))
        {
            if (findExecutable(args[0], fullPath))
                args[0] = fullPath;
        }
        if (execve(args[0], args, environ) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
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
                printf("Command failed with status %d\n", exit_status);
        }
        else
        {
            printf("Command terminated abnormally\n");
        }
    }
}

