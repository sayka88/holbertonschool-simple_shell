#ifndef EXECUTE_COMMAND_H
#define EXECUTE_COMMAND_H

#include "main.h"

/**
* execute_command - Executes the command entered by the user.
* @command_array: An array containing the command and its arguments.
*
* This function executes the command specified
* by the user along with its arguments
*
* Return: The exit status of the executed command.
*/

int execute_command(char **command_array)
{
	pid_t pid;
	int return_code;

	pid = fork();
	if (pid == 0)
	{
		execve(command_array[0], command_array, environment_variables);
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&return_code);
		return (WEXITSTATUS(return_code));
	}
}
#endif
