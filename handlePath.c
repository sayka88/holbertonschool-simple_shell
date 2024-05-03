#include "main.h"

/**
 * handle_path - Finds the path of the command to execute
 * @input: User input
 * Return: The full path of the command if found, NULL otherwise
 */
char *handle_path(char *input)
{
	char *token, *path_copy, *full_path;
	char *input_copy = NULL;

	if (strchr(input, '/') != NULL)
	{
		input_copy = strdup(input);
		return input_copy;
	}

	path_copy = strdup(getenv("PATH"));
	if (path_copy == NULL)
	{
		perror("Error getting PATH");
		free(input_copy);
		return NULL;
	}

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(input) + 2);
		if (full_path == NULL)
		{
			perror("Malloc failed");
			free(path_copy);
			free(input_copy);
			return NULL;
		}

		sprintf(full_path, "%s/%s", token, input);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			free(input_copy);
			return full_path;
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	free(input_copy);
	return NULL;
}

