#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>

extern char **environ;

char *findExecutable(char *command, char *fullPath)
{
    char *path = getenv("PATH");
    char *token = strtok(path, ":");

    while (token != NULL)
    {
        char tempPath[PATH_MAX];
        snprintf(tempPath, PATH_MAX, "%s/%s", token, command);
        if (access(tempPath, X_OK) == 0)
        {
            strncpy(fullPath, tempPath, PATH_MAX);
            return fullPath;
        }
        token = strtok(NULL, ":");
    }
    return NULL;
}
