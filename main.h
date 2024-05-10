#ifndef MAINH
#define MAINH
#define PATH "PATH="
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

extern char **path_list;
extern char **environ;
char **fetch_command(char **);
char **initialize_path(char **);
char *search_file(char *file_name, int *);
void print_environment(void);
void print_prompt(int status);
void release_path_memory(void);
int execute_command(char **command_array);
char **custom_strtok(char *str, char delim);

#endif
