#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>

extern char **environ;

void executeCommand(char *command);
void printEnvironment(void);
char *findExecutable(char *command, char *fullPath);
char **tokenize(char *str);
void removeNewline(char *str);
void runCommand(char **args);

#endif
