#ifndef MAIN_H
#define MATH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *read_command(void);
void parse_arguments(char *command, char **args);
int execute(char *command);
extern char **environ;
void search_and_execute(char *args[], char *command);
int main(void);

#endif
