#include "main.h"

/**
* execute - executes command
*
* @command: The command string to execute.
*
* Return: the exit status of the executed command,
* or -1 if an error occurs.
*/
int execute(char *command)
{
	int status = 0;
	pid_t pid;

	if (access(command, X_OK) == -1)
	{
		fprintf(stderr, "Function 'fork' is not allowed\n");
		return 1;
	}

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		free(command);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *arr[64];
		line_div(command, arr);

		execve(arr[0], arr, environ);

		perror("execve");
		free(command);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		free(command);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		else
			status = 1;
	}
	return status;
}

