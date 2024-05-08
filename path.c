#include "main.h"

/**
 * findExecutable - Find Executable path
 *
 * @command: line of command
 * @fullPath: path
 *
 * Return: bool.
 */

char *findExecutable(char *command, char *fullPath)
{
    char *path = getenv("PATH");
    char *token = strtok(path, ":");

    while (token != NULL)
    {
        snprintf(fullPath, 255, "%s/%s", token, command);
        if (access(fullPath, X_OK) == 0)
        {
            return fullPath;
        }
        token = strtok(NULL, ":");
    }
    return NULL;
}

