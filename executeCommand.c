#include "main.h"

/**
* exec_c - Executes user input.
*
* This function executes the user-provided command by forking a new process and
* executing the command using the execve system call.
*
* @fcommand: User input command and its arguments.
*
* Return: The return code of the executed command.
*/

int exec_c(char **fcommand)
{
pid_t pid;
int r_code;

pid = fork();
if (pid == 0)
	r_code = execve(fcommand[0], fcommand, environ);
else
{
	wait(&r_code);
	return (WEXITSTATUS(r_code));
}
return (r_code);
}
