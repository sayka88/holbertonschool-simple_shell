#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

void tokenize(char *input, char *args[]);
void printEnv(void);
char *handle_path(char *input);
void exec(char **args, char *input);
void _err(char *args[]);
int spacesCheck(const char *str);
void tokenize(char *input, char *args[]);

#endif /* MAIN_H */

