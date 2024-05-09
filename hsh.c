#include "main.h"

/**
 * split_string- split getline in array of word
 * @line: string to split
 * @array: array to stock word
 * @nbrchar_read: nbr char read by function getline
 * Return: array of word to split getline
 **/

char **split_string(char *line, char **array, int nbrchar_read)
{
	char *delim = " \n\t\r", *token = NULL;
	int i = 0;

	if (line == NULL || nbrchar_read < 0)
	{
		free(line);
		exit(0);
	}

	token = strtok(line, delim);

	if (token == NULL)
		return (0);

	/* +2 because add also NULL */
	array = malloc(sizeof(char *) * (strlen(token) + 2));
	if (array == NULL)
	{
		free(line);
		line = NULL;
		exit(0);
	}

	for (i = 0; token != NULL; i++)
	{
		array[i] = token;
		token = strtok(NULL, delim);
	}
	array[i] = NULL;
	token = NULL;

	return (array);
}

/**
 * execve_cmd- execute function associated
 * @array: string split
 *
 * Return: 0
 */
int execve_cmd(char **array)
{
	char *cmd = NULL;
	int status, execve_status;
	pid_t child_pid;

	if (array[0] == NULL)
		exit(0);

	if (array)
		cmd = array[0];

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("error");
		return (1);
	}
	else if (child_pid == 0)
	{
		execve_status = execve(cmd, array, environ);
		if (execve_status == -1)
			return (-1);
	}
	else
		wait(&status);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else
		return (status);
}

/**
 * _which- search directory in PATH
 * @cmd: command search
 * @fullpath: full path of command it searched
 * @path_var: PATH variable
 * Return: pointer to path of the command searched
 */

char *_which(char *cmd, char *fullpath, char *path_var)
{
	unsigned int cmd_len, path_var_len, path_len;
	char *path_var_copy, *token;
	struct stat buffer;

	if (stat(cmd, &buffer) == 0) /* test if cmd is a file path */
	{
		fullpath = cmd;
		return (fullpath);
	}
	cmd_len = strlen(cmd);			 /* length of command */
	path_var_len = strlen(path_var); /* length of path variable */
	/* memory allocation for copy */
	path_var_copy = malloc(sizeof(char) * path_var_len + 1);
	if (path_var_copy == NULL) /* test allocation */
		return (NULL);
	strcpy(path_var_copy, path_var);	/* copy Path var */
	token = strtok(path_var_copy, ":"); /* split Path var */
	if (token == NULL)
		token = strtok(NULL, ":");
	while (token != NULL)
	{
		path_len = strlen(token);
		fullpath = malloc(sizeof(char) * (path_len + cmd_len) + 2);
		if (fullpath == NULL)
			return (NULL);
		strcpy(fullpath, token);
		fullpath[path_len] = '/';
		strcpy(fullpath + path_len + 1, cmd);
		fullpath[path_len + cmd_len + 1] = '\0';
		/* check access to file and right of execution */
		if (access(fullpath, X_OK) != 0) /* if not executable */
		{	free(fullpath);
			fullpath = NULL;
			token = strtok(NULL, ":");
		}
		else /*end of while loop */
			break;
	}
	free(path_var_copy); /* free the copy */
	return (fullpath);	 /* return full path of cmd search*/
}

/**
 * loop_getline- loop function getline
 * Return: 0
 */

int loop_getline(void)
{
	char *array[1024], *line = NULL, *fullpath = NULL, *path = NULL, **cmd = NULL;
	size_t len = 0;
	ssize_t nbrchar_read;
	int i = 0, flag_malloc = 0;

	while (1) /* loop for shell prompt */
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2); /* print $ in the beginning of line */
		nbrchar_read = getline(&line, &len, stdin);
		if (nbrchar_read == -1)
		{	free(line), line = NULL;
			return (-1);
		}
		if (feof(stdin) || strncmp(line, "exit", 4) == 0)
			free(line), line = NULL, exit(0);
		if (strcmp(line, "\n") != 0) /* test if line = \n */
		{	cmd = split_string(line, array, nbrchar_read);
			if (cmd == NULL)
				free(line), exit(0);
			path = _getenv("PATH");
			if (environ && strcmp(*cmd, "env") == 0)
				print_full_env(environ);
			else if (path == NULL && access(cmd[0], X_OK) != 0)
				dprintf(STDERR_FILENO, "./hsh: 1: %s: not found\n", cmd[0]);
			else
			{	
				if (cmd[0][0] != '/' && strncmp(cmd[0], "./", 2) != 0)
				{	fullpath = _which(cmd[0], fullpath, path);
					if (fullpath == NULL)
						fullpath = cmd[0];
					else
						flag_malloc = 1, cmd[0] = fullpath;
				}
				i = execve_cmd(cmd);
				if (i != 0) /* si le programme enfant s'est mal fini*/
					free_malloc(cmd, line, fullpath, flag_malloc), exit(i);
			}
		}
		nbrchar_read = 0, free_malloc(cmd, line, fullpath, flag_malloc);
		line = NULL, path = NULL, fullpath = NULL, flag_malloc = 0;
	}
	return (0);
}

/**
 * main- loop shell prompt
 * @argc: count arg
 * @argv: arguments
 * Return:0
 */

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	loop_getline();

	return (0);
}
