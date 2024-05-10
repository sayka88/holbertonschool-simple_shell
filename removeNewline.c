#include "main.h"

/**
* print_prompt - Prints the shell prompt string.
*
* This function prints the shell prompt string, which typically includes the
* shell name and a delimiter, such as "#cisfun$ ", to indicate that the shell
* is ready to accept user input.
*
* @status: 1 if the file descriptor is an
*open file descriptor referring to a terminal
*/

void print_prompt(int status)
{
if (status)
	printf("#cisfun$ ");
else
	errno = 0;
}
