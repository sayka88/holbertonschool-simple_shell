#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define PROMPT "$ "
#define DELIM " \t\n"
#define MAX_ARGS 64

void print_error(char *message);
char **tokenize_line(char *line);
void free_args(char **args);
int execute_command(char **args);

#endif /* MAIN_H */

