#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

extern char **environ;

int executeCommand(char *command);
void printEnvironment(void);
void removeNewline(char *str);
char *findExecutable(char *command, char *fullPath);

#endif /* MAIN_H */

