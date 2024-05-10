#ifndef FETCH_COMMAND_H
#define FETCH_COMMAND_H

#include "main.h"
/**
 * count_arguments - Counts the number of arguments in the input buffer.
 * @input_buffer: The user input buffer.
 * @size: The size of the user input buffer.
 *
 * This function counts the number of arguments in the user input buffer.
 *
 * Return: The number of arguments.
 */

int count_arguments(char *input_buffer, int size)
{
	int count = 0, i;

	for (i = 1; i < size; i++)
		count += ((input_buffer[i - 1] == ' ' &&
					(input_buffer[i] != ' ' && input_buffer[i] != '\n')) ||
				(i == 1 &&
				 input_buffer[i - 1] != ' '));
	return (count);
}

 /**
 * fetch_user_command - Formats the command line arguments.
 * @input_buffer: Buffer for storing the user input.
 *
 * This function formats the command line arguments entered by the user.
 *
 * Return: The memory address where the arguments are stored.
 */
char **fetch_command(char **input_buffer)
{
	char **array;
	size_t buffer_size = 1, k, i, l = 0, count;

	*input_buffer = malloc(buffer_size), k = getline(input_buffer, &buffer_size, stdin);
	if (k == (size_t)(-1))
	{
		if (errno == 0)
			return (NULL);
		perror("Failure to read line");
		return (NULL);
	}
	count = count_arguments(*input_buffer, k);
	if (!count)
	{
		array = malloc(sizeof(char *));
		array[0] = strdup(" ");
		return (array);
	}
	array = malloc(sizeof(char *) * (count + 1));
	if (array == NULL)
	{
		free(*input_buffer), free(array);
		return (NULL);
	}
	for (i = 1; i < k; i++)
	{
		if ((*input_buffer)[i - 1] == ' ' || (*input_buffer)[i - 1] == '\t' || (*input_buffer)[i - 1] == '\n')
			(*input_buffer)[i - 1] = '\0';
		else if ((*input_buffer)[i - 1] == '\0')
			continue;
		else
		{
			array[l] = *input_buffer + i - 1;
			while ((*input_buffer)[i] != ' ' && (*input_buffer)[i] != '\t' && (*input_buffer)[i] != '\n')
				i++;
			(*input_buffer)[i] = '\0', l++;
		}
	}
	array[l] = NULL;
	return (array);
}

#endif
