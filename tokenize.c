#ifndef TOKENIZE_H
#define TOKENIZE_H

#include "main.h"

/**
* custom_strtok - Custom implementation of strtok
* @str: The string to tokenize.
* @delim: The delimiter character.
*
* This function splits the input string into
*tokens based on the specified delimiter
*
* Return: An array of tokens.
*/

char **custom_strtok(char *str, char delim)
{
char **token_array, *start, *end;
int i = 0, token_count = 1, max_tokens = 10;

if (str == NULL)
	return (NULL);

token_array = malloc(sizeof(char *) * max_tokens);

if (token_array == NULL)
	return (NULL);

while (str[i])
{
	if (str[i] != delim)
	{
		start = str + i;
		while (str[i] != delim && str[i])
			i++;
		if (str[i] == '\0')
		{
			token_array[token_count - 1] = strdup(start);
			token_count++;
			break;
		}
		else
		{
			end = str + i;
			*end = '\0';
			token_array[token_count - 1] = strdup(start), *end = delim, start = end;
		}
		token_count++;
	}
	i++;
}

token_array[token_count - 1] = NULL;
return (token_array);
}



#endif
