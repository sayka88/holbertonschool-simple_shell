#ifndef MAIN_H
#define MATH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
<<<<<<< HEAD
#include <stdbool.h>

extern char **environ;

void executeCommand(char *command);
void printEnvironment(void);
bool findExecutable(char *command, char *fullPath);


=======
#include <fcntl.h>
#include <sys/types.h>
char *_getline(void);
void line_div(char *command, char *arr[]);
int execute(char *command);
extern char **environ;
int main(void);
>>>>>>> refs/remotes/origin/main
#endif
