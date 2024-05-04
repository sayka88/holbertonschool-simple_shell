#include "shell.h"

char *command_path(char *cmd)
{
        int i;
	char *path = _strdup(_getenv("PATH"));
	char *tokens = strtok(path, ":");
	char *path_array[100]; /* array of 100 elements */ 
	char *new_path = NULL;
	struct stat buf;

	/**
	 * printf("Original Path\n");
	 * printf("%s\n", path);
	 * printf("---------------------------\n");
	 *
	 * printf("Tokens: %s\n", tokens);
	 * printf("---------------------------\n");
	 */
	
	new_path = malloc(sizeof(char) * 100);
	if (_getenv("PATH")[0] == ':') 
	  if (stat(cmd, &buf) == 0)   /* in case of success */
	    return (_strdup(cmd));    /* return a copy of command */
	
	/**
	 *  
	 * continue to split the path in a set of tokens
	 * store results in path_array
	 *
	 */
	i = 0;
	while (tokens != NULL)
	{
		path_array[i] = tokens;
		i++;
		tokens = strtok(NULL, ":");
	}
	path_array[i] = NULL;

	/**  
	 * printf("Path Array\n");
	 * for (i=0; path_array[i] != NULL; i++)
	 * printf("%s\n", path_array[i]);
	 * printf("---------------------------\n");
	 */
	
	/**
	 * copy tokens to new path
	 * add "/" and command 
	 * Example: after loop command will be /bin/ls
	 */ 
	for (i = 0; path_array[i]; i++)
	{
		_strcpy(new_path, path_array[i]);
		_strcat(new_path, "/");
		_strcat(new_path, cmd);
		_strcat(new_path, "\0");

		/* printf("NewPath--> %s\n", new_path); */ 
		/* in case of sucess free resources and return new_path */
		if (stat(new_path, &buf) == 0)
		{
			free(path);
			return (new_path);
		}
		else 
			new_path[0] = 0;
	}
	free(path);
	free(new_path);
	
	/* After PATH checked and cmd is there locally */
	if (stat(cmd, &buf) == 0)
		return (_strdup(cmd));

	/* in case of possible errors */ 
	return (NULL);
}
