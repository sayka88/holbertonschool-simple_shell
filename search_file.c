#ifndef SEARCH_FILE_H
#define SEARCH_FILE_H

#include "main.h"

/**
* find_file_location - Finds the location of a file in the path variables.
*
* @file_name: The name of the file to search for.
* @lookup: Flag indicating whether this command uses path or not.
*
* Return: Modified user input.
*/
char *find_file_location(char *file_name, int *lookup)
{
	struct stat st;
	char **path_variables = NULL;
	char *temp;
	int max_len = 0;
	int i, j;

	if (file_name[0] == '/' || file_name[0] == '.')
	{
		if (!stat(file_name, &st))
		{
			(*lookup)++;
			return (strdup(file_name));
		}
		return (NULL);
	}

	if (!path_variables)
		return (NULL);

	for (j = 0; path_variables[j] != NULL; j++)
		max_len += strlen(path_variables[j]) + strlen(file_name) + 2;

	temp = malloc(max_len);

	if (temp == NULL)
		return (NULL);

	for (i = 0; path_variables[i] != NULL; i++)
	{
		strcpy(temp, path_variables[i]);
		strcat(temp, "/");
		strcat(temp, file_name);

		if (!stat(temp, &st))
		{
			(*lookup)++;
			errno = 0;
			return (strdup(temp));
		}
	}

	free(temp);
	return (NULL);
}
#endif

