#include "main.h"

/**
 * _getenv - get the environment
 * @name: name used as argument
 *
 * Return: ptr or NULL value
 */

char *_getenv(char *name)
{
	char **env;
	char *ptr, *namecopy;

	for (env = environ; *env != NULL; env++)
	{
		for (ptr = *env, namecopy = name; *ptr == *namecopy; ptr++, namecopy++)
		{
			if (*ptr == '=')
				break;
		}
		if ((*ptr == '=') && (*namecopy == '\0'))
			return (ptr + 1);
	}
	return (NULL);
}
