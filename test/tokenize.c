#include "main.h"

/**
 * tokenize - function that splits a string into multiple ones
 * @input: users input
 * @args: arguments
 * Return: void
 */
void tokenize(char *input, char *args[])
{
	char *token;
	char *resolved_path;
	unsigned int i = 0;

	token = strtok(input, " ");
	resolved_path = handle_path(args[0]);
	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	if (args[0] == NULL)
		exit(0);

	if (strcmp(args[0], "env") == 0)
	{
		printEnv();
		return;
	}

	if (strcmp(args[0], "exit") == 0 && args[1] == NULL)
	{
		free(args[0]);
		exit(0);
	}

	if (resolved_path != NULL)
	{
		free(args[0]);
		args[0] = resolved_path;
		exec(args, input);
		return;
	}

	fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
	exit(127);
}

