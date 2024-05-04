#include "shell.h"

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int is_interactive = isatty(STDIN_FILENO);

    while (is_interactive ? printf("$ ") : 0, (read = getline(&line, &len, stdin)) != -1)
    {
        if (read > 1 && line[read - 1] == '\n')
            line[read - 1] = '\0';
        execute_command(line);
    }

    if (feof(stdin))
        printf("\n");
    free(line);
    exit(EXIT_SUCCESS);
}

