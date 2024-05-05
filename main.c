#include "main.h"

/**
 * main - Creates an interactive loop in which the
 *        user can enter commands and receive responses
 *        from the program.
 * Return: Always 0.
 */
int main(void)
{
    ssize_t read;
    char *input = NULL;
    size_t len = 0;
    size_t i;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            printf("#cisfun$ ");

        read = getline(&input, &len, stdin);
        if (read == -1)
        {
            free(input);
            exit(0);
        }

        input[read - 1] = '\0';

        printf("Received %lu arguments:\n", (unsigned long)read);

        for (i = 0; i < (size_t)read; i++)
        {
            printf("Argument %lu: %c\n", (unsigned long)i, input[i]);
        }

        if (strcmp(input, "exit") == 0)
        {
            free(input);
            exit(0);
        }
        else if (strcmp(input, "env") == 0)
            printEnvironment();
        else
            executeCommand(input);
    }
    free(input);
    return (0);
}
