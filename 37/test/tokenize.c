#include "main.h"

/**
 * tokenize - function that splits a string into multiple ones
 * @input: users input
 * @args: arguments
 * Return: void
 */

void tokenize(char *input, char *args[])
{
    char *token;
    char *executable;
    unsigned int i = 0;

    token = strtok(input, " ");
    while (token != NULL)
    {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    if (args[0][0] == '/')
    {
        args[0] = strdup(args[0]);
        return;
    }

    executable = handle_path(args[0]);
    if (executable != NULL)
    {
        args[0] = executable;
    }
    else
    {
        fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
        exit(127);
    }
}

