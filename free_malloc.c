#include "main.h"

/**
 * free_malloc- frees all dynamic space alocation
 * @token: pointer in token
 * @line: pointer of line sort of getline
 * @fullpath: point full path of command
 * @fp_malloc: flag to view if full_path is malloc
 *
 */

void free_malloc(char **token, char *line,
		char *fullpath, int fp_malloc)
{
	if (token != NULL)
		free(token);
	free(line);
	if (fp_malloc == 1)
		free(fullpath);
}
