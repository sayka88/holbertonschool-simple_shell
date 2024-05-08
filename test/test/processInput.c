#include "main.h"

/**
* processInput - Processes the input string.
* @input: The input string.
*/
void processInput(char *input)
{
	char **args = tokenize(input);

	if (args == NULL || args[0] == NULL)
	{
		free(input);
		free(args);
		return;
	}
	runCommand(args);
	free(args);
}
