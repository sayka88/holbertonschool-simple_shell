#include "shell.h"

void execute_command(char *line)
{
    pid_t pid;
    char *argv[2];
    char *command_path;

    argv[0] = line;
    argv[1] = NULL;

    if (line[0] == '/')
    {
        command_path = strdup(line);
    }
    else
    {
        command_path = _which(argv[0]);
    }

    if (command_path == NULL)
    {
        perror("Command not found");
        return;
    }

    if ((pid = fork()) == -1)
        perror("Error:");
    else if (pid == 0)
    {
        if (execve(command_path, argv, NULL) == -1)
            perror(argv[0]);
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(NULL);
        free(command_path);
    }
}

