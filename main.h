#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

/* environment variable */
extern char **environ;


/* Function free all malloc */
void free_malloc(char **token, char *line, char *fullpath, int fp_malloc);
/* function like which */
char *_which(char *cmd, char *fullpath, char *path_var);
/* function like getenv */
char *_getenv(char *name);
/* liste all directory path */
char *_directory_path(char *path);
/* construct NAME=VALUE for environment variable */
char *build_var_env(const char *name, const char *value);
/* implicit declaration of getline so i define it*/
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
/* function print env */
void print_full_env(char **envp);

#endif
