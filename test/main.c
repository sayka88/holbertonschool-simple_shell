#include "main.h"

/**
 * removeNewline - Removes the newline character from the input string.
 * @str: The input string.
 */
void removeNewline(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '\n')
        {
            str[i] = '\0';
            break;
        }
    }
}

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
        else
            executeCommand(input);
    }
    free(input);
    return (0);
}

