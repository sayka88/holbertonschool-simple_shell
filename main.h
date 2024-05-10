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

extern char **path_variables;
extern char **environment_variables;

char **custom_strtok(char *str, char delim);
int execute_command(char **command_array);
char *find_file_location(char *file_name, int *lookup);
int count_arguments(char *input_buffer, int size);
char **fetch_command(char **input_buffer);

char **parse_command(char **input_buffer);
void search_path(char **env_vars, int *row_index, int *column_index);
char **initialize_path(char **environment_variables);
void release_path_memory(void);
void print_environment(void);
void print_prompt(int status);
int shell_main_helper(char **command_array, int status, char *input_buffer);
int start_shell(int argc, char **argv, char **environment);

#endif
