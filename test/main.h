#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>


void removeNewline(char *str);
void printEnvironment(void);
int executeCommand(char *command);

#endif
