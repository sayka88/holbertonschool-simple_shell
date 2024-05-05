#include "head.h"

void process_input(char *input)
{
    if (input && input[0])
    {
        char *args[2];
        args[0] = input;
        args[1] = NULL;

        if (execvp(input, args) == -1)
        {
            perror("Error executing command");
        }
    }
}

void execute_command(char *command)
{
    pid_t pid;
    int status;
    char *argv[2];

    argv[0] = command;
    argv[1] = NULL;

    pid = fork();

    if (pid == 0)
    {
        if (execvp(command, argv) == -1)
        {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    }
    else if (pid < 0)
    {
        perror("fork");
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}

