#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* removeNewline - Removes the newline character from the input string.
* @str: The input string.
*/
void removeNewline(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break;
		}
	}
}
