#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

extern char **environ;

void execute_command(char *command);
void loop_shell(void);
int read_command(char *buffer);
void process_input(char *input);
void read_input(int fd, char *buffer);
void int_mode(void);
void non_int_mode(FILE *stream);

#endif
