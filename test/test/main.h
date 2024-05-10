#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

extern char **path_var;
extern char **environ;

int main(int argc, char **argv, char **env)
char **get_user_command(char **buf);
char **get_path_directories(char **env);
char *find_executable_path(char *command, int *found);
void display_environment(void);
void print_shell_prompt(int status);
void release_path_memory(void);
int execute_command(char **command);

#endif

