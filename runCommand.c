#include "main.h"

/**
* path_var - Array of pointers to strings representing PATH variables.
*
* This global variable stores an array of pointers to strings, each string
* representing a directory specified in the PATH environment variable. It is
* used to search for executable files in the specified directories.
*/

char **path_var;

/**
* find_file - Find the location of a file in the PATH variables.
*
* This function searches for the location of a file specified by the user
* input in the directories specified by the PATH environment variable.
*
* @command: User input specifying the file
* @lk: Flag indicating whether this command uses PATH or not
*
* Return: Modified user input with the full path to the file
*/

char *find_file(char *command, int *lk)
{
int i = 0, max_len = 0, j;
char *temp, *result = NULL;
struct stat st;

if (command[0] == '/' || command[0] == '.')
{
if (!stat(command, &st))
{
result = strdup(command);
if (result != NULL)
	(*lk)++;
}
return (result);
}
if (!path_var)
return (NULL);
for (j = 0; path_var[j] != NULL; j++)
max_len += strlen(path_var[j]) + strlen(command) + 2;
temp = malloc(max_len);
if (temp == NULL)
return (NULL);
while (path_var[i])
{
strcpy(temp, path_var[i]);
strcat(temp, "/");
strcat(temp, command);
if (!stat(temp, &st))
{
(*lk)++;
errno = 0;
result = strdup(temp);
break;
}
i++;
}
free(temp);
return (result);
}


