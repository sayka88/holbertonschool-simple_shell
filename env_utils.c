#include "shell.h"

/**
 * display all the variables in the environment system
 */

int _printenv(void)
{
	char *str = environ[0];
	int i = 0, file_descr = 1;
	
	while (str[i] != '\0')
	{
		write(file_descr, str, _strlen(str));
		write(file_descr, "\n", 1);
		str = environ[i]; /*++i without next line */
		++i;
	}
	return (0);
}

char *_getenv(char *name)
{
	int i = 0;
	int len_name = _strlen(name);

	for (i = 0; environ[i] != NULL; i++)
		if (_str_n_cmp(environ[i], name, _strlen(name)) == 0)
			return (&environ[i][len_name]);
     
	return (NULL);
}
