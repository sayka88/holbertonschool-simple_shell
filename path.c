#include "main.h"

/**
* find_path - Find the PATH variable in environment variables.
*
* This function searches for the PATH variable in the environment variables
* array. It iterates through each row of the environment variables until it
* finds the PATH variable.
*
* @var: Pointer to the environment variables array
* @i: Pointer to the row index
* @j: Pointer to the column index
*/
void find_path(char **var, int *i, int *j)
{
	while (var[*i])
	{
		while (var[*i][*j])
		{
			if (var[*i][*j] == PATH[*j])
			{
				if (var[*i][*j] == '=')
					return;
				(*j)++;
			}
			else
				break;
		}
		(*i)++;
		*j = 0;
	}
	*i = 0;
	*j = 0;
}

/**
* get_path - Initialize the path array.
*
* This function initializes the path array by extracting the directories
* specified in the PATH variable from the environment variables array.
*
* @env: Pointer to the environment variables array
* Return: Path array containing directories specified in the PATH variable
*/

char **get_path(char **env)
{
	int i = 0, j = 0;
	char **array;

	find_path(env, &i, &j);
	if (i == 0 && j == 0)
	{
		return (NULL);
	}
	j++;
	array = _strtok(env[i] + j, ':');
	if (!array)
	{
		free(array);
		return (NULL);
	}
	return (array);
}

/**
* free_path - Free the path buffer.
*
* This function frees the memory allocated for the path buffer.
*/

void free_path(void)
{
	int i = 0;

	if (!path_var)
		return;
	while (path_var[i])
		free(path_var[i++]);
	free(path_var);
}
