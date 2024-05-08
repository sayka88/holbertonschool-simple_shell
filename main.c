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
    int i;

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
        removeNewline(input);
        for (i = 0; input[i] != '\0'; i++)
        {
            if (input[i] != ' ')
                break;
        }
        if (input[i] == '\0')
            continue;
        if (strcmp(input, "exit") == 0)
        {
            free(input);
            exit(0);
        }
        else if (strcmp(input, "env") == 0)
            printEnvironment();
        else {
            int status = executeCommand(input);
            exit(status);
        }
    }
    free(input);
    return (0);
}
