#include "main.h"

/**
* executeCommand - Executes a command on a Unix or Linux system.
* @command: The input string.
*/
void executeCommand(char *command)
{
	char **args = tokenize(command);
	pid_t child_pid;
	int status;

	if (!args)
	{
		free(command);
		return;
	}

	if (strcmp(args[0], "exit") == 0)
	{
		free(command);
		free(args);
		exit(EXIT_SUCCESS);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error when creating a child process");
		free(command);
		free(args);
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}

	free(command);
	free(args);
}
