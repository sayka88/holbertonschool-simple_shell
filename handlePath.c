#include <stdlib.h>
#include <string.h>

char *handle_path(char *command) {
    char *path = getenv("PATH");
    char *token = strtok(path, ":");

    while (token != NULL) {
        char *full_path = malloc(strlen(token) + strlen(command) + 2);
        if (full_path == NULL) {
            perror("malloc");
            return NULL;
        }
        sprintf(full_path, "%s/%s", token, command);
        if (access(full_path, X_OK) == 0) {
            return full_path;
        }
        free(full_path);
        token = strtok(NULL, ":");
    }

    return NULL;
}

