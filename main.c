#include "main.h"

void removeNewline(char *str) {
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }
}

int main(void) {
    ssize_t read;
    char *input = NULL;
    size_t len = 0;
    int i;
    int status;

    while (1) {
        if (isatty(STDIN_FILENO))
            printf("#cisfun$ ");
        read = getline(&input, &len, stdin);
        if (read == -1) {
            free(input);
            exit(0);
        }
        removeNewline(input);
        for (i = 0; input[i] != '\0'; i++) {
            if (input[i] != ' ')
                break;
        }
        if (input[i] == '\0')
            continue;
        if (strcmp(input, "exit") == 0) {
            free(input);
            wait(&status);
            exit(status);
        } else if (strcmp(input, "env") == 0)
            printEnvironment();
        else
            executeCommand(input);
    }
    free(input);
    return (0);
}

