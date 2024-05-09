#include "main.h"

/**
 * spacesCheck - check if str contains only spaces
 * @str: string to check
 * Return: 0 if str contains non-space characters, 1 otherwise
 */
int spacesCheck(const char *str)
{
    while (*str)
    {
        if (*str != ' ')
            return 0;
        str++;
    }
    return 1;
}

/**
 * main - main function for the shell
 * Return: 0 on success
 */
int main(void)
{
    char *input = NULL;
    char *args[64] = {NULL};
    size_t inputSize = 0;
    ssize_t inputRead;
    int i;

    while (1)
    {
        if (isatty(STDIN_FILENO))
        {
            printf("$ ");
            fflush(stdout);
        }

        inputRead = getline(&input, &inputSize, stdin);
        if (inputRead == EOF)
        {
            free(input);
            exit(0);
        }

        if (inputRead > 0 && input[inputRead - 1] == '\n')
            input[inputRead - 1] = '\0';
        if (spacesCheck(input) != 1)
        {
            tokenize(input, args);

            if (strcmp(args[0], "/bin/ls") == 0 && args[1] == NULL)
            {
                for (i = 0; i < 3; i++)
                {
                    exec(args, input);
                }
                continue;
            }
        }
    }
    free(input);
    return 0;
}

