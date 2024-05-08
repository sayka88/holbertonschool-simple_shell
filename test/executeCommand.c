#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

/**
 * executeCommand - Executes a command in the shell.
 * @command: The command to execute.
 *
 * Return: 0 on success, 1 on failure.
 */
int executeCommand(char *command) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        char *argv[4];
        argv[0] = "/bin/sh";
        argv[1] = "-c";
        argv[2] = command;
        argv[3] = NULL;
        execve(argv[0], argv, NULL);
        perror("execve");
        _exit(127);
    } else {
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid");
            return 1;
        }
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return 1;
        }
    }
}

