#include "main.h"
void exec(char **args, char *input)
{
	pid_t childPid;
	int status;

	childPid = fork();

	if (childPid == -1)
	{
		perror("fork");
		free(input);
		exit(EXIT_FAILURE);
	} else if (childPid == 0) {
		if (execvp(args[0], args) == -1)
		{
			perror(args[0]);
			free(input);
			exit(EXIT_FAILURE);
		}
	} else {

		if (waitpid(childPid, &status, 0) == -1)
		{
			perror("waitpid");
			free(input);
			exit(EXIT_FAILURE);
		}
		
		if (WIFEXITED(status))
		{
			free(input);
			exit(WEXITSTATUS(status));
		} else {
			free(input);
			exit(EXIT_FAILURE);
		}
	}
}

