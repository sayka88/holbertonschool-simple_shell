#include "main.h"

/**
 * print_full_env- function that print all environment variable
 * @envp: environment
 */

void print_full_env(char **envp)
{
	int i = 0;

	for (i = 0; envp[i] != NULL; i++)
		printf("%s\n", envp[i]);
}
