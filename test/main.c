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

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		read = getline(&input, &len, stdin);
		if (read == -1)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		removeNewline(input);
		if (strcmp(input, "exit") == 0)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		else if (strcmp(input, "env") == 0)
			printEnvironment();
		else
			executeCommand(input);
	}
	free(input);
	return (0);
}
