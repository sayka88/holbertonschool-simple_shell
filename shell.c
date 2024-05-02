#include "main.h"

/**
 * main - main func
 *
 * Return: int
 */
int main(void)
{
	char *command;
	int status;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		command = _getline();
		if (command == NULL)
			break;
		if (strcmp(command, "exit") == 0)
		{
			free(command);
			exit(0);
		}

		if (access(command, X_OK) == -1)
		{
			printf("Command not found: %s\n", command);
			free(command);
			continue;
		}

		status = execute(command);
		if (status == 2)
		{
			exit(2);
		}
	}
	return (status);
}

