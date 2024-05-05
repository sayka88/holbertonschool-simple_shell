#include "head.h"

int read_command(char *buffer)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    read = getline(&line, &len, stdin);

    if (read == -1)
    {
        free(line);
        return (0);
    }

    if (line[read - 1] == '\n')
    {
        line[read - 1] = '\0';
    }

    strcpy(buffer, line);
    free(line);
    return (1);
}

