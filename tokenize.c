#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* tokenize - Tokenizes a string into an array of strings.
* @str: The string to tokenize.
*
* Return: An array of strings (tokens).
*/
char **tokenize(char *str)
{
	char **tokens = malloc(sizeof(char *) * 64);
	char *token = strtok(str, " \t\n");
	int i = 0;

	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, " \t\n");
	}

	tokens[i] = NULL;

	return (tokens);
}
