#include "main.h"

int main(int argc, char **argv, char **env)
{
    char **command, *buf, *executable_path;
    int status, found = 0, exit_code = 0;

    path_var = get_path_directories(env);

    while (1)
    {
        status = isatty(STDIN_FILENO);
        print_shell_prompt(status);

        command = get_user_command(&buf);

        if (main_helper(command, status, buf))
            break;

        if (!strcmp(command[0], " "))
        {
            free(buf);
            free(command[0]);
            free(command);
            continue;
        }

        executable_path = find_executable_path(command[0], &found);
        if (!executable_path)
        {
            fprintf(stderr, "%s: 1: %s: not found\n", argv[0], command[0]);
            free(buf);
            free(command);
            errno = 0;
            if (!status)
                release_path_memory(), exit(127);
            continue;
        }

        exit_code = execute_command(command);
        if (found)
            free(executable_path), found = 0;
        free(buf);
        free(command);
    }

    return exit_code;
}

