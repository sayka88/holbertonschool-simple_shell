#include "shell.h"

/**
 * _which - Searches for an executable in the PATH.
 * @cmd: The command to search for.
 *
 * Return: The full path to the executable, or NULL if not found.
 */
char *_which(char *cmd)
{
    char *path = getenv("PATH");
    char *path_dup = strdup(path);
    char *token = strtok(path_dup, ":");
    struct stat st;
    char *full_path;

    while (token != NULL)
    {
        full_path = malloc(strlen(token) + strlen(cmd) + 2);
        strcpy(full_path, token);
        strcat(full_path, "/");
        strcat(full_path, cmd);

        if (stat(full_path, &st) == 0)
        {
            free(path_dup);
            return full_path;
        }

        free(full_path);
        token = strtok(NULL, ":");
    }

    free(path_dup);
    return (NULL);
}
