#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * tokenize - tokenizes a string into an array of strings
 * @str: the string to tokenize
 *
 * Return: a pointer to an array of strings (tokens)
 */
char **tokenize(char *str)
{
    char **tokens = malloc(sizeof(char *) * 64);
    char *token;
    int i = 0;

    if (!tokens)
    {
        perror("malloc failed");
        return NULL;
    }

    token = strtok(str, " \t\n");

    while (token != NULL)
    {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " \t\n");
    }

    tokens[i] = NULL;

    return tokens;
}

