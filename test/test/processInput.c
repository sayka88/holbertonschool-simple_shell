#include <errno.h>
#include "main.h"

void print_shell_prompt(int status)
{
    if (status)
        printf("#cisfun$ ");
    else
        errno = 0;
}

