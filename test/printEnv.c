#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
 * printEnvironment - Prints the system environment variables.
 */
void printEnvironment(void)
{
    extern char **environ;
    char **env = environ;

    while (*env != NULL)
    {
        printf("%s\n", *env);
        env++;
    }
}
