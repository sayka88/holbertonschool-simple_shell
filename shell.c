#include "shell.h"

/* global variable name */
char *name;

int main(int __attribute__ ((unused))argc, char *argv[])
{
	char *line = NULL;
	size_t buf_size = 0;
	ssize_t characters = 0;

	name = argv[0];

	while (1)
	{
	  /* check if an open file descriptor is associated with terminal device */
		if (isatty(STDIN_FILENO) == 1)
		  /* write to standard output */
			write(1, "$ ", 2);
		/* store number of characters read */
		characters = getline(&line, &buf_size, stdin);
		/* in case of failure, write new line if file is open */
		if (characters == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(1, "\n", 1);
			break;
		}

		/* when encountering new line, write null terminating byte */
		if (line[characters - 1]  == '\n')
			line[characters - 1]  = '\0';
		if (*line == '\0')
			continue;
		/* in case of exit */ 
		if (command_read(line, characters) == 2)
			break;
	}
	/* free resources */ 
	free(line);
	line = NULL;
	
	return (0);
}


int command_read(char *s, size_t __attribute__((unused))characters)
{
	char *token = NULL;
	char *cmd_arr[100];
	int i;

	if (_strcmp(s, "exit") == 0)
		return (2);
	if (_strcmp(s, "env") == 0)
		return (_printenv());
	token = strtok(s, " "), i = 0;
	while (token)
	{
		cmd_arr[i++] = token;
		token = strtok(NULL, " ");
	}
	cmd_arr[i] = NULL;
	/* Return status code */
	return (execute(cmd_arr));
}

int execute(char *cmd_arr[])
{
	char *exe_path = NULL;
	char *cmd = NULL;
	pid_t pid;
	int status;

	cmd = cmd_arr[0];
	exe_path = command_path(cmd);
	if (exe_path == NULL)
	{
	        write(2, name, _strlen(name));
		write (2, ": ", 2);
	        write(2, cmd, _strlen(cmd));
		write(2, ": not found\n", 12);

		return (3);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Error:");
		return (-1);
	}
	if (pid > 0)
		wait(&status);
	else if (pid == 0)
	{
	  if (environ)
	    {
		(execve(exe_path, cmd_arr, environ));
		perror("Error:");
		exit(1);
	    }
	  else
	    {
	      execve(exe_path, cmd_arr, NULL);
	    }
	}
	free(exe_path);
	return (0);
}
